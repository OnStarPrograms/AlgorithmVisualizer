#pragma once
#include "Node.h"
#include "ToolBox.h"
#include <math.h>

class Connection {
private:
  sf::RectangleShape *_Connection;
  Node *StartNode;
  Node *EndNode;
  int Weight = 0;
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

  int UpdateConnection() {
    if (!active)
      return 0;
    float _math = sqrt(pow(abs((StartNode->getX() - mytools.mousevec.x)), 2) +
                       pow(abs(StartNode->getY() - mytools.mousevec.y), 2));
    _Connection->setSize(sf::Vector2f(_math, 2));
    double rotation = 180 + atan2((StartNode->getY() - mytools.mousevec.y),
                                  ((StartNode->getX() - mytools.mousevec.x))) *
                                (180.0 / 3.141592653589793238463);
    _Connection->setRotation(rotation);
    _Connection->setPosition(StartNode->getX(), StartNode->getY());
    return 1;
  };

  void EndConnection(Node *_EndNode) {
    active = 0;
    EndNode = _EndNode;
    float _math = sqrt(pow(abs((StartNode->getX() - EndNode->getX())), 2) +
                       pow(abs(StartNode->getY() - EndNode->getY()), 2));
    _Connection->setSize(sf::Vector2f(_math, 2));
    float rotation = 180 + atan2((StartNode->getY() - EndNode->getY()),
                                 ((StartNode->getX() - EndNode->getX()))) *
                               (180.0 / 3.141592653589793238463);
    _Connection->setRotation(rotation);
    _Connection->setPosition(StartNode->getX(), StartNode->getY());
  }

  sf::RectangleShape *GetDrawable() { return _Connection; }
  int isactive() { return active; };

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
