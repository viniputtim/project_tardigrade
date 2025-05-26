# ifndef SCENE_MANAGER_HPP
# define SCENE_MANAGER_HPP


# include <memory>
# include <string>


class MainLoop;
class Scene;


class SceneManager
{
private:
    MainLoop* loop;
    std::unique_ptr<Scene> current_scene;

public:
    SceneManager(MainLoop* loop);
    ~SceneManager();

    void change_scene(std::string scene_name);
    void input();
    void update();
    void render();
};


# endif
