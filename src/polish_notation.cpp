#include "menu_data_container.h"
#include <iostream>

int main(void) {
	pn_r_c_mdc::MenuDataContainer menuDataContainer;
	menuDataContainer.renderMenu();
	char ch {};
	do {
		menuDataContainer.renderMenu();
		menuDataContainer.renderField();
        if (read(STDIN_FILENO, &ch, 1) == 0) {
			std::cout << "continue" << std::endl;
			continue;
		}
	} while(menuDataContainer.update(ch));
    return 0;
}
