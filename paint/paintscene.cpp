#include "paintscene.h"
#include "square.h"
#include "romb.h"
#include "triangle.h"
#include <QFile>
#include <QTextStream>
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    tempFigure = nullptr;
    m_drawMode = ModeDraw;
    m_typeFigure = SquareType;
}

paintScene::~paintScene()
{

}

void paintScene::setPenColor(const QColor &color)
{
    penColor = color;
    setDrawMode(ModeDraw); // Switch to draw mode when color is selected
}

int paintScene::typeFigure() const
{
    return m_typeFigure;
}

void paintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
    setDrawMode(ModeFigure); // Switch to figure mode when figure is selected
}

void paintScene::setDrawMode(DrawMode mode)
{
    m_drawMode = mode;
}

paintScene::DrawMode paintScene::drawMode() const
{
    return m_drawMode;
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_drawMode == ModeDraw) {
        // При нажатии кнопки мыши отрисовываем эллипс
        addEllipse(event->scenePos().x() - 5,
                   event->scenePos().y() - 5,
                   10,
                   10,
                   QPen(Qt::NoPen),
                   QBrush(penColor)); // Use the current pen color
        // Сохраняем координаты точки нажатия
        previousPoint = event->scenePos();
    } else if (m_drawMode == ModeFigure) {
        if (tempFigure) {
            removeItem(tempFigure);
            delete tempFigure;
            tempFigure = nullptr;
        }
        switch (m_typeFigure) {
        case SquareType:
            tempFigure = new Square(event->scenePos());
            break;
        case RombType:
            tempFigure = new Romb(event->scenePos());
            break;
        case TriangleType:
            tempFigure = new Triangle(event->scenePos());
            break;
        }
        if (tempFigure) {
            tempFigure->setStartPoint(event->scenePos());
            tempFigure->setEndPoint(event->scenePos());
            tempFigure->setPenColor(penColor);
            addItem(tempFigure);

        }
    }
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_drawMode == ModeDraw) {
        // Отрисовываем линии с использованием предыдущей координаты
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(penColor, 10, Qt::SolidLine, Qt::RoundCap)); // Use the current pen color
        // Обновляем данные о предыдущей координате
        previousPoint = event->scenePos();
    } else if (m_drawMode == ModeFigure && tempFigure) {
        tempFigure->setEndPoint(event->scenePos());

    }
}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_drawMode == ModeFigure && tempFigure) {
        tempFigure->setEndPoint(event->scenePos());
        Figures.push_back(tempFigure);
        tempFigure = nullptr;
    }
}




void paintScene::saveToFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (Figure *figure : Figures) {
            out << figure->metaObject()->className() << " "
                << figure->startPoint().x() << " " << figure->startPoint().y() << " "
                << figure->endPoint().x() << " " << figure->endPoint().y() << " "
                << figure->WhatCa().name() << "\n";
        }
        file.close();
    }
}

void paintScene::loadFromFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        clear(); // Clear the scene before loading
        Figures.clear(); // Clear the vector of figures
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ");
            if (parts.size() == 6) {
                QString type = parts[0];
                QPointF startPoint(parts[1].toDouble(), parts[2].toDouble());
                QPointF endPoint(parts[3].toDouble(), parts[4].toDouble());
                QColor color(parts[5]);

                Figure *figure = nullptr;
                if (type == "Square") {
                    figure = new Square(startPoint);
                } else if (type == "Romb") {
                    figure = new Romb(startPoint);
                } else if (type == "Triangle") {
                    figure = new Triangle(startPoint);
                }

                if (figure) {
                    figure->setStartPoint(startPoint);
                    figure->setEndPoint(endPoint);
                    figure->setPenColor(color);
                    addItem(figure);
                    Figures.push_back(figure);
                }
            }
        }
        file.close();
    }
}

