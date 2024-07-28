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

    if (tools.menu == 0b1) {
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
      // If Node Placer is active update the temp Node
      tools.Handle->SetNode();
    } else {

      std::vector<Node *> noders = tools.Handle->GetNotConnectedNode();
      for (int i = 1; i < noders.size(); i++) {
        tools.Handle->SetUnconnectedConnection(noders[i - 1]);
        tools.Handle->UpdateConnection();
        /*tools.Handle->SetConnectedConnection(noders[i]); // This Function Connects one node to the other.*/
        printf("Set Node");
      }
      std::vector<Node *> Noders = tools.Handle->GetNotConnectedNode();
      for (int i = 0; i < Noders.size(); i++) {
        Noders[i]->ChangeColor(sf::Color(255, 255, 255));
      }

      // This is a Test For Connecting Nodes, Need to connect Nodes
      Node *node = tools.Handle->GetConnectedNode();
      if (node != nullptr) {
        node->ChangeColor(sf::Color(100, 250, 0)); // Green On Hover
        for (int i = 0; i < node->ConnectedNodes.size(); i++) {
          node->ConnectedNodes[i]->ChangeColor(
              sf::Color(250, 100, 0)); // Red For Connected Nodes
        }
      }
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
  while (tools.RectStack.getSize() > 0) {
    tools.window->draw(tools.RectStack.pop());
  }
  while (tools.CircStack.getSize() > 0) {
    tools.window->draw(tools.CircStack.pop());
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
        (event.mouseButton.button == sf::Mouse::Button::Left)) {
      if (tools.isKthBitSet(tools.menuselect, 0) && (tools.menu ^ 0b0) == 0b1) {
        tools.Handle->AddNode();
      } else if (tools.Handle->IsActive()) {
        tools.Handle->AddNode();
      }
    }

    if ((event.type == sf::Event::MouseButtonPressed) &&
        (event.mouseButton.button == sf::Mouse::Button::Right)) {
      RightClick();
    } else if ((event.type == sf::Event::MouseButtonPressed) ||
               (event.type == sf::Event::KeyPressed)) {
      tools.menu &= 0b0;
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
