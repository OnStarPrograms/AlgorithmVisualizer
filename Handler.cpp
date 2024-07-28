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

void Handler::SetNode() {
  sf::Vector2f tempvec;

  tempvec.x = tools.mousevec.x;
  tempvec.y = tools.mousevec.y;
  TempNode.setX_Y(tempvec);
};

void Handler::FinishNode() {
  TempNode.active = 0;
  Nodes.pop_back();
};

std::vector<Node *> Handler::GetNotConnectedNode() {
  std::vector<Node *> NoNodes;
  for (int i = 0; i < Nodes.size(); i++) {
    float Myx = Nodes[i].getX();
    float Myy = Nodes[i].getY();
    if (Myx - 30. <= tools.mousevec.x && Myx + 30. >= tools.mousevec.x &&
        Myy - 30. <= tools.mousevec.y && Myy + 30. >= tools.mousevec.y) {
      ;
    } else {
      NoNodes.push_back(&Nodes[i]);
    }
  }
  return NoNodes;
};

Node *Handler::GetConnectedNode() {
  for (int i = 0; i < Nodes.size(); i++) {
    float Myx = Nodes[i].getX();
    float Myy = Nodes[i].getY();
    if (Myx - 30. <= tools.mousevec.x && Myx + 30. >= tools.mousevec.x &&
        Myy - 30. <= tools.mousevec.y && Myy + 30. >= tools.mousevec.y) {
      return &Nodes[i];
    }
  }
  return nullptr;
};

bool Handler::SetUnconnectedConnection(Node* fir_node) {
  SelectedNode = fir_node;
  ActiveConnection = new Connection(fir_node);
  Connections.push_back(*ActiveConnection);
  return 0;
};

bool Handler::SetConnectedConnection(Node *sec_node) {
  if (SelectedNode != nullptr) {
    SelectedNode->addConnectedNode(sec_node);
    sec_node->addConnectedNode(SelectedNode);
    SelectedNode = nullptr;
    ActiveConnection->EndConnection(sec_node);
  }
  return 0;
};

bool Handler::SetConnectedConnection(Node* fir_node, Node* sec_node) {
  fir_node->addConnectedNode(sec_node);
  sec_node->addConnectedNode(fir_node);
  return 0;
};
