#include <QFlowEditorNodePin.h>

#include <QFlowEditorNode.h>
#include <QFlowEditorNodePinConnection.h>

QFlowEditorNodePin::QFlowEditorNodePin(QFlowEditorNode *parent):
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
    parentNode = (QFlowEditorNode*)parent;
}

QFlowEditorNodePin::~QFlowEditorNodePin()
{
    foreach(QFlowEditorPinConnection *conn, m_connections)
		delete conn;
}

bool QFlowEditorNodePin::isConnected()
{
    return m_connections.size();
}

void QFlowEditorNodePin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void QFlowEditorNodePin::setName(const QString &n)
{
	name = n;
    label.setPlainText(n);
}

void QFlowEditorNodePin::setIsOutput(bool o)
{
	isOutput_ = o;

	QFontMetrics fm(scene()->font());
	QRect r = fm.boundingRect(name);

	if (isOutput_)
        label.setPos(-radius_ - margin - label.boundingRect().width(), -label.boundingRect().height()/2);
	else
        label.setPos(radius_ + margin, -label.boundingRect().height()/2);
}

int QFlowEditorNodePin::radius()
{
	return radius_;
}

bool QFlowEditorNodePin::isOutput()
{
	return isOutput_;
}

QVector<QFlowEditorPinConnection*>& QFlowEditorNodePin::connections()
{
	return m_connections;
}

QFlowEditorNode* QFlowEditorNodePin::node() const
{
    return parentNode;
}

quint64 QFlowEditorNodePin::ptr()
{
	return m_ptr;
}

void QFlowEditorNodePin::setPtr(quint64 p)
{
	m_ptr = p;
}

bool QFlowEditorNodePin::isConnectedTo(QFlowEditorNodePin *other)
{
    foreach(QFlowEditorPinConnection *conn, m_connections)
        if (conn->sourcePin() == other || conn->destinationPin() == other)
			return true;

	return false;
}

QVariant QFlowEditorNodePin::itemChange(GraphicsItemChange change, const QVariant &value)
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

void QFlowEditorNodePin::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = true;
    update();
}

void QFlowEditorNodePin::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = false;
    update();
}

void QFlowEditorNodePin::dragEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = true;
    update();
}

void QFlowEditorNodePin::dragLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHovered = false;
    update();
}
