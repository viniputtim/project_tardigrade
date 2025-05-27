# include <raylib.h>
# include "scenes/loading.hpp"
# include "core/main_loop.hpp"


Loading::Loading(MainLoop* loop) : Scene(loop)
{
    float center_x = static_cast<float> (GetScreenWidth() / 2);
    float center_y = static_cast<float> (GetScreenHeight() / 2);

    this->borders["left"].x = center_x - (this->rect.width / 2);
    this->borders["top"].x = center_x - (this->rect.width / 2);
    this->borders["right"].x = center_x + (this->rect.width / 2) - this->borders["right"].width;
    this->borders["bottom"].x = center_x - (this->rect.width / 2);

    this->borders["left"].y = center_y - (this->rect.height / 2);
    this->borders["top"].y = center_y - (this->rect.height / 2);
    this->borders["right"].y = center_y - (this->rect.height / 2);
    this->borders["bottom"].y = center_y + (this->rect.height / 2) - this->borders["bottom"].height;

    this->text_rect.height = 80;
    this->text_rect.width = MeasureText(this->raylib_text.c_str(), this->text_rect.height);
    this->text_rect.x = this->borders["right"].x - this->text_rect.width - 50;
    this->text_rect.y = this->borders["bottom"].y - this->text_rect.height - 50;
}


Loading::~Loading()
{
}


void Loading::input()
{
}


void Loading::update()
{
    float current_time = GetTime();
    float dt = GetFrameTime();
    float dw = this->growth_speed * dt;
    float dh = this->growth_speed * dt;

    if (current_time >= 2 && this->borders["left"].width < this->rect.width)
    {
        this->borders["left"].height += dh;
        this->borders["top"].width += dw;

        if (this->borders["left"].height > this->rect.height)
        {
            this->borders["left"].height = this->rect.height;
        }

        if (this->borders["top"].width > this->rect.width)
        {
            this->borders["top"].width = this->rect.width;
        }
    }

    if (this->borders["left"].height == this->rect.height)
    {
        this->borders["right"].height += dh;
        this->borders["bottom"].width += dw;

        if (this->borders["right"].height > this->rect.height)
        {
            this->borders["right"].height = this->rect.height;
        }

        if (this->borders["bottom"].width > this->rect.width)
        {
            this->borders["bottom"].width = this->rect.width;
        }
    }

    if (this->borders["right"].height == this->rect.height)
    {
        if (
            current_time - this->last_time > 0.1 &&
            this->raylib_text.size() != this->current_text.size()
        )
        {
            this->current_text = this->raylib_text.substr(0, this->current_text.size() + 1);
            this->last_time = current_time;
        }
    }

    if (this->raylib_text == this->current_text)
    {
        if (current_time - this->last_time > 2)
        {
            this->loop->change_scene("main menu");
        }
    }
}


void Loading::render()
{
    ClearBackground(RAYWHITE);

    int current_time = (GetTime() * 4);

    if (current_time > 2 * 4 || current_time % 2)
    {
        DrawRectangleRec(this->borders["left"], BLACK);
        DrawRectangleRec(this->borders["top"], BLACK);
    }

    if (this->borders["left"].height == this->rect.height)
    {
        DrawRectangleRec(this->borders["right"], BLACK);
        DrawRectangleRec(this->borders["bottom"], BLACK);
    }

    if (this->borders["right"].height == this->rect.height)
    {
        DrawText(
            this->current_text.c_str(), this->text_rect.x, this->text_rect.y,
            this->text_rect.height, BLACK
        );
    }
}
