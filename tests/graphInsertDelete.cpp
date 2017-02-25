#include <iostream>
#include "../graph/graph.h"
using namespace std;

class GraphTest : public Graph<int, char> {
public:
//    auto& refNodeList = this-nodeList;
    void printGraph() {
	for (const auto& i : nodeList) {
	    cout << "Node: " << i->value << endl;
	    for (const auto& j : i->edgeList) {
		cout << j->value << " ";
	    }
	    cout << endl;
	}
	cout << "---------" << endl;
    }
    deque<node*>& getNodeList() {
	return nodeList;
    }
};


int main() {
    //Graph<int, char> graph;
    //graph.insertNode(1);
    GraphTest graph;
    auto& nodes = graph.getNodeList();
    int n = 10;
    for (int i = 0; i < n; i++)
	graph.insertNode(i);

    int j = 0;
    for(auto i = nodes.begin(); i < nodes.end() - 1; i++) {
	graph.insertEdge('a' + j, *i, *(i + 1));
	j++;
    }
    graph.insertEdge('a' + j, nodes.back(), nodes.front(), 1);
    graph.printGraph();

    cout << "Node removed: " << nodes.front()->value << endl;
    graph.removeNode(nodes.begin());
    graph.printGraph();

    cout << "Node removed: " << nodes[4]->value << endl;
    graph.removeNode(nodes[4]);
    graph.printGraph();

    cout << "Edges removed: beetween " << nodes[5]->value << " and " << nodes[6]->value << endl;
    graph.removeEdgesBtwn(nodes[5], nodes[6]);
    graph.printGraph();

    cout << "Edge removed: c" << endl;
    
    graph.removeEdge(nodes[1]->edgeList[1]);
    graph.printGraph();

    GraphTest graph2;
    auto& nodes2 = graph2.getNodeList();

    graph2.insertNode(1);
    graph2.insertEdge('a', nodes2.front(), nodes2.front(), 1);

    cout << "Loop edge: " << endl;
    graph2.printGraph();
    graph2.removeEdgesBtwn(nodes2.front(), nodes2.front());
    
    graph2.printGraph();
    
    
    
}
