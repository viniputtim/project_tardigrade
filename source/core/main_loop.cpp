# include <raylib.h>
# include "core/main_loop.hpp"
# include "core/scene_manager.hpp"


void MainLoop::input()
{
    this->scene_manager->input();
}


void MainLoop::update()
{
    this->scene_manager->update();
}


void MainLoop::render()
{
    this->scene_manager->render();
}


MainLoop::MainLoop()
{
    this->scene_manager = std::make_unique<SceneManager> (this);
    this->change_scene("loading");
}


MainLoop::~MainLoop()
{
}


void MainLoop::run()
{
    while (!WindowShouldClose())
    {
        this->input();
        this->update();
        this->render();
    }
}


void MainLoop::change_scene(std::string scene_name)
{
    this->scene_manager->change_scene(scene_name);
}
