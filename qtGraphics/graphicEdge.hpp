#pragma once

#include "coordGraph/coordGraph.hpp"
#include <QGraphicsLineItem>

class GraphicEdge : public QGraphicsLineItem {
private:
  CoordGraph::edge *data;

public:
  enum { Type = UserType + 5 };
  int type() const override { return Type; }

  GraphicEdge(CoordGraph::edge *data, QGraphicsItem *parent = 0);

  void setColor(const QColor &color);

  CoordGraph::edge *getData() { return data; }
};
