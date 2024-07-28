#include "Connection.h"
#include "Node.h"
#include "ToolBox.h"
#include <vector>

class Handler {
private:
  ToolBox &tools = ToolBox::getInstance();
  // Stores all the nodes made
  std::vector<Node> Nodes;
  Node TempNode;
  Node *SelectedNode = nullptr;
  // Stores all the Connections
  std::vector<Connection> Connections;
  Connection *ActiveConnection;
  int uncconnected = 0;

public:
  Handler();
  bool AddNode();

  void SetNode();

  void FinishNode();
  std::vector<Node *> GetNotConnectedNode();

  Node *GetConnectedNode();
  void PreMatureNode() { SelectedNode = nullptr; };
  bool IsActive() {
    if (TempNode.isactive() == 1) {
      return true;
    }
    return false;
  };
  // make a sf::RederSquare and store all info in node
  bool SetUnconnectedConnection(Node *fir_node);

  void UpdateConnection() { if(ActiveConnection!= nullptr){ActiveConnection->UpdateConnection();} };
  // make a sf::RenderSquare and store all info in Connection
  bool SetConnectedConnection(Node *sec_node);
  bool SetConnectedConnection(Node *fir_node, Node *sec_node);
  void DrawHandles() {
    for (int i = 0; i < Nodes.size(); i++) {
      tools.CircStack.push(*Nodes[i].GetDrawable());
    }
    for (int i = 0; i < Connections.size(); i++) {
      tools.RectStack.push(*Connections[i].GetDrawable());
    }
  };
};
