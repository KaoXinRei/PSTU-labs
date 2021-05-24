#define _USE_MATH_DEFINES
#include "road.h"
#include <cmath>
road::road(city* f, city* s, QGraphicsItem* parent) : QGraphicsItem(parent)
{
    first_city = f;
    second_city = s;
    setFlag(QGraphicsItem::ItemIsFocusable);
    color = Qt::black;
}

road::road(const road& r){
    first_city = r.first_city;
    second_city = r.second_city;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QString road::double_to_str(double in){
    QString result = QString::fromStdString(std::to_string(in));
    double intpart;
    while (result.back() == '0'){
        result.remove(result.length() - 1, 1);
    }
    if (modf(in, &intpart) == 0.0){
        result.remove(result.length() - 1, 1);
    }
    return result;
}

void road::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(color);
    qreal fx = first_city->pos().x() + 25;
    qreal fy = first_city->pos().y() + 25;
    qreal sx = second_city->pos().x() + 25;
    qreal sy = second_city->pos().y() + 25;
    QLineF line = QLineF(fx, fy, sx, sy);
    QLineF vector = line.unitVector();
    vector.setLength(25);
    QPointF point1 = vector.p2();
    vector.setLength(line.length() - 25);
    QPointF point2 = vector.p2();
    painter->drawLine(QLineF(point1, point2));
    vector.setLength(line.length() - 35);
    QLineF arrow_1 = QLineF(point2, vector.p2());
    QLineF arrow_2 = QLineF(point2, vector.p2());
    arrow_1.setAngle(arrow_1.angle() - 25);
    arrow_2.setAngle(arrow_2.angle() + 25);
    painter->drawLine(arrow_1);
    painter->drawLine(arrow_2);
}

QRectF road::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

bool operator== (const road &r1, const road &r2) {
    return r1.first_city == r2.first_city && r1.second_city == r2.second_city;
}

void road::selected_color() {
    color = Qt::red;
}

void road::unselected_color() {
    color = Qt::black;
}


