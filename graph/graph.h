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
    void insertNode() {
	
    }
    void insertEdge() {
	
    }
    void removeNode() {
	
    }
    void removeEdge() {
	
    }
    
};

#endif //GRAPH_H
