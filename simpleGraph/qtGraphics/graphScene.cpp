#include "graphScene.h"
#include "../coordGraph/coordGraph.h"
#include "graphicNode.h"
#include "graphicEdge.h"

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent) {
    graph = new CoordGraph();
}

void GraphScene::showGraph() {
    const auto& v = graph->getNodeList();

    for (const auto& i : v) {
        GraphicNode* node = new GraphicNode(i, 3);
        this->addItem(node);
        for (const auto& j : i->edgeList) {
            if (!j->printed) {
                j->printed = true;
                GraphicEdge* edge = new GraphicEdge(j);
                this->addItem(edge);
            }
        }
    }
}

void GraphScene::randomizeGraph(int nodesN, int edgesN, double distance, double limitA, double limitB) {
    if (this->items().count())
        this->clear();

    graph->randomGeneration(nodesN, edgesN, distance, limitA, limitB);
    this->showGraph();

}
