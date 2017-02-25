#include <iostream>
#include "../graph/graph.h"
using namespace std;

int main() {
    using graph = Graph<int, char>;
    using node = Node<graph>;
    using edge = Edge<graph>;
    node *x = new node(1),
	*y = new node(2),
	*z = new node(3),
	*w = new node(4);
    
    edge *a = new edge('a', x, z),
	*b = new edge('b',x, y),
	*c = new edge('c', x, w);

    x->edgeList.push_back(a);
    x->edgeList.push_back(b);
    x->edgeList.push_back(c);
    z->edgeList.push_back(a);
    y->edgeList.push_back(b);
    w->edgeList.push_back(c);
    
    auto print = [&] (node *n) {
	cout << "Node: " << n->value << endl;
	for (const auto& i : n->edgeList)
	    cout << i->value << " ";
	cout << endl;
    };
    
    auto printAll = [&] () {
	print(x);
	print(y);
	print(z);
	print(w);
	cout << "----" << endl;
    };
    
    printAll();
    
    delete b;

    printAll();
    
    delete a;
    delete c;

    printAll();
}
