#ifndef COORDGRAPH_H
#define GRAPH_H

#include <deque>
#include <random>
#include <utility>
#include <QPointF>
#include "../graph/graph.h"

class CoordGraph : public Graph<QPointF, double> {
private:

    deque<QPointF> randomGenNodes(int nodesN, double limitA, double limitB) {
	std::random_device seed;  
	std::mt19937 gen(seed());
	std::uniform_real_distribution<double> disA(limitA, limitB), disB(limitA,limitB);

	deque<QPointF> nodes(nodesN);
	for (auto& i : nodes)
	    i = {disA(gen), disB(gen)};
	
	return nodes;
    }

public:


    void randomGeneration(int nodesN, int edgesN, double limitA, double limitB) {
	if(!nodeList.empty()){
	    this->clear();
	}
	nodeList = randomGenNodes(nodesN, limitA, limitB);
	// TODO: rangomGenEdges
    }

    //TODO : removNodeRange : passing 2 QPointF or passing 2 x, y (doubles)
    void removeNodeRange() {
	
    }

    
};



#endif //COORDGRAPH_H
