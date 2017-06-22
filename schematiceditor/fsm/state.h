#ifndef STATE_H
#define STATE_H

#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include "schematiceditor.h"
#include "schematicscene.h"
#include <QMenu>

class State : public QObject
{
public:
    State(QObject* parent = nullptr);

    SchematicScene* schScene;
    bool isDrawing;

    QPointF firstMousePressScenePoint;//第一次press时赋值
    QPointF mousePressScenePoint;//每次press时赋值
    QPointF mouseReleaseScenePoint;//每次release时赋值
    QPointF lastMouseReleaseScenePoint;//每次release后赋值
    QPointF mouseMoveScenePoint;

    virtual bool mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual bool mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual bool mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual bool mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);

    virtual bool contextMenuEvent(QGraphicsSceneContextMenuEvent *menuEvent);
    virtual bool keyPressEvent(QKeyEvent *keyEvent);

    virtual void cancelDrawing();
};

#endif // STATE_H
