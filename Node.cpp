#include "Node.h"
#include "Connection.h"

sf::CircleShape *Node::GetDrawable() { return Shaper; };
void Node::addConnectedNode(Node *node) { ConnectedNodes.push_back(node); };
std::vector<Node *> Node::GetConnectedNode() { return ConnectedNodes; };

void Node::DeleteConnectedNode(Node *node) {
  ConnectedNodes.erase(
      std::find(ConnectedNodes.begin(), ConnectedNodes.end(), node));
};
void Node::setX_Y(sf::Vector2f Coor) { Shaper->setPosition(Coor); };
float Node::getX() { return Shaper->getPosition().x; };
float Node::getY() { return Shaper->getPosition().y; };
void Node::ChangeColor(sf::Color color) { Shaper->setFillColor(color); };
int Node::isactive() { return active; };
void Node::addConnectionBlock(Connection *connection) {
  Connections.push_back(connection);
};
std::vector<Connection *> Node::getConnectedConnects() { return Connections; };

// Goal Go through the Connections vector and if there are any duplicates,
// delete them and add the duplicates weight to the weight of the og.
//

void Node::addWeight(int num, Connection *Checksum) {
  for (int i = 0; i < Connections.size(); i++) {
    if (Checksum == Connections[i])
    {
      Connections[i]->addWeight(num);
    }
  }
}
