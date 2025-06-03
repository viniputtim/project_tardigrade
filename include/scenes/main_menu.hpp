# ifndef MAIN_MENU_HPP
# define MAIN_MENU_HPP


# include <memory>
# include "core/scene.hpp"


class MainLoop;
class Button;


class MainMenu : public Scene
{
private:
    std::unique_ptr<Button> testing;

public:
    MainMenu(MainLoop*);
    ~MainMenu() override;

    void input() override;
    void update() override;
    void render() override;
};


# endif
