# ifndef MAIN_LOOP_HPP
# define MAIN_LOOP_HPP


# include <memory>
# include <string>


class SceneManager;


class MainLoop
{
private:
    std::unique_ptr<SceneManager> scene_manager;

    void input();
    void update();
    void render();

public:
    MainLoop();
    ~MainLoop();

    void run();
    void change_scene(std::string scene_name);
};


# endif
