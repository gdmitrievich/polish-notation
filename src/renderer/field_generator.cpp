#include "polish_notation/renderer/field_generator.h"

#include <cmath>
#include <iostream>

#include "polish_notation/exceptions/invalid_field_info_exception/invalid_field_info_exception.h"
#include "polish_notation/polish_calculation/polish_calculation.h"

namespace polish_notation::renderer {
using polish_notation::data_structures::queue::Queue;
using polish_notation::token::Token;
using std::pair;
using std::vector;

using polish_notation::polish_calculation::calculatePostfixTokenQueue;
using polish_notation::polish_calculation::replaceAllXWithNumInTokenQueue;

using std::cout, std::endl;

vector<vector<char>> getGeneratedField(const Queue<Token>& qPostfix,
                                       FieldInfo fieldInfo) {
	checkInputDataAndThrowExceptionIfNeeded(fieldInfo);

    vector<vector<char>> field;
    fillFieldByDefault(field, fieldInfo);

    const double WIDTH_IN_NEW_SYSTEM =
        fieldInfo.domain.second - fieldInfo.domain.first;
    const double WIDTH_SEGMENT_SIZE = WIDTH_IN_NEW_SYSTEM / fieldInfo.width;
    const double HEIGHT_IN_NEW_SYSTEM =
        fieldInfo.codomain.second - fieldInfo.codomain.first;
    const double HEIGHT_SEGMENT_SIZE = HEIGHT_IN_NEW_SYSTEM / fieldInfo.height;

    bool isOk = true;
    for (double i = fieldInfo.domain.first; isOk && i < fieldInfo.domain.second;
         i += WIDTH_SEGMENT_SIZE) {
        int xInitInSrcCoords = round(i / WIDTH_SEGMENT_SIZE);
        int xInSrcCoords =
            xInitInSrcCoords + fieldInfo.centerOfCoordinates.first;
        if (xInSrcCoords < 0 || xInSrcCoords >= fieldInfo.width)
            continue;

        Queue<Token> qPostfixWithoutX(qPostfix);
        replaceAllXWithNumInTokenQueue(qPostfixWithoutX, i);
        double v = calculatePostfixTokenQueue(qPostfixWithoutX);
        if (v >= fieldInfo.codomain.first && v <= fieldInfo.codomain.second) {
            int yInitInSrcCoords = round(v / HEIGHT_SEGMENT_SIZE);
            int yInSrcCoords =
                fieldInfo.centerOfCoordinates.second - yInitInSrcCoords;
            if (yInSrcCoords >= 0 && yInSrcCoords < fieldInfo.height) {
                const char FUNC_VALUE_CHAR = '*';
                field[yInSrcCoords][xInSrcCoords] = FUNC_VALUE_CHAR;
            }
        }
    }

    return field;
}

void checkInputDataAndThrowExceptionIfNeeded(const FieldInfo& f) {
    if (f.width <= 0)
        throw ::pn_e::InvalidFieldInfoException(
            ::pn_e::InvalidFieldInfoException::ErrType::NegativeOrZeroWidth,
            "invalid_field_info: Negative or zero width error.");
    if (f.height <= 0)
        throw ::pn_e::InvalidFieldInfoException(
            ::pn_e::InvalidFieldInfoException::ErrType::NegativeOrZeroHeigth,
            "invalid_field_info: Negative or zero height error.");
	if (f.domain.first > f.domain.second)
        throw ::pn_e::InvalidFieldInfoException(
            ::pn_e::InvalidFieldInfoException::ErrType::InvalidDomain,
            "invalid_field_info: Invalid domain error.");
	if (f.codomain.first > f.codomain.second)
        throw ::pn_e::InvalidFieldInfoException(
            ::pn_e::InvalidFieldInfoException::ErrType::InvalidCodomain,
            "invalid_field_info: Invalid codomain error.");
}

void fillFieldByDefault(vector<vector<char>>& f, FieldInfo fInfo) {
    const char EMPTY_CELL_CHAR = '.';
    const char COORD_LINE_CHAR = 'o';
    const char RIGHT_ARROW_CHAR = '>';
    const char UP_ARROW_CHAR = '^';

    f = vector<vector<char>>(fInfo.height,
                             vector<char>(fInfo.width, EMPTY_CELL_CHAR));

    if (fInfo.centerOfCoordinates.second >= 0 &&
        fInfo.centerOfCoordinates.second < fInfo.height) {
        f[fInfo.centerOfCoordinates.second] =
            vector<char>(fInfo.width, COORD_LINE_CHAR);
        f[fInfo.centerOfCoordinates.second][fInfo.width - 1] = RIGHT_ARROW_CHAR;
    }
    if (fInfo.centerOfCoordinates.first >= 0 &&
        fInfo.centerOfCoordinates.first < fInfo.width) {
        for (int i {}; i < fInfo.height; ++i)
            f[i][fInfo.centerOfCoordinates.first] = COORD_LINE_CHAR;
        f[0][fInfo.centerOfCoordinates.first] = UP_ARROW_CHAR;
    }
}
} // namespace polish_notation::renderer