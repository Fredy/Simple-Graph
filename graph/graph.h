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
    void insertNode(typeN val) {
	nodeList.push_back(new node(val));
    }
    
    void insertEdge(typeE val, node* nodeA, node* nodeB, bool dir = 0) {
	edge* tmp = new edge(val, nodeA, nodeB, dir);
	nodeA->edgeList.push_back(tmp);
	if (nodeA != nodeB) // If the edge is a loop we don't have to push it again
	    nodeB->edgeList.push_back(tmp);
    }
    
    void removeNode(node* remv) {
	auto fnd = nodeList.begin();
	while (*fnd != remv)
	    fnd++;
	delete *fnd;
	nodeList.erase(fnd);
    }
    
    void removeNode(typename std::deque<node*>::iterator iterator) {
	delete *iterator;
	nodeList.erase(iterator);
    }

    // Remove all the edges between two nodes:
    void removeEdgesBtwn(node* nodeA, node* nodeB) {
	std::deque<edge*> toremove;
	for (edge* i : nodeA->edgeList) {
	    auto& first = i->conNodes.first;
	    auto& second = i->conNodes.second;
	       
	    if ((first == nodeA and second == nodeB) or
		(first == nodeB and second == nodeA))
		toremove.push_back(i);
	}
	for (edge* i : toremove)
	    delete i;
    }
    
    void removeEdge(edge* remv) {
	delete remv;
    }
    
};

#endif //GRAPH_H
