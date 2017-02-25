QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simple-Graph
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++14

SOURCES += \  
    tests/graphInsertDelete.cpp \
    tests/nodesEdges.cpp

HEADERS += \
    graph/edge.h \
    graph/graph.h \
    graph/node.h

# FORMS += 
