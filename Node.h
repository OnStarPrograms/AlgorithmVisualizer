#pragma once
#include "ToolBox.h"
#include <vector>


class Node {
  sf::CircleShape *Shaper;

public:
  std::vector<Node *> ConnectedNodes;
  int active = 0;
  Node() { ; };
  Node(sf::Vector2f Dim) {
    active = 1;
    Shaper = new sf::CircleShape(40.);
    Shaper->setOrigin(30., 30.);
    Shaper->setPosition(Dim);
  }
  sf::CircleShape *GetDrawable() { return Shaper; };
  void addConnectedNode(Node *node) { ConnectedNodes.push_back(node); };
  void DeleteConnectedNode(Node *node) {
    ConnectedNodes.erase(
        std::find(ConnectedNodes.begin(), ConnectedNodes.end(), node));
  };
  void setX_Y(sf::Vector2f Coor) { Shaper->setPosition(Coor); };
  float getX() { return Shaper->getPosition().x; };
  float getY() { return Shaper->getPosition().y; };
  void ChangeColor(sf::Color color) {Shaper->setFillColor(color); };
  int isactive() { return active; };
};
