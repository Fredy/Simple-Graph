#ifndef GRAPHICEDGE_H
#define GRAPHICEDGE_H

#include "../coordGraph/coordGraph.h"

class GraphicEdge {
private:
    CoordGraph::edge* data;
public:
    GraphicEdge(CoordGraph::edge* data);
};

#endif //GRAPHICEDGE_H
