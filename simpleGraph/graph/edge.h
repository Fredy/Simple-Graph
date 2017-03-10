#ifndef EDGE_H
#define EDGE_H

#include <utility>

class GraphicEdge;

template <typename G>
class Edge {
public:
    using typeE = typename G::typeE;
    using node = typename G::node;
    using edge = typename G::edge;
private:
    void removeCon(Edge* e) {
        // This is the edgeList inside the first conected node:
        auto& eList1 = e->conNodes.first->edgeList;
        auto fnd = eList1.begin();
        while(*fnd != e)
            fnd++;
        eList1.erase(fnd);
        // And this is  the edge list of the second conected node:
        auto& eList2 = e->conNodes.second->edgeList;

        // If the edge is a loop then it was already deleted from the
        // edge list so the function returns;
        if (e->conNodes.first == e->conNodes.second)
            return;

        fnd = eList2.begin();

        while(*fnd != e)
            fnd++;
        eList2.erase(fnd);
        // TODO: convert the conected nodes to nullptr ??
    }

public:
    typeE value;
    std::pair<node*,node*> conNodes;
    bool direction; // 0: [0] <-> [1] ; 1: [0] -> [1]

    // Connects this part with the graphics part:
    GraphicEdge* graphics;
    bool printed;


    // TODO: copy constructor  ???
    // TODO: overlodad operator = ???

    Edge(typeE val, node* nodeA, node* nodeB, bool dir = 0) {
        value = val;
        conNodes = {nodeA, nodeB};
        direction = dir;

        graphics = nullptr;
        printed = false;
    }

    ~Edge() {
        removeCon(this);
    }
};

#endif //EDGE_H
