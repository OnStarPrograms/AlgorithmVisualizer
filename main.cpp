#include "Handler.h"
#include "LinkedList.h"
#include "Menu.h"
#include "ToolBox.h"
#include <stdio.h>

void Render();
void InputHandler();
void RightClick();

int main() {
  // Open the ToolBox
  ToolBox &tools = ToolBox::getInstance();
  Menu RightClickMenu;
  tools.Handle = new Handler;
  // run the program as long as the window is open
  while (tools.window->isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop

    if ((tools.menu ^ 0b0) == 0b1) {
      RightClickMenu.drawMenu();
      for (int i = 0; i < tools.menuselectsize; i++) {
        // printf("%i \n", tools.menuselect);
        if (tools.isKthBitSet(tools.menuselect, i)) {
          printf(" : %x \n", i);
          sf::CircleShape circ(30);
          circ.setFillColor(sf::Color(0 + 100 * i, 100, 100));
          tools.CircStack.push(circ);
        }
      }
    }
    if (tools.Handle->IsActive()) {
      tools.Handle->SetNode();
    }
    InputHandler();
    Render();
  }

  return 0;
}

void Render() {

  ToolBox &tools = ToolBox::getInstance();
  tools.Handle->DrawHandles();
  // clear the window with black color
  tools.window->clear(sf::Color::Black);

  // draw everything here...
  // window.draw(...);
  while (tools.CircStack.getSize() > 0) {
    tools.window->draw(tools.CircStack.pop());
  }
  while (tools.RectStack.getSize() > 0) {
    tools.window->draw(tools.RectStack.pop());
  }

  // end the .current frame
  tools.window->display();
}

void InputHandler() {
  ToolBox &tools = ToolBox::getInstance();

  sf::Event event;
  tools.mousevec = tools.mouse.getPosition(*tools.window);

  while (tools.window->pollEvent(event)) {
    // "close requested" event: we close the window
    if (event.type == sf::Event::Closed)
      tools.window->close();
    else if (event.type == sf::Event::Resized)
      tools.window->setView(
          sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

    if ((event.type == sf::Event::MouseButtonPressed) &&
        (event.mouseButton.button == sf::Mouse::Button::Right)) {
      RightClick();
    } else if ((event.type == sf::Event::MouseButtonPressed) ||
               (event.type == sf::Event::KeyPressed)) {
      tools.menu &= 0b0;
    }

    if ((event.type == sf::Event::MouseButtonPressed) &&
        (event.mouseButton.button == sf::Mouse::Button::Left)) {
      if (tools.isKthBitSet(tools.menuselect, 0)) {
        tools.Handle->AddNode();
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      if (tools.Handle->IsActive()) {
        tools.Handle->FinishNode();
      }
    }
  }
}

void RightClick() {
  ToolBox &tools = ToolBox::getInstance();
  switch (tools.CurrentAvailable) {
  case tools.MENU:
    tools.menu |= 0b1;
    tools.RightClickPosition.x = tools.mousevec.x;
    tools.RightClickPosition.y = tools.mousevec.y;
    break;

  default:
    break;
  }
};
