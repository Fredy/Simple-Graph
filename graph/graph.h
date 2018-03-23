#ifndef GRAPH_H
#define GRAPH_H

#include <deque>
#include <utility>
#include <algorithm>
#include "node.h"
#include "edge.h"

template <typename N, typename E>
class Graph {
public:
    using self = Graph<N, E>;
    using typeN = N;
    using typeE = E;
    using node = Node<self>;
    using edge = Edge<self>;

    struct PathFindData {
        double accDist;
        bool done;
        edge* prev;
        PathFindData(double dist, edge* prev) {
            this->accDist = dist;
            this->prev = prev;
        }
    };

protected:
    std::deque<node*> nodeList;

public:
    void insertNode(typeN val) {
        nodeList.push_back(new node(val));
    }

    void insertEdge(typeE val, node* nodeA, node* nodeB, bool dir = 0) {
        edge* tmp = new edge(val, nodeA, nodeB, dir);
        nodeA->edgeList.push_back(tmp);
        if (nodeA != nodeB) // If the edge is a loop we don't have to push it again
            nodeB->edgeList.push_back(tmp);
    }

    void removeNode(node* remv) {
        auto fnd = nodeList.begin();
        while (*fnd != remv)
            fnd++;
        delete *fnd;
        nodeList.erase(fnd);
    }

    typename std::deque<node*>::iterator
    removeNode(typename std::deque<node*>::iterator iterator) {
        delete *iterator;
        return nodeList.erase(iterator);
    }

    // Remove all the edges between two nodes:
    void removeEdgesBtwn(node* nodeA, node* nodeB) {
        std::deque<edge*> toremove;
        for (edge* i : nodeA->edgeList) {
            auto& first = i->conNodes.first;
            auto& second = i->conNodes.second;

            if ((first == nodeA and second == nodeB) or
                    (first == nodeB and second == nodeA))
                toremove.push_back(i);
        }
        for (edge* i : toremove)
            delete i;
    }

    void removeEdge(edge* remv) {
        delete remv;
    }

    const std::deque<node*>& getNodeList() {
        return nodeList;
    }

    void clear() {
        while(!nodeList.empty()){
            delete nodeList.back();
            nodeList.pop_back();
        }
    }

    std::pair<double,std::deque<edge*> >
    minPathDijkstra(node* start, node* end) {

        std::deque<node*> queue;
        start->pathData = new PathFindData(0.0, nullptr);
        queue.push_back(start);

        while(!queue.empty()) {
            node* crtNode = queue.front();
            for (const auto& iedge : crtNode->edgeList) {
                node* otherNode = iedge->otherNode(crtNode);
                double dist = crtNode->pathData->accDist + iedge->value;
                if (otherNode->pathData == nullptr) {
                    otherNode->pathData = new PathFindData(dist, iedge);
                    auto pos = std::upper_bound(queue.begin(), queue.end(), otherNode, [](auto a, auto b) {
                            return a->pathData->accDist < b->pathData->accDist;
                        });
                    queue.insert(pos, otherNode);

                }
                else {
                    if (dist < otherNode->pathData->accDist) {
                        node* tmp = new node();
                        tmp->pathData = new PathFindData(dist, nullptr);

                        auto pos = std::upper_bound(queue.begin(), queue.end(), tmp, [](auto a, auto b) {
                                return a->pathData->accDist < b->pathData->accDist;
                            });
                        auto actPos = std::find(queue.begin(), queue.end(), otherNode); // TODO: replace queue.begin() with pos
                        std::rotate(pos, actPos, actPos + 1); // TODO: use reverse iterator

                        otherNode->pathData->accDist = dist;
                        otherNode->pathData->prev = iedge;

                        delete tmp->pathData;
                        delete tmp;
                    }
                }
            }
            queue.pop_front();
        }
        std::deque<edge*> edgePath;
        double pathLenght = 0.0;
        if (end->pathData) {
            pathLenght = end->pathData->accDist;
            node* actNode = end;
            while (actNode != start) {
                edgePath.push_back(actNode->pathData->prev);
                actNode = actNode->pathData->prev->otherNode(actNode);
            }
            for (const auto& i : nodeList) {
                if (i->pathData) {
                    delete i->pathData;
                    i->pathData = nullptr;
                }
            }
        }
        return {pathLenght, edgePath};
    }

    ~Graph() {
        this->clear();
    }
};

#endif //GRAPH_H
