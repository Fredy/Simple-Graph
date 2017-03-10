#include "graphicEdge.h"

GraphicEdge::GraphicEdge(CoordGraph::edge* data, QGraphicsItem * parent)
    : QGraphicsLineItem(QLineF(data->conNodes.first->value,
                               data->conNodes.second->value), parent) {
    this->data = data;
}
