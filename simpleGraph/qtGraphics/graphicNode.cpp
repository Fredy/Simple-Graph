#include "graphicNode.h"
#include <QPen>
#include <QPainter>

GraphicNode::GraphicNode(CoordGraph::node* data, qreal radius, QGraphicsItem* parent)
    : QGraphicsEllipseItem(data->value.x() - radius, data->value.y() - radius,
                           radius * 2, radius * 2,  parent) {
    this->data = data;
    this->setPen(QPen(Qt::black, 1));
    this->setBrush(Qt::red); // TODO: find a good color;
}
