#include "Connection.h"
#include "Node.h"
#include "ToolBox.h"
#include <vector>

class Handler {
private:
  ToolBox &tools = ToolBox::getInstance();
  // Stores all the nodes made
  std::vector<Node *> Nodes;
  Node *TempNode = new Node();
  Node *SelectedNode = nullptr;
  // Stores all the Connections
  std::vector<Connection *> Connections;
  Connection *ActiveConnection;
  int uncconnected = 0;

public:
  Handler();
  bool AddNode();

  void SetNode();

  void FinishNode();
  std::vector<Node *> GetNotConnectedNode();

  void AutoConnectNodes();

  Node *GetConnectedNode();
  void PreMatureNode();
  bool IsNodeSetActive();
  bool IsConnectionSetActive();
  // make a sf::RederSquare and store all info in node
  bool SetUnconnectedConnection(Node *fir_node);

  void UpdateConnection();
  // make a sf::RenderSquare and store all info in Connection
  bool SetConnectedConnection(Node *sec_node);
  bool SetConnectedConnection(Node *fir_node, Node *sec_node);
  void DrawHandles();
  bool CleanConnections();
};
