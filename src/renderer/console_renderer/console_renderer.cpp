#include "console_renderer.h"

#include <iostream>

using std::cout, std::endl;
using std::vector;

namespace polish_notation::renderer::console {
void renderField(const vector<vector<char>>& field) {
    const int HEIGHT = field.size();
    const int WIDTH = field[0].size();

    for (int i {}; i < HEIGHT; ++i) {
        for (int j {}; j < WIDTH; ++j) {
            cout << field[i][j];
        }
        cout << endl;
    }
}
} // namespace polish_notation::renderer::console