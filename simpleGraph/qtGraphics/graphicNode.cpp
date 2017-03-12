#include <QBrush>
#include <QGraphicsScene>
#include "graphicNode.h"
#include "graphicEdge.h"

GraphicNode::GraphicNode(CoordGraph::node* data, qreal radius, QGraphicsItem* parent)
    : QGraphicsEllipseItem(data->value.x() - radius, data->value.y() - radius,
                           radius * 2, radius * 2,  parent) {
    this->data = data;
    this->setPen(QPen(Qt::black, 1));
    this->setBrush(Qt::red); // TODO: find a good color;
}

bool GraphicNode::removeEdges() {
    for (auto& i : data->edgeList) {
        if (i->graphics != nullptr) {
            scene()->removeItem(i->graphics);
            delete i->graphics;
            i->graphics = nullptr;
        }
    }
    return true;
}

void GraphicNode::setColor(const QColor &color) {
    this->setBrush(color);
}
