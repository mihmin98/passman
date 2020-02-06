#include "MenuContext.hpp"

MenuContext::MenuContext()
{
    this->state = new StartMenu();
}

void MenuContext::SetState(Menu *state)
{
    this->state = state;
}