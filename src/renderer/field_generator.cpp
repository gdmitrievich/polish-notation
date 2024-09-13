#include "field_generator.h"

#include "../polish_calculation/polish_calculation.h"

using polish_notation::data_structures::queue::Queue;
using polish_notation::token::Token;
using std::pair;
using std::vector;

using polish_notation::polish_calculation::replaceAllXWithNumInTokenQueue;
using polish_notation::polish_calculation::tryCalculatePostfixTokenQueue;

#include <iostream>
using std::cout, std::endl;

namespace polish_notation::renderer {
pair<bool, vector<vector<char>>> tryGetGeneratedField(
    const Queue<Token>& qPostfix, FieldInfo fieldInfo) {
    if (fieldInfo.width <= 0 || fieldInfo.height <= 0)
        return pair(false, ::std::vector<vector<char>>());

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
        ::std::pair valuePair = tryCalculatePostfixTokenQueue(qPostfixWithoutX);
        if (valuePair.first) {
            double v = valuePair.second;
            if (v >= fieldInfo.codomain.first &&
                v <= fieldInfo.codomain.second) {
                int yInitInSrcCoords = round(v / HEIGHT_SEGMENT_SIZE);
                int yInSrcCoords =
                    fieldInfo.centerOfCoordinates.second - yInitInSrcCoords;
                if (yInSrcCoords >= 0 && yInSrcCoords < fieldInfo.height) {
                    const char FUNC_VALUE_CHAR = '*';
                    field[yInSrcCoords][xInSrcCoords] = FUNC_VALUE_CHAR;
                }
            }
        } else {
            isOk = false;
        }
    }

    return pair<bool, vector<vector<char>>>(isOk, field);
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