#ifndef GRAPH_H
#define GRAPH_H

#include <deque>
#include "node.h"
#include "edge.h"

template <typename N, typename E>
class Graph {
public:
    using self = Graph<N, E>;
    using typeN = N;
    using typeE = E;
    using node = Node<self>;
    using edge = Edge<self>;

protected:
    std::deque<node*> nodeList;

public:
    const std::deque<node*>& getNodeList();

    void insertNode(typeN val);
    void insertEdge(typeE val, node* nodeA, node* nodeB, bool dir = 0);
    void removeNode(node* remv);

    typename std::deque<node*>::iterator
    removeNode(typename std::deque<node*>::iterator iterator);

    // Remove all the edges between two nodes:
    void removeEdgesBtwn(node* nodeA, node* nodeB);
    void removeEdge(edge* remv);

    void clear();
    ~Graph();
};

#endif //GRAPH_H
