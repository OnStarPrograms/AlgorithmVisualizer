#include "Handler.h"

Handler::Handler() { ; };

bool Handler::AddNode() {
  sf::Vector2f tempvec;

  tempvec.x = tools.mousevec.x;
  tempvec.y = tools.mousevec.y;
  TempNode = Node(tempvec);
  Nodes.push_back(TempNode);  
  return 0;
};

void Handler::SetNode(){
  sf::Vector2f tempvec;

  tempvec.x = tools.mousevec.x;
  tempvec.y = tools.mousevec.y;
  TempNode.setX_Y(tempvec);
};

void Handler::FinishNode()
{
    TempNode.active = 0;
    Nodes.pop_back();
};

bool Handler::SetUnconnectedConnection(Node fir_node, sf::Vector2f Mouser) {
  return 0;
};

bool Handler::SetConnectedConnection(Connection Connector, Node sec_node) {
  return 0;
};
