#pragma once
#include "Stack.h"
#include <SFML/Graphics.hpp>

class Handler;

class ToolBox {
private:
  ToolBox() {

    if (!DosFont.loadFromFile("MorePerfectDOSVGA.ttf")) {
      throw EXIT_FAILURE;
    };
  };

public:
  static ToolBox &getInstance() {
    static ToolBox mine;
    return mine;
  };
  sf::Font DosFont;

  Handler *Handle;
  enum RightClick { MENU, NONE };
  RightClick CurrentAvailable = MENU;
  sf::RenderWindow *window =
      new sf::RenderWindow(sf::VideoMode(1600, 1200), "Algorithm");
  sf::Mouse mouse;
  sf::Vector2i mousevec;
  Stack<sf::RectangleShape> aboveCircleStack;
  Stack<sf::Text> TextStack;
  Stack<sf::RectangleShape> RectStack;
  Stack<sf::CircleShape> CircStack;
  sf::Vector2f RightClickPosition;
  int menu = 0b0;
  int menuselect = 0b00000;
  int menuselectsize = 5;

  bool isKthBitSet(int n, int k) {
    if (n & (1 << k))
      return true;
    else
      return false;
  }
  /*
  ///////////////////////
  |  1 Byte  |  2 Byte  |
  +----------+----------+
  | R.C.Menu | 1.Option |
  ///////////////////////
  */
};
