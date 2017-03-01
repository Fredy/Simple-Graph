#include <QApplication>

#include <QPushButton>
#include <QFont>
#include <QIcon>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "coordGraph/coordGraph.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget window;
    QGraphicsView view(&window);
    QGraphicsScene* scene = new QGraphicsScene(&window) ;
    CoordGraph graph;
    graph.randomGeneration(50, 44, 3, 500);

    const auto& v = graph.getNodeList();

    for (const auto& i : v) {
        scene->addEllipse(i->value.x(), i->value.y(), 3, 3, QPen(Qt::black));
        for (const auto& j : i->edgeList) {
            scene->addLine(j->conNodes.first->value.x(), j->conNodes.first->value.y(), j->conNodes.second->value.x(), j->conNodes.second->value.y());
        }
    }

    view.setScene(scene);
    window.show();
    return app.exec();
}
