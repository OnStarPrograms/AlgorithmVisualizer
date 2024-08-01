#include "Node.h"

sf::CircleShape *Node::GetDrawable() { return Shaper; };
void Node::addConnectedNode(Node *node) { ConnectedNodes.push_back(node); };
std::vector<Node *> Node::GetConnectedNode() {return ConnectedNodes;};

void Node::DeleteConnectedNode(Node *node) {
  ConnectedNodes.erase(
      std::find(ConnectedNodes.begin(), ConnectedNodes.end(), node));
};
void Node::setX_Y(sf::Vector2f Coor) { Shaper->setPosition(Coor); };
float Node::getX() { return Shaper->getPosition().x; };
float Node::getY() { return Shaper->getPosition().y; };
void Node::ChangeColor(sf::Color color) { Shaper->setFillColor(color); };
int Node::isactive() { return active; };
