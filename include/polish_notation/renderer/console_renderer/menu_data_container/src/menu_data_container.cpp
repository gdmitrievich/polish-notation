#include "menu_data_container.h"

#include "user_input.h"
#include "polish_notation/renderer/field_generator.h"
#include "user_err_mess_printer.h"

namespace polish_notation::renderer::console::menu_data_container {
MenuDataContainer::MenuDataContainer() : funcStr_(), funcPostfixTokenQueue_(), fInfo_(), actionType_(ActionType::Select), arrowPos_() {
	try {
		pn_ui::setFunctionStr(funcStr_);
		regenerateFunction();

		pn_ui::setFieldInfo(fInfo_);
		pn::renderer::checkInputDataAndThrowExceptionIfNeeded(fInfo_);
    } catch (const ::std::exception& e) {
        pn_uemp::printErrMess(e);
        exit(EXIT_FAILURE);
    }
}
}