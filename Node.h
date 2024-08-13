#pragma once
#include "ToolBox.h"
#include <vector>
class Connection;
class Node {
  sf::CircleShape *Shaper;

public:
  std::vector<Node *> ConnectedNodes;
  std::vector<Connection *> Connections;
  int active = 0;
  Node() { ; };
  Node(sf::Vector2f Dim) {
    active = 1;
    Shaper = new sf::CircleShape(40.);
    Shaper->setOrigin(40., 40.);
    Shaper->setPosition(Dim);
  }
  std::vector<Node *> GetConnectedNode();
  sf::CircleShape *GetDrawable();
  void addConnectedNode(Node *node);
  void DeleteConnectedNode(Node *node);
  void setX_Y(sf::Vector2f Coor);
  float getX();
  float getY();
  void ChangeColor(sf::Color color);
  int isactive();
  void addConnectionBlock(Connection* connection);
  std::vector<Connection *> getConnectedConnects();
  void addWeight(int num, Connection* Checksum);
};
