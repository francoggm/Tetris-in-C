#include <raylib.h>

int menuSelecao()
{
    int x, y;
    Vector2 mouse = {x, y};

    mouse = GetMousePosition();
    if ((mouse.x > 550 && mouse.x < 705) && (mouse.y > 350 && mouse.y < 380) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 1;
    }

    else if ((mouse.x > 515 && mouse.x < 745) && (mouse.y > 400 && mouse.y < 430) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 2;
    }

    else if ((mouse.x > 540 && mouse.x < 710) && (mouse.y > 450 && mouse.y < 480) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 3;
    }

    else if ((mouse.x > 595 && mouse.x < 650) && (mouse.y > 500 && mouse.y < 530) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 4;
    }
}
