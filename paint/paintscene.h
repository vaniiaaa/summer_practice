#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

#include "figure.h"

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();

    void setPenColor(const QColor &color);

    int typeFigure() const;                 // Возвращение текущего типа
    void setTypeFigure(const int type);     // Установка текущего типа
    void saveToFile(const QString &filePath); // Save figures to file
    void loadFromFile(const QString &filePath); // Load figures from file

    enum FigureTypes
    {
        SquareType,
        RombType,
        TriangleType
    };

    enum DrawMode
    {
        ModeDraw,
        ModeFigure
    };

    void setDrawMode(DrawMode mode);
    DrawMode drawMode() const;

signals:

    void typeFigureChanged();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    QColor penColor = Qt::red; // Default color is red

    Figure *tempFigure;
    int m_typeFigure;
    DrawMode m_drawMode = ModeDraw;
    QVector<Figure*> Figures;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event); // Add release event for figures
};

#endif // PAINTSCENE_H
