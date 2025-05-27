# ifndef LOADING_HPP
# define LOADING_HPP


# include <map>
# include <string>
# include "core/scene.hpp"


class MainLoop;


class Loading : public Scene
{
private:
    int growth_speed = 250;
    std::map<std::string, Rectangle> borders = {
        {"left", {0, 0, 40, 40}},
        {"top", {0, 0, 40, 40}},
        {"right", {0, 0, 40, 40}},
        {"bottom", {0, 0, 40, 40}}
    };
    Rectangle rect = {0, 0, 500, 500};
    Rectangle text_rect = {0, 0, 0, 0};
    std::string raylib_text = "raylib";
    std::string current_text = "";
    float last_time = 0;
public:
    Loading(MainLoop* loop);
    ~Loading() override;

    void input() override;
    void update() override;
    void render() override;
};


# endif

# ifndef CLASS_NAME
# define CLASS_NAME


class ClassName
{
private:
protected:
public:
    ClassName();
    ~ClassName();
};


# endif

# ifndef SCENE_NAME_HPP
# define SCENE_NAME_HPP


# include "core/scene.hpp"


class SceneName : public Scene
{
private:
public:
    SceneName();
    ~SceneName();

    void input() override;
    void update() override;
    void render() override;
};


# endif
