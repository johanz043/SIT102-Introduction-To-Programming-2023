#include "splashkit.h"

void draw_house_scene()
{
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen(60);
}

void draw_circle()
{
     clear_screen(COLOR_WHITE);
     fill_circle(COLOR_BLACK, 400, 300, 300);
     refresh_screen(60);

}

int main()
{
    open_window("My Drawing", 800, 600);

    draw_house_scene();
    delay(1000);
    clear_screen(COLOR_BLACK);
    delay(1000);
    
    draw_circle();
    delay(1000);

    draw_house_scene();
    delay(1000);

    draw_circle();
    delay(1000);

    return 0;
}