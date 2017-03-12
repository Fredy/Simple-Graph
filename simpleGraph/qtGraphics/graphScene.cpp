#include <QGraphicsSceneMouseEvent>
#include "graphScene.h"
#include "../coordGraph/coordGraph.h"
#include "graphicNode.h"
#include "graphicEdge.h"

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent) {
    graph = new CoordGraph();
    selectRect = nullptr;
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

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (mouseEvent->button() == Qt::LeftButton) {

    }
    else if (mouseEvent->button() == Qt::RightButton) {
        selectFirstPoint = mouseEvent->scenePos();
        selectRect = new QGraphicsRectItem(QRectF(selectFirstPoint, selectFirstPoint));
        selectRect->setPen(QPen(Qt::black, 1, Qt::DashLine));
        this->addItem(selectRect);
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    // TODO: When modes are implemented, comprobe the mode
    if (selectRect != nullptr) {
        QPointF a = selectFirstPoint, b = mouseEvent->scenePos();
        QRectF tmpRect;

        if (a.x() <= b.x()) {
            if (a.y() <= b.y())
                tmpRect = QRectF(a, b);
            else {
                a.setX(b.x());
                b.setX(selectFirstPoint.x());
                tmpRect = QRectF(b, a);
            }
        }
        else {
            if (a.y() > b.y())
                tmpRect = QRectF(b, a);
            else {
                a.setX(b.x());
                b.setX(selectFirstPoint.x());
                tmpRect = QRectF(a, b);
            }
        }
        selectRect->setRect(tmpRect);
    }
    else
        QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (selectRect != nullptr and mouseEvent->button() == Qt::RightButton) {
        this->removeItem(selectRect);
        delete selectRect;
        selectRect = nullptr;
        // TODO: Delete portion delimited by the selectRect
    }
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
