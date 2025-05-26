# ifndef SCENE_HPP
# define SCENE_HPP


class MainLoop;


class Scene
{
protected:
    MainLoop* loop;
public:
    Scene(MainLoop* loop) : loop(loop) {};
    virtual ~Scene() = default;

    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};


# endif
