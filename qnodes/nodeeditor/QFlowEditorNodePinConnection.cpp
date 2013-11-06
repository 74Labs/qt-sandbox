#include <QFlowEditorNodePinConnection.h>

#include <QFlowEditorNodePin.h>

QFlowEditorPinConnection::QFlowEditorPinConnection(QFlowEditorNodePin *sourcePin, QFlowEditorNodePin *destinationPin, QGraphicsItem *parent) : QGraphicsPathItem(parent)
{
	setPen(QPen(Qt::black, 2));
	setBrush(Qt::NoBrush);
    setZValue(-1);
    srcPin = sourcePin;
    destPin = destinationPin;
}

QFlowEditorPinConnection::~QFlowEditorPinConnection()
{
    if (srcPin)
        srcPin->connections().remove(srcPin->connections().indexOf(this));
    if (destPin)
        destPin->connections().remove(destPin->connections().indexOf(this));
}

void QFlowEditorPinConnection::setStartPos(const QPointF &p)
{
    srcPos = p;
}

void QFlowEditorPinConnection::setEndPos(const QPointF &p)
{
    destPos = p;
}

void QFlowEditorPinConnection::setSourcePin(QFlowEditorNodePin *p)
{
    srcPin = p;

    srcPin->connections().append(this);
}

void QFlowEditorPinConnection::setDestinationPin(QFlowEditorNodePin *p)
{
    destPin = p;

    destPin->connections().append(this);
}

void QFlowEditorPinConnection::updatePositions()
{
    srcPos = srcPin->scenePos();
    destPos = destPin->scenePos();
}

void QFlowEditorPinConnection::updatePath()
{
	QPainterPath p;

	//QPointF pos1(m_port1->scenePos());
	//QPointF pos2(m_port2->scenePos());

    p.moveTo(srcPos);

    qreal dx = destPos.x() - srcPos.x();
    qreal dy = destPos.y() - srcPos.y();

    QPointF ctr1(srcPos.x() + dx * 0.25, srcPos.y() + dy * 0.1);
    QPointF ctr2(srcPos.x() + dx * 0.75, srcPos.y() + dy * 0.9);

    p.cubicTo(ctr1, ctr2, destPos);

	setPath(p);
}

QFlowEditorNodePin* QFlowEditorPinConnection::sourcePin() const
{
    return srcPin;
}

QFlowEditorNodePin* QFlowEditorPinConnection::destinationPin() const
{
    return destPin;
}
