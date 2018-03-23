#ifndef NODE_H
#define NODE_H

#include <deque>

class GraphicNode;


template <typename G>
class Node {
private:
public:
    using node = typename G::node;
    using edge = typename G::edge;
    using typeN = typename G::typeN;

    typeN value;
    std::deque<edge*> edgeList;

    // Connects this part with the graphics part:
    GraphicNode* graphics;

    //This is used to find the shortest path:
    typename G::PathFindData* pathData;

    // TODO: copy constructor
    // TODO: overlodad operator =

    Node() = default;

    Node(typeN v) {
        value = v;

        graphics = nullptr;
        pathData = nullptr;
    }

    ~Node() {
        // The edge destructor is in charge of removing the edge ptr
        // contained in the edgeList...
        while (!edgeList.empty())
            delete edgeList.front();
    }
};

#endif //NODE_H
