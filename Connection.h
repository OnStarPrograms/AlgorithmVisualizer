#pragma once
#include "Node.h"
#include "ToolBox.h"
#include <math.h>

class Connection {
private:
  sf::RectangleShape *_Connection;
  Node *StartNode;
  Node *EndNode;
  int Weight = 1;
  sf::Text* WeightText = new sf::Text(std::to_string(Weight), mytools.DosFont, 30);
  int active = 0;
  ToolBox mytools = ToolBox::getInstance();

public:
  Connection() { ; };

  Connection(Node *_start) {
    StartNode = _start;
    _Connection = new sf::RectangleShape(sf::Vector2f(5, 5));
    active = 1;
  };

  Connection(Node *_start, int _weight) {
    StartNode = _start;
    _Connection = new sf::RectangleShape(sf::Vector2f(5, 2));
    active = 1;
    Weight = _weight;
    _Connection->setOrigin(0., 0.);
    _Connection->move(_start->getX(), _start->getY());
  };

  int UpdateConnection();
  void EndConnection(Node *_EndNode);
  sf::RectangleShape *GetDrawable();
  int isactive();
  void changeColor(sf::Color color);
  Node* getStartNode(){return StartNode;};
  Node* getEndNode(){return EndNode;};
  int GetWeight(){return Weight;};
  void addWeight(int num){
    Weight+=num;
  }
  sf::Text *GetTextDrawable();
  /*//Node* ConnectedNode1;
    //Node* ConnectedNode2;
    int numOfData = 0;
    int max = 0;
         int active = 0;
  Node() { ; };
  Node(sf::Vector2f Dim, sf::Vector2f) {
    active = 1;
    Shaper = new sf::RectShape(sf::Vector2i(100,10));
    Shaper->setOrigin(0., 0.);
    Shaper->setPosition(Dim);
  }
  sf::CircleShape *GetDrawable() { return Shaper; };
  void setX_Y(sf::Vector2f Coor) { Shaper->setPosition(Coor); };
  float getX() { return Shaper->getPosition().x; };
  float getY() { return Shaper->getPosition().y; };
};*/
};
