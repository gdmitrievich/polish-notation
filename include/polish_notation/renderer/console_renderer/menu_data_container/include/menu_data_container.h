#ifndef MENU_DATA_CONTAINER_H
#define MENU_DATA_CONTAINER_H

#include <string>
#include <vector>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/renderer/field_info.h"
#include "polish_notation/token/token.h"

namespace polish_notation::renderer::console::menu_data_container {
class MenuDataContainer {
   private:
    enum class ActionType : char { Select, Edit };

    ::std::string funcStr_;
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>
        funcPostfixTokenQueue_;
    ::polish_notation::renderer::FieldInfo fInfo_;
	::std::vector<::std::vector<char>> field_;

    ActionType actionType_;
    int arrowPos_;

    void regenerateField();
    void regenerateFunction();

   public:
    MenuDataContainer();

    void renderField() const;
    void printMenu() const;
    bool update(char pressedKey);
};

namespace pn = polish_notation;
namespace pn_ds = polish_notation::data_structures;
} // namespace polish_notation::renderer::console::menu_data_container

namespace pn_r_c_mdc = polish_notation::renderer::console::menu_data_container;

#endif // MENU_DATA_CONTAINER_H