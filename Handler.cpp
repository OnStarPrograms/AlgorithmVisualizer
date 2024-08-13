#include "Handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

Handler::Handler() { ; };

bool Handler::AddNode() {
  sf::Vector2f tempvec;

  tempvec.x = tools.mousevec.x;
  tempvec.y = tools.mousevec.y;
  TempNode = new Node(tempvec);
  Nodes.push_back(TempNode);
  return 0;
};

void Handler::SetNode() {
  sf::Vector2f tempvec;

  tempvec.x = tools.mousevec.x;
  tempvec.y = tools.mousevec.y;
  TempNode->setX_Y(tempvec);
};

void Handler::FinishNode() {
  TempNode->active = 0;
  Nodes.pop_back();
};

void Handler::AutoConnectNodes() {
  std::vector<Node *> noders = GetNotConnectedNode();
  if (noders.size() > 1) {
    srand(time(NULL));
    int iSecret;
    for (int i = 0; i < noders.size(); i++) {

      iSecret = rand() % noders.size();
      SetUnconnectedConnection(noders[i]);
      while (iSecret == i)
        iSecret = rand() % noders.size();

      SetConnectedConnection(noders[iSecret]);
    }
    for (int i = 0; i < noders.size(); i++) {

      iSecret = rand() % noders.size();
      SetUnconnectedConnection(noders[i]);
      while (iSecret == i)
        iSecret = rand() % noders.size();

      SetConnectedConnection(noders[iSecret]);
    }
  }
}
void Handler::PreMatureNode() { SelectedNode = nullptr; };

std::vector<Node *> Handler::GetNotConnectedNode() {
  std::vector<Node *> NoNodes;
  for (int i = 0; i < Nodes.size(); i++) {
    float Myx = Nodes[i]->getX();
    float Myy = Nodes[i]->getY();
    if (Myx - 30. <= tools.mousevec.x && Myx + 30. >= tools.mousevec.x &&
        Myy - 30. <= tools.mousevec.y && Myy + 30. >= tools.mousevec.y) {
      ;
    } else {
      // if (Nodes[i].)
      NoNodes.push_back(Nodes[i]);
    }
  }
  return NoNodes;
};

bool Handler::IsConnectionSetActive() {
  if (SelectedNode != nullptr)
    return true;
  return false;
};

bool Handler::IsNodeSetActive() {
  if (TempNode->isactive() == 1) {
    return true;
  }
  return false;
};

void Handler::UpdateConnection() {
  if (ActiveConnection != nullptr) {
    ActiveConnection->UpdateConnection();
  }
};

void Handler::DrawHandles() {
  for (int i = 0; i < Nodes.size(); i++) {
    tools.CircStack.push(*Nodes[i]->GetDrawable());
    std::vector<Connection *> Connects_ = Nodes[i]->getConnectedConnects();
    for (int i = 0; i < Connects_.size(); i++) {
      tools.RectStack.push(*Connects_[i]->GetDrawable());
      tools.TextStack.push(*Connects_[i]->GetTextDrawable());
      //printf("%i", Connects_[i]->GetWeight());
    }
  }
};

Node *Handler::GetConnectedNode() {
  for (int i = 0; i < Nodes.size(); i++) {
    float Myx = Nodes[i]->getX();
    float Myy = Nodes[i]->getY();
    if (Myx - 30. <= tools.mousevec.x && Myx + 30. >= tools.mousevec.x &&
        Myy - 30. <= tools.mousevec.y && Myy + 30. >= tools.mousevec.y) {
      return Nodes[i];
    }
  }
  return nullptr;
};

bool Handler::SetUnconnectedConnection(Node *fir_node) {
  SelectedNode = fir_node;
  return 0;
};

bool Handler::SetConnectedConnection(Node *sec_node) {
  if (SelectedNode != nullptr) {
    printf("-----\n");

    std::vector<Connection *> Connects = SelectedNode->getConnectedConnects();
    bool trig = 0;
    for (int i = 0; i < Connects.size(); i++) {
      if (Connects[i]->getEndNode() == sec_node && Connects[i]->getStartNode() == SelectedNode) {
        SelectedNode->addWeight(1, Connects[i]);
        trig = 1;
        printf("AntiTrigged");
      };
      if (Connects[i]->getStartNode() == sec_node && Connects[i]->getEndNode() == SelectedNode) { 
        sec_node->addWeight(1, Connects[i]);
        trig = 1;
      };
      //if (Connects[i]->getEndNode() == ) {
        //SelectedNode->addWeight(1, Connects[i]);
        //trig = 1;
      //};
    };
    if (trig != 1) {
      printf("Trigged");
      ActiveConnection = new Connection(SelectedNode);
      SelectedNode->addConnectionBlock(ActiveConnection);
      sec_node->addConnectionBlock(ActiveConnection);
      SelectedNode->addConnectedNode(sec_node);
      sec_node->addConnectedNode(SelectedNode);
      ActiveConnection->EndConnection(sec_node);
    }

    SelectedNode = nullptr;
  }
  return 0;
};

bool Handler::SetConnectedConnection(Node *fir_node, Node *sec_node) {
  fir_node->addConnectedNode(sec_node);
  sec_node->addConnectedNode(fir_node);
  return 0;
};

bool Handler::CleanConnections() {
  int i = 0;
  int j = 0;
  for (auto it : Nodes) {
    while (i < it->getConnectedConnects().size()) {
      while (j < it->getConnectedConnects().size()) {
        if (it->getConnectedConnects()[i]->getEndNode()->getX() ==
                it->getConnectedConnects()[j]->getEndNode()->getX() &&
            i != j) {
          it->getConnectedConnects()[i] +=
              it->getConnectedConnects()[j]->GetWeight();
          Connections.erase(Connections.begin() + j);
          printf("%i", it->getConnectedConnects()[i]->GetWeight());
          j--;
          i--;
        }
        j++;
        i++;
      }
    }
    j = 0;
    i = 0;
  }

  return 0;
};
