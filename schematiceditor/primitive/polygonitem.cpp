#include "polygonitem.h"
#include "polygonitemcontrolpoint.h"

#include "shapeitemaddcommand.h"
#include "shapeitemremovecommand.h"
#include "shapeitemmovecommand.h"
#include "shapeitemchanggeometryecommand.h"


#include "schematicscene.h"

PolygonItem::PolygonItem(SchematicScene *scene, QGraphicsItem *parent)
    :QGraphicsPolygonItem(parent),
      AbstractShapeItem(scene,this)
{
    initial();
    if(parent && (parent->type() > Item::PackageItemType)){
        isMemberOfPackage = true;
    }else{
        setFlags(ItemIsMovable | ItemIsSelectable | ItemIsFocusable);
    }

    metadata["type"] = Type;
    metadata["lineStyle"] = LineStyle::SolidLine;
    metadata["lineWidth"] = LineWidth::Normal;
    metadata["fillStyle"] = FillStyle::NoBrush;
    metadata["color"] = schColor.value("Display");
}

PolygonItem::PolygonItem(SchematicScene *scene, const json &j, QGraphicsItem *parent)
    :QGraphicsPolygonItem(parent),
      AbstractShapeItem(scene,this)
{

}

PolygonItem::~PolygonItem()
{
}

void PolygonItem::selected()
{
    setPen(selectedPen);
    drawControlPoints();
}

void PolygonItem::unselected()
{
    setPen(normalPen);
    foreach (QGraphicsItem *item, childItems()) {
        schScene->removeItem(item);
        delete item;
    }
}

int PolygonItem::type() const
{
    return Type;
}

void PolygonItem::createCommandAdd()
{
    schScene->pushCommand(new ShapeItemAddCommand(this),true);
    metadata["geometry"] = polygon();
}

void PolygonItem::createCommandRemove()
{
    schScene->pushCommand(new ShapeItemRemoveCommand(this),true);

}

void PolygonItem::createCommandMove()
{
    schScene->pushCommand(new ShapeItemMoveCommand(this));
}

void PolygonItem::createCommandChangeGeometry()
{
    schScene->pushCommand(new ShapeItemChangeGeometryCommand(this));

}

void PolygonItem::setGeometry(const json &geometry)
{
    setPolygon(geometry);
}

QVariant PolygonItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    switch (change)
    {
    case ItemSelectedHasChanged:
        value.toBool() ? selected() : unselected();
        break;
    default:
        break;
    }
    return QGraphicsItem::itemChange(change, value);
}

void PolygonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(isMoved()){
        createCommandMove();

    }
    QGraphicsPolygonItem::mouseReleaseEvent(mouseEvent);
}

void PolygonItem::drawControlPoints()
{
    const QPolygonF &metaPolygon = polygon();
    int count = metaPolygon.size();
    for(int i=0;i<count;i++){
        PolygonItemControlPoint *controlPoint = new PolygonItemControlPoint(this);
        controlPoint->setPos(metaPolygon.at(i));
        controlPoint->flag = i;
    }
}

void PolygonItem::initial()
{
    normalPen   = QPen(QColor(schColor.value("Display")), 0, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    selectedPen = QPen(QColor(schColor.value("Selection")), 0, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    drawingPen  = QPen(QColor(schColor.value("Drawing")), 0, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

//    setAcceptHoverEvents(true);

    if (schScene->sceneState == FSM::SelectState || schScene->sceneState == FSM::PartItemState)
    {
        //TODO 评估是否有必要每次setpen时重绘
        setPen(normalPen);
    }
    else
    {
        setPen(drawingPen);
    }

    setZValue(ZValue::BaseItemZValue);
}
