#include "../coordGraph/coordGraph.h"
#include <iostream>
using namespace std;

class GraphTest : public CoordGraph {
public:
    deque<node*>& getNodeList() {
	return nodeList;
    }
};

int main() {
    GraphTest graph;
    graph.randomGeneration(10, 10, 0, 10);
    auto& nodes = graph.getNodeList();
    auto print = [&]() {
	for(const auto& i : nodes) {
	    auto& val = i->value;
	    cout << val.x() << " " << val.y() << endl;
	}
	cout << "----" << endl;
    };
    print();
    graph.clear();
    print();
    graph.randomGeneration(10, 10, 0, 10);
    print();
    graph.randomGeneration(10, 10, 0, 10);
    print();
}
