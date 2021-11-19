#include <raylib.h>

int menuSelecao()
{
    int x, y;
    Vector2 mouse = {x, y};

    mouse = GetMousePosition();
    if ((mouse.x > 580 && mouse.x < 735) && (mouse.y > 350 && mouse.y < 380) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 1;
    }

    else if ((mouse.x > 545 && mouse.x < 775) && (mouse.y > 400 && mouse.y < 430) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 2;
    }

    else if ((mouse.x > 570 && mouse.x < 740) && (mouse.y > 450 && mouse.y < 480) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 3;
    }

    else if ((mouse.x > 625 && mouse.x < 680) && (mouse.y > 500 && mouse.y < 530) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 4;
    }
}
