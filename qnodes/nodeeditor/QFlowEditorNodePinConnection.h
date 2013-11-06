#pragma once

#include <QGraphicsPathItem>
#include <QPen>

class QFlowEditorNodePin;

class QFlowEditorPinConnection : public QGraphicsPathItem
{
public:
	enum { Type = QGraphicsItem::UserType + 2 };

    QFlowEditorPinConnection(QFlowEditorNodePin *srcPin = 0, QFlowEditorNodePin *destPin = 0, QGraphicsItem *parent = 0);
    ~QFlowEditorPinConnection();

    void setStartPos(const QPointF &p);
    void setEndPos(const QPointF &p);
    void setSourcePin(QFlowEditorNodePin *p);
    void setDestinationPin(QFlowEditorNodePin *p);
    void updatePositions();
	void updatePath();
    QFlowEditorNodePin* sourcePin() const;
    QFlowEditorNodePin* destinationPin() const;

	int type() const { return Type; }

private:
    QPointF srcPos;
    QPointF destPos;
    QFlowEditorNodePin *srcPin;
    QFlowEditorNodePin *destPin;
};
