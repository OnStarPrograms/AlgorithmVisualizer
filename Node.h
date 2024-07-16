#include "ToolBox.h"

class Node {
  sf::CircleShape *Shaper;
  std::vector<Node *> ConnectedNodes;

public:
  Node(){;};
  Node(sf::Vector2f Dim) { Shaper = new sf::CircleShape(30.); Shaper->setPosition(Dim); }
  sf::CircleShape *GetDrawable() { return Shaper; };
  void addConnectedNode(Node *node) { ConnectedNodes.push_back(node); };
  void setX_Y(sf::Vector2f Coor) {Shaper->setPosition(Coor); };
  float getX() { return Shaper->getPosition().x; };
  float getY() { return Shaper->getPosition().y; };
};
