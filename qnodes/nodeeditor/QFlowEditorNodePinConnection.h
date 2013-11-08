#pragma once

#include <QGraphicsPathItem>
#include <QPen>

class QFlowEditorNodePinItem;

class QFlowEditorPinConnection : public QGraphicsPathItem
{
public:
	enum { Type = QGraphicsItem::UserType + 2 };

    QFlowEditorPinConnection(QFlowEditorNodePinItem *srcPin = 0, QFlowEditorNodePinItem *destPin = 0, QGraphicsItem *parent = 0);
    ~QFlowEditorPinConnection();

    void setStartPos(const QPointF &p);
    void setEndPos(const QPointF &p);
    void setSourcePin(QFlowEditorNodePinItem *p);
    void setDestinationPin(QFlowEditorNodePinItem *p);
    void updatePositions();
	void updatePath();
    QFlowEditorNodePinItem* sourcePin() const;
    QFlowEditorNodePinItem* destinationPin() const;

	int type() const { return Type; }

private:
    QPointF srcPos;
    QPointF destPos;
    QFlowEditorNodePinItem *srcPin;
    QFlowEditorNodePinItem *destPin;
};
