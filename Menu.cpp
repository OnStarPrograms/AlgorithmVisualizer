#include "Menu.h"
Menu::Menu()
{
    width = 250;
    height = 300;
    MicroHeight = height/5;
    num = 5;
    color = 100;
}




Menu::Menu(int W, int H, int MH, int Col)
{
    width = W;
    height = H;
    MicroHeight = height/MH;
    num = MH;
    color = Col;
}

Menu::~Menu()
{
}

void Menu::drawMenu()
{
    ToolBox &tools = ToolBox::getInstance();
    std::vector<std::string> myString = {"Create Nodes", "Auto Connect", "3", "4", "5"};
    for (int i = 0; i < num; i++)
    {
        
        sf::Vector2f Boxs = tools.RightClickPosition;
        Boxs.y += (MicroHeight*i);
        int check = CheckIfHover(tools.mousevec, Boxs);
        int _pow = pow(2,i);
        if (check)
        {
            tools.menuselect |= _pow;
        }
        else{
            tools.menuselect &= ~_pow;
        }
        color = color+100*check;
        sf::RectangleShape Menu(sf::Vector2f(width, MicroHeight));
         sf::Text myText (myString[i], tools.DosFont, 30); 
        Menu.move(Boxs);
        Boxs.x += 15;
        myText.move(Boxs);
        Menu.setFillColor(sf::Color(color*0, color, color));
        Menu.setOutlineColor(sf::Color(0, 0, 0));
        Menu.setOutlineThickness(1.5);
        tools.aboveCircleStack.push(Menu);
        tools.TextStack.push(myText);
        color = color-100*CheckIfHover(tools.mousevec, Boxs);
    }

    sf::RectangleShape Menu(sf::Vector2f(width, height));
    Menu.move(tools.RightClickPosition);
    tools.RectStack.push(Menu);
};

int Menu::CheckIfHover(sf::Vector2i MouseVector, sf::Vector2f BoxVector)
{
    if ((BoxVector.y < MouseVector.y && MouseVector.y < (BoxVector.y+MicroHeight)) && 
        (BoxVector.x < MouseVector.x && MouseVector.x < (BoxVector.x+width)))
    {
        return 1;
    };
    return 0;
};
