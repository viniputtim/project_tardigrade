# include <raylib.h>
# include "core/main_loop.hpp"


int main()
{
    InitWindow(0, 0, "Project Tardigrade");
    InitAudioDevice();
    ToggleFullscreen();
    SetMasterVolume(0.5);
    SetTargetFPS(0);

    MainLoop loop;
    loop.run();

    CloseWindow();
    CloseAudioDevice();

    return 0;
}
