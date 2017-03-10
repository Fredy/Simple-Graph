#ifndef GRAPHICNODE_H
#define GRAPHICNODE_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <deque>
#include "../coordGraph/coordGraph.h"
#include "graphicEdge.h"

class GraphicNode : public QGraphicsEllipseItem {
private:
    CoordGraph::node* data;
    std::deque<GraphicEdge*> edgeList;

public:
    enum { Type = UserType + 4};
    int type() const override { return Type; }

    GraphicNode(CoordGraph::node* data, qreal radius, QGraphicsItem *parent = 0);
// Custom Destructor is not necessary:
// The Coord Graph deletes all the basic nodes when is needed.
// This can't do that because is necessary to remove the nodes
// from the node list in the graph.

    void setColor(const QColor& color) { this->setBrush(color); }

};

#endif //GRAPHICNODE_H
