#include "Node.h"
#include "ToolBox.h"
#include "Connection.h"
#include <vector>

class Handler
{
    private:
        ToolBox& tools = ToolBox::getInstance();
        // Stores all the nodes made
        std::vector<Node> Nodes;
        Node TempNode;
        // Stores all the Connections
        std::vector<Connection> Connections;

    public:
        Handler();
        bool AddNode();
        
        void SetNode();
        
        void FinishNode();
        // make a sf::RederSquare and store all info in node
        bool SetUnconnectedConnection(Node fir_node, sf::Vector2f Mouser);

        // make a sf::RenderSquare and store all info in Connection
        bool SetConnectedConnection(Connection Connector, Node sec_node);
        void DrawHandles()
        {
            for (int i = 0; i < Nodes.size(); i++)
            {
                tools.CircStack.push(*Nodes[i].GetDrawable());
                tools.CircStack.push(*TempNode.GetDrawable());
            }
            for (int i = 0; i < Connections.size(); i++)
            {
                while(Connections[i].getNum() != 0)
                {
                    tools.RectStack.push(*Connections[i].GetDrawable());
                }
            }
        };
};
