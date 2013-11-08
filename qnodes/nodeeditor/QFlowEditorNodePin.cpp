#include <QFlowEditorNodePin.h>

#include <QFlowEditorNode.h>
#include <QFlowEditorNodePinConnection.h>

QFlowEditorNodePinItem::QFlowEditorNodePinItem(QFlowEditorNodeItem *parent):
    QGraphicsPathItem((QGraphicsItem*)parent)
{
    borderPen = QPen(Qt::black);
    acceptBorderPen = QPen(Qt::darkGreen);
    acceptBorderPen.setWidth(4);
    refuseBorderPen = QPen(Qt::darkRed);
    refuseBorderPen.setWidth(4);

    connectedBrush = QBrush(Qt::black);
    disconnectedBrush = QBrush(Qt::gray);

    label.setParentItem(this);
    label.setFont(QFont("Ubuntu", 8));

    radius_ = 4;
    margin = 0;

	QPainterPath p;
    p.addEllipse(-radius_, -radius_, 2 * radius_, 2 * radius_);
	setPath(p);

    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    setAcceptHoverEvents(true);
    setAcceptDrops(true);

    isHovered = false;
    multiSignal = false;
	m_portFlags = 0;
    parentNode = (QFlowEditorNodeItem*)parent;
}

QFlowEditorNodePinItem::~QFlowEditorNodePinItem()
{
    foreach(QFlowEditorPinConnection *conn, m_connections)
		delete conn;
}

bool QFlowEditorNodePinItem::isConnected()
{
    return m_connections.size();
}

void QFlowEditorNodePinItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    if(isConnected())
    {
        painter->setBrush(connectedBrush);
        painter->setPen(isHovered ? (multiSignal ? acceptBorderPen : refuseBorderPen) : borderPen);
    }
    else
    {
        painter->setBrush(disconnectedBrush);
        painter->setPen(isHovered ? acceptBorderPen : borderPen);
    }

    painter->drawPath(path());
}

void QFlowEditorNodePinItem::setName(const QString &n)
{
	name = n;
    label.setPlainText(n);
}

void QFlowEditorNodePinItem::setIsOutput(bool o)
{
	isOutput_ = o;

	QFontMetrics fm(scene()->font());
	QRect r = fm.boundingRect(name);

	if (isOutput_)
        label.setPos(-radius_ - margin - label.boundingRect().width(), -label.boundingRect().height()/2);
	else
        label.setPos(radius_ + margin, -label.boundingRect().height()/2);
}

int QFlowEditorNodePinItem::radius()
{
	return radius_;
}

bool QFlowEditorNodePinItem::isOutput()
{
	return isOutput_;
}

QVector<QFlowEditorPinConnection*>& QFlowEditorNodePinItem::connections()
{
	return m_connections;
}

QFlowEditorNodeItem* QFlowEditorNodePinItem::node() const
{
    return parentNode;
}

quint64 QFlowEditorNodePinItem::ptr()
{
	return m_ptr;
}

void QFlowEditorNodePinItem::setPtr(quint64 p)
{
	m_ptr = p;
}

bool QFlowEditorNodePinItem::isConnectedTo(QFlowEditorNodePinItem *other)
{
    foreach(QFlowEditorPinConnection *conn, m_connections)
        if (conn->sourcePin() == other || conn->destinationPin() == other)
			return true;

	return false;
}

QVariant QFlowEditorNodePinItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
	if (change == ItemScenePositionHasChanged)
	{
        foreach(QFlowEditorPinConnection *conn, m_connections)
		{
            conn->updatePositions();
			conn->updatePath();
		}
	}
    return value;
}

void QFlowEditorNodePinItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = true;
    update();
}

void QFlowEditorNodePinItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = false;
    update();
}

void QFlowEditorNodePinItem::dragEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = true;
    update();
}

void QFlowEditorNodePinItem::dragLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = false;
    update();
}
