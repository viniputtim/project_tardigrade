# include <raylib.h>
# include "scenes/loading.hpp"
# include "core/main_loop.hpp"


Loading::Loading(MainLoop* loop) : Scene(loop)
{
}


Loading::~Loading()
{
}


void Loading::input()
{
    if (IsMouseButtonPressed(0))
    {
        this->loop->change_scene("main menu");
    }
}


void Loading::update()
{
}


void Loading::render()
{
    ClearBackground(YELLOW);
}
