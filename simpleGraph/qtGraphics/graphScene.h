#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>

class CoordGraph;

class GraphScene : public QGraphicsScene {
    Q_OBJECT
private:
    CoordGraph* graph;
public:
    explicit GraphScene(QObject* parent = 0);

    void showGraph();
    void randomizeGraph(int nodesN, int edgesN, double distance, double limitA, double limitB);
};


#endif //GRAPHSCENE_H
