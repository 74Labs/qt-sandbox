#include <QFlowEditorNode.h>

#include <QFlowEditorNodePin.h>

QFlowEditorNodeItem::QFlowEditorNodeItem(sfl::flow::Node *node, QGraphicsItem *parent) : sfl::flow::FlowEditorNodeItem(node), QGraphicsPathItem(parent)
{
    borderPen = QPen(Qt::black);
    borderPen.setCosmetic(true);
    borderPen.setWidthF(0.8f);

    QLinearGradient fill;
    fill.setCoordinateMode(QGradient::ObjectBoundingMode);
    fill.setColorAt(1, Qt::darkGray);
    fill.setColorAt(0, Qt::lightGray);
    normalFillBrush = QBrush(fill);
    selectedFillBrush = QBrush(Qt::white);

    width = DEFAULT_MIN_WIDTH;
    height = DEFAULT_MIN_HEIGHT;
    contentPadding = DEFAULT_CONTENT_PADDING;
    borderSpacing = DEFAULT_BORDER_SPACING;
    cornerRadius = DEFAULT_CORNER_RADIUS;

    borderItem.setParentItem(this);
    borderItem.setPos(0, 0);

    titleItem.setParentItem(this);
    titleItem.setText(QString::fromStdString(node->getNodeName()));
    titleItem.setFont(QFont("Sans Serif", 8, QFont::Bold));

    iconItem.setParentItem(this);
    //iconItem.setPixmap(QPixmap(":/images/icon.png"));

    collapseIconItem.setParentItem(this);
    collapseIconItem.setFont(QFont("FontAwesome", 12, QFont::Light));
    collapseIconItem.setText(QString(0xf0ae));

    setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);

    prepare();
}

void QFlowEditorNodeItem::prepare()
{

    width = std::max(DEFAULT_MIN_WIDTH, (int)iconItem.boundingRect().width() + 2 * contentPadding);
    width = std::max(width, (int)collapseIconItem.boundingRect().width() + (int)titleItem.boundingRect().width() + 5 * contentPadding);

    int y = contentPadding;

    titleItem.setPos(contentPadding, y);
    collapseIconItem.setPos(titleItem.boundingRect().width() + 4 * contentPadding, y);

    y += titleItem.boundingRect().height() + 2 * contentPadding;

    iconItem.setPos(contentPadding, y);

    y += iconItem.boundingRect().height() + contentPadding;

    foreach(QGraphicsItem *port_, childItems()) {
        if (port_->type() != QFlowEditorNodePinItem::Type)
            continue;
        QFlowEditorNodePinItem *port = (QFlowEditorNodePinItem*) port_;
        if (port->isOutput())
            port->setPos(width, y);
        else
            port->setPos(0, y);
        y += port_->boundingRect().height() + contentPadding;
    }

    height = y + contentPadding;

    QPainterPath path;
    path.addRoundedRect(0, 0, width, height, cornerRadius, cornerRadius);
    setPath(path);

    QPainterPath borderPath;
    borderPath.addRoundedRect(-borderSpacing, -borderSpacing, width + 2 * borderSpacing, height + 2 * borderSpacing, cornerRadius, cornerRadius);
    borderItem.setPath(borderPath);
}

sfl::flow::FlowEditorNodeItemPin* QFlowEditorNodeItem::addPin(sfl::flow::NodePin* pin)
{
    QFlowEditorNodePinItem *pinItem = new QFlowEditorNodePinItem(pin, this);
    pinItem->setName(QString::fromStdString(pin->getPinName()));
    pinItem->setIsOutput(pin->getDirection() == sfl::flow::NodePin::Direction::Output);

    prepare();

    return pinItem;
}

void QFlowEditorNodeItem::setPosition(float x, float y)
{
    setPos(x, y);
}

#include <QStyleOptionGraphicsItem>

void QFlowEditorNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	if (isSelected()) {
        painter->setPen(borderPen);
        painter->setBrush(selectedFillBrush);
        borderItem.setOpacity(0.2f);
	} else {
        painter->setPen(borderPen);
        painter->setBrush(normalFillBrush);
        borderItem.setOpacity(0);
	}

    painter->drawPath(path());

}
/*
QFlowEditorNodeItem* QFlowEditorNodeItem::clone()
{
    QFlowEditorNodeItem *b = new QFlowEditorNodeItem(getNode());
    this->scene()->addItem(b);

	foreach(QGraphicsItem *port_, childItems())
	{
        if (port_->type() == QFlowEditorNodePinItem::Type)
		{
            QFlowEditorNodePinItem *port = (QFlowEditorNodePinItem*) port_;
            b->addPin(port->portName(), port->isOutput(), port->ptr());
		}
	}

	return b;
}

QVector<QFlowEditorNodePinItem*> QFlowEditorNodeItem::ports()
{
    QVector<QFlowEditorNodePinItem*> res;
	foreach(QGraphicsItem *port_, childItems())
	{
        if (port_->type() == QFlowEditorNodePinItem::Type)
            res.append((QFlowEditorNodePinItem*) port_);
	}
	return res;
}
*/
QVariant QFlowEditorNodeItem::itemChange(GraphicsItemChange change, const QVariant &value)
{

    Q_UNUSED(change);
	return value;
}

