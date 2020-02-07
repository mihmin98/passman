#include "MenuContext.hpp"

MenuContext::MenuContext()
{
    this->state = new StartMenu(this);
}

void MenuContext::SetState(Menu *state)
{
    this->state = state;
}