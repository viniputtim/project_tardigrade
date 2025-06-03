# include <raylib.h>
# include "scenes/main_menu.hpp"
# include "core/main_loop.hpp"
# include "ui/button.hpp"


MainMenu::MainMenu(MainLoop* loop) : Scene(loop)
{
    this->testing = std::make_unique<Button> ();
}


MainMenu::~MainMenu()
{
}


void MainMenu::input()
{
}


void MainMenu::update()
{
}


void MainMenu::render()
{
    ClearBackground(RAYWHITE);
    this->testing->draw();
}
