#include "menu_data_container.h"

#include <iostream>
#include <cstdlib>
#include <cctype>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/parser/parser.h"
#include "polish_notation/renderer/console_renderer/console_renderer.h"
#include "polish_notation/renderer/field_generator.h"
#include "polish_notation/shunting_yard_alg/shunting_yard_alg.h"
#include "polish_notation/token/token.h"
#include "polish_notation/exceptions/invalid_function/invalid_function.h"
#include "user_input.h"
#include "polish_notation/utility/utility.h"

namespace polish_notation::renderer::console::menu_data_container {
MenuDataContainer::MenuDataContainer() :
    funcStr_(),
    funcPostfixTokenQueue_(),
    fInfo_(),
    field_(),
    actionType_(ActionType::Select),
	editableOptions(),
    arrowPos_() {
	pn_ui::setFunctionStr(funcStr_);
	regenerateFunction();

	pn_ui::setFieldInfo(fInfo_);
	field_ = getGeneratedField(funcPostfixTokenQueue_, fInfo_);

	initEditableOptions();
	regenerateEditableOptions();

	pn_u_c_rm::setRawMode();
}

MenuDataContainer::~MenuDataContainer() {
	pn_u_c_rm::resetMode(pn_u_c_rm::original);
}

void MenuDataContainer::regenerateFunction() {
    std::string funcLineWithoutSpaces =
        pn::parser::getLineWithoutSpaces(funcStr_);

	pn_ds::queue::Queue<pn::token::Token> qTokens;
	if (!pn::parser::trySetTokenQueueFromStr(qTokens,
												funcLineWithoutSpaces))
		throw ::pn_e::InvalidFunction(
			::pn_e::InvalidFunction::ErrType::InvalidToken,
			"invalid_function: Invalid token.");

	funcPostfixTokenQueue_ =
		pn::shunting_yard_alg::convertInfixTokenQueueToPostfix(qTokens);
}

void MenuDataContainer::regenerateField() {
	field_ =
		pn::renderer::getGeneratedField(funcPostfixTokenQueue_, fInfo_);
}

void MenuDataContainer::renderField() const {
    pn::renderer::console::renderField(field_);
}

void MenuDataContainer::renderMenu() const {
    using std::cout, std::endl;

	system("clear");
    cout << "Type: " << actionTypeToStr(actionType_) << endl;
	renderEditableOptions();
    cout << "q - quit; ";
    cout << "m - change mode;" << endl;
    cout << "w, d (k, l) - move up (SELECT), increase value (EDIT);" << endl;
    cout << "s, a (j, h) - move down (SELECT), decrease value (EDIT);" << endl;
    cout << "In case of domain, codomain and center:" << endl;
    cout << "d, a (l, h) - to change the first value;" << endl;
    cout << "w, s (k, j) - to change the second value;" << endl;
}

void MenuDataContainer::initEditableOptions() {
	editableOptions[0].first = "Function: ";
	editableOptions[1].first = "Width: ";
	editableOptions[2].first = "Height: ";
	editableOptions[3].first = "Domain: ";
	editableOptions[4].first = "Codomain: ";
	editableOptions[5].first = "Center: ";
}

void MenuDataContainer::regenerateEditableOption(int idx) {
	switch (idx) {
		case 0:
			editableOptions[idx].second = funcStr_;
			break;
		case 1:
			editableOptions[idx].second = std::to_string(fInfo_.width);
			break;
		case 2:
			editableOptions[idx].second = std::to_string(fInfo_.height);
			break;
		case 3:
			editableOptions[idx].second = "[" + std::to_string(fInfo_.domain.first) + ", " + std::to_string(fInfo_.domain.second) + "]";
			break;
		case 4:
			editableOptions[idx].second = "[" + std::to_string(fInfo_.codomain.first) + ", " + std::to_string(fInfo_.codomain.second) + "]";
			break;
		case 5:
			editableOptions[idx].second = "(" + std::to_string(fInfo_.centerOfCoordinates.first) + ", " + std::to_string(fInfo_.centerOfCoordinates.second) + ")";
			break;
	}
}

void MenuDataContainer::regenerateEditableOptions() {
	for (int i {}; i < n_ED_OPT; ++i)
		regenerateEditableOption(i);
}

void MenuDataContainer::renderEditableOptions() const {
    using std::cout, std::endl;
	for (int i {}; i < n_ED_OPT; ++i) {
		if (i == arrowPos_)
			cout << ">>> ";
		cout << editableOptions[i].first + editableOptions[i].second << endl;
	}
}

std::string MenuDataContainer::actionTypeToStr(
    MenuDataContainer::ActionType a) const {
    switch (actionType_) {
        case ActionType::Select:
            return "SELECT";
        case ActionType::Edit:
            return "EDIT";
        default:
            return std::string();
    }
}

bool MenuDataContainer::update(char pressedKey) {
	char lowerKey = tolower(pressedKey);
	switch (lowerKey)
	{
	case 'm':
		if (isArrowPointsToFunctionOptionInSelectMode())
			updateFunction();

		actionType_ = (ActionType) !((bool) actionType_);
		return true;
	case 'q':
		return false;
	}

	if (actionType_ == ActionType::Select) {
		processPressedKeyInSelectMode(lowerKey);
	} else if (actionType_ == ActionType::Edit) {
		if(processPressedKeyInEditMode(lowerKey)) {
			regenerateEditableOption(arrowPos_);
			regenerateField();
		}
	}

	return true;
}

bool MenuDataContainer::isArrowPointsToFunctionOptionInSelectMode() const {
	return arrowPos_ == 0 && actionType_ == ActionType::Select;
}

void MenuDataContainer::updateFunction() {
	pn_u_c_rm::resetMode(pn_u_c_rm::original);
	pn_ui::setFunctionStr(funcStr_);
	regenerateFunction();
	regenerateField();
	regenerateEditableOption(arrowPos_);
	pn_u_c_rm::setRawMode();
}

void MenuDataContainer::processPressedKeyInSelectMode(char pressedKey) {
	int v = returnValueIfOneOfTheKeyPressed(-1, pressedKey, {'w', 'd', 'k', 'l'});
	if (v == 0) v = returnValueIfOneOfTheKeyPressed(1, pressedKey, {'s', 'a', 'j', 'h'});
	if (v == 0)
		return;

	if (v + arrowPos_ == -1)
		arrowPos_ = n_ED_OPT - 1;
	else if (v + arrowPos_ == n_ED_OPT)
		arrowPos_ = 0;
	else
		arrowPos_ += v;
}

bool MenuDataContainer::processPressedKeyInEditMode(char pressedKey) {
	int v {-2};
	if (arrowPos_ == 1 || arrowPos_ == 2) {
		v = returnValueIfOneOfTheKeyPressed(1, pressedKey, {'w', 'd', 'k', 'l'});
		if (v == 0) v = returnValueIfOneOfTheKeyPressed(-1, pressedKey, {'s', 'a', 'j', 'h'});
		if (v == 0)
			return false;

		if (arrowPos_ == 1)
			fInfo_.width += v;
		else
			fInfo_.height += v;
	} else if (arrowPos_ >= 3 && arrowPos_ <= 5) {
		v = returnValueIfOneOfTheKeyPressed(1, pressedKey, {'d', 'l'});
		if (v == 0) v = returnValueIfOneOfTheKeyPressed(-1, pressedKey, {'a', 'h'});

		if (arrowPos_ == 3)
			fInfo_.domain.first += v;
		else if (arrowPos_ == 4)
			fInfo_.codomain.first += v;
		else if (arrowPos_ == 5)
			fInfo_.centerOfCoordinates.first += v;
		if (v != 0) return true;

		v = returnValueIfOneOfTheKeyPressed(1, pressedKey, {'w', 'k'});
		if (v == 0) v = returnValueIfOneOfTheKeyPressed(-1, pressedKey, {'s', 'j'});
		if (v == 0)
			return false;

		if (arrowPos_ == 3)
			fInfo_.domain.second += v;
		else if (arrowPos_ == 4)
			fInfo_.codomain.second += v;
		else if (arrowPos_ == 5)
			fInfo_.centerOfCoordinates.second += v;
	}

	return true;
}

int MenuDataContainer::returnValueIfOneOfTheKeyPressed(int value, char pressedKey, const std::initializer_list<char>& keys) {
	return ::std::any_of(keys.begin(), keys.end(), [pressedKey](int key) {return key == pressedKey;}) ? value : 0;
}
}