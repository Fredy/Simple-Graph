#include "graph.h"

inline void
Graph::insertNode(typeN val) {
    nodeList.push_back(new node(val));
}

inline void
Graph::insertEdge(typeE val, node* nodeA, node* nodeB, bool dir = 0) {
    edge* tmp = new edge(val, nodeA, nodeB, dir);
    nodeA->edgeList.push_back(tmp);
    if (nodeA != nodeB) // If the edge is a loop we don't have to push it again
        nodeB->edgeList.push_back(tmp);
}

inline void
Graph::removeNode(node* remv) {
    auto fnd = nodeList.begin();
    while (*fnd != remv)
        fnd++;
    delete *fnd;
    nodeList.erase(fnd);
}

inline typename std::deque<node*>::iterator
Graph::removeNode(typename std::deque<node*>::iterator iterator) {
    delete *iterator;
    return nodeList.erase(iterator);
}

// Remove all the edges between two nodes:
inline void Graph::removeEdgesBtwn(node* nodeA, node* nodeB) {
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

inline void Graph::removeEdge(edge* remv) {
    delete remv;
}

inline const std::deque<node*>&
Graph::getNodeList() {
    return nodeList;
}

inline void Graph::clear() {
    while(!nodeList.empty()){
        delete nodeList.back();
        nodeList.pop_back();
    }
}



inline Graph::~Graph() {
    this->clear();
}
