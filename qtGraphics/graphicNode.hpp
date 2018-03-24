#pragma once

#include "coordGraph/coordGraph.hpp"
#include <QGraphicsEllipseItem>

class GraphicNode : public QGraphicsEllipseItem {
private:
  CoordGraph::node *data;

public:
  enum { Type = UserType + 4 };
  int type() const override { return Type; }

  GraphicNode(CoordGraph::node *data, qreal radius, QGraphicsItem *parent = 0);
  // Custom Destructor is not necessary:
  // The Coord Graph deletes all the basic nodes when is needed.
  // This can't do that because is necessary to remove the nodes
  // from the node list in the graph.

  void setColor(const QColor &color);

  void removeEdges();

  CoordGraph::node *getData() { return data; }
};
