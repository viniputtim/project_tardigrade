# ifndef MAIN_MENU_HPP
# define MAIN_MENU_HPP


# include "core/scene.hpp"


class MainLoop;


class MainMenu : public Scene
{
public:
    MainMenu(MainLoop*);
    ~MainMenu() override;

    void input() override;
    void update() override;
    void render() override;
};


# endif
