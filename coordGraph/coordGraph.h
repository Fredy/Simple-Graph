#ifndef COORDGRAPH_H
#define COORDGRAPH_H

#include <deque>
#include <QPointF>
#include "../graph/graph.h"

class CoordGraph : public Graph<QPointF, double> {
private:
    std::deque<node*> randomGenNodes(int nodesN, double limitA, double limitB);
    void sortNodes();
    double distance(node* a, node* b);
    void randomGenEdges(unsigned int maxEdges, double distance);

public:
    void randomGeneration(int nodesN, int edgesN, double distance, double limitA, double limitB);
    void removeNodeRange(QPointF first, QPointF last);
};

#endif //COORDGRAPH_H
