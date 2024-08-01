#include "ToolBox.h"
#include <math.h>

class Menu
{
private:
    /* data */
    int width;
    int height;
    int MicroHeight;
    int num;
    int color;
public:
    Menu();
    Menu(int W, int H, int MH, int Col);
    ~Menu();
    void drawMenu();
    int CheckIfHover(sf::Vector2i Vector, sf::Vector2f BoxVector);
};

