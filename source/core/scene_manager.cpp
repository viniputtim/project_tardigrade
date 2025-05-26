# include <raylib.h>
# include "core/scene_manager.hpp"
# include "core/main_loop.hpp"
# include "core/scene.hpp"
# include "scenes/loading.hpp"
# include "scenes/main_menu.hpp"


SceneManager::SceneManager(MainLoop* loop)
{
    this->loop = loop;
}


SceneManager::~SceneManager()
{
}


void SceneManager::change_scene(std::string scene_name)
{
    if (scene_name == "loading")
    {
        this->current_scene = std::make_unique<Loading> (this->loop);
    }
    else if (scene_name == "main menu")
    {
        this->current_scene = std::make_unique<MainMenu> (this->loop);
    }
}


void SceneManager::input()
{
    this->current_scene->input();
}


void SceneManager::update()
{
    this->current_scene->update();
}


void SceneManager::render()
{
    BeginDrawing();
    this->current_scene->render();
    DrawFPS(0, 0);
    EndDrawing();
}
