#include <random>
#include <utility>
#include <algorithm>
#include <cmath>
#include "coordGraph.h"

std::deque<CoordGraph::node*>
CoordGraph::randomGenNodes(int nodesN, double limitA, double limitB) {
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_real_distribution<double> disA(limitA, limitB), disB(limitA,limitB);

    std::deque<node*> nodes(nodesN);
    for (auto& i : nodes)
        i =new node({disA(gen), disB(gen)});

    return nodes;
}

//TODO: Check if is better to make this with the QpointF converted to Qpoint
void CoordGraph::sortNodes() {
    std::sort(nodeList.begin(), nodeList.end(), [](node* a, node* b){
            if (a->value.y() < b->value.y())
                return true;
            else if (a->value.y() > b->value.y())
                return false;
            else
                return a->value.x() < b->value.x();
        });
}

// d = sqrt((x1 - x2)² +(y1 - y2)²)
double CoordGraph::distance(node* a, node* b) {
    double x = a->value.x() - b->value.x();
    double y = a->value.y() - b->value.y();
    return sqrt(x * x + y * y);
}

void CoordGraph::randomGenEdges(unsigned int maxEdges, double distance) {
    for (auto i = nodeList.begin(); i < nodeList.end(); i++) {
        for (auto j = i + 1; j < nodeList.end(); j++) {
            if ((*i)->edgeList.size() >= maxEdges)
                break;
            double dist = this->distance(*i, *j);
            if (dist <= distance)
                insertEdge(dist, *i, *j); // TODO: randomize the direction
        }
    }
}

void CoordGraph::randomGeneration(int nodesN, int edgesN, double distance, double limitA, double limitB) {
    if(!nodeList.empty()){
        this->clear();
    }
    nodeList = randomGenNodes(nodesN, limitA, limitB);
    sortNodes();
    randomGenEdges(edgesN, distance); // TODO: find a good distance
}

void CoordGraph::removeNodeRange(QPointF first, QPointF last) {
    for (auto i = nodeList.begin(); i < nodeList.end();) {
        if ((*i)->value.x() >= first.x() and (*i)->value.x() <= last.x() and
            (*i)->value.y() >= first.y() and (*i)->value.y() <= last.y())
            i = this->removeNode(i);
        else
            i++;
    }
}
