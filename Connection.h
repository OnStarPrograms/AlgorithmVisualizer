#include "ToolBox.h"

class Connection
{
    std::vector<sf::RectangleShape*> Shaper;
    Node* ConnectedNode1;
    Node* ConnectedNode2;
    int numOfData = 0;
    int max = 0;
    public:
        Connection(Node* node1)
        {
            Shaper.push_back(new sf::RectangleShape(sf::Vector2f(30., 30.)));
            max++;
            numOfData = max;
            ConnectedNode1 = node1;
        }
        int getNum()
        {
            return numOfData;
        }
        sf::RectangleShape* GetDrawable()
        {
            numOfData--;
            return Shaper[numOfData];
        };
};