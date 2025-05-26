# ifndef LOADING
# define LOADING


# include "core/scene.hpp"


class MainLoop;


class Loading : public Scene
{
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
