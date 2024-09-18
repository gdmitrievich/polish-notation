#include "menu_data_container.h"
#include "user_err_mess_printer.h"
#include <iostream>

int main(void) {
	try {
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
	} catch (const ::std::exception& e) {
		pn_uemp::printErrMess(e);
		exit(EXIT_FAILURE);
	}
    return 0;
}
