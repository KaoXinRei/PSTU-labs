#include "mygraphicsscene.h"

myGraphicsScene::myGraphicsScene(QObject *parent) : QGraphicsScene(parent){
    pen = new QPen(Qt::black);
    brush = new QBrush(Qt::blue);
    choosing_cities = false;
}

void myGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::update();
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void myGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::mousePressEvent(mouseEvent);
    QGraphicsScene::update();
}

void myGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
