#ifndef EDGE_H
#define EDGE_H

#include <utility>

template <typename G>
class Edge {
public:
    using E = typename G::typeE;
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
	// And the edge list of the second conected node:
	auto& eList2 = e->conNodes.second->edgeList;
	fnd = eList2.begin();
	while(*fnd != e)
	    fnd++;
	eList2.erase(fnd);
	// TODO: convert the conected nodes to nullptr ??
    }
    
public:
    E value;
    std::pair<node*,node*> conNodes;
    bool dir; // 0: [0] <-> [1] ; 1: [0] -> [1]

    Edge(E val, node* nodeA, node* nodeB) {
	value = val;
	conNodes = {nodeA, nodeB};
    }
    
    ~Edge() {
	removeCon(this);		
    }
};

#endif //EDGE_H
