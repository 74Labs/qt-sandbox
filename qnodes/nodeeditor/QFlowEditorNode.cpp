#include <QFlowEditorNode.h>

#include <QFlowEditorNodePin.h>
#include <QDebug>

QFlowEditorNode::QFlowEditorNode(const QString &title, QGraphicsItem *parent) : QGraphicsPathItem(parent)
{
    borderPen = QPen(Qt::black);
    borderPen.setCosmetic(true);
    borderPen.setWidth(1);

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
    titleItem.setText(title);
    titleItem.setFont(QFont("Consolas", 10, QFont::Bold));

    iconItem.setParentItem(this);
    //iconItem.setPixmap(QPixmap(":/images/icon.png"));

    setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);

    prepare();
}

void QFlowEditorNode::prepare()
{

    width = std::min(iconItem.boundingRect().width() + 2 * contentPadding;

    int y = contentPadding;

    titleItem.setPos(contentPadding, y);

    y += titleItem.boundingRect().height();

    iconItem.setPos(contentPadding, y);

    y += iconItem.boundingRect().height() + contentPadding;

    foreach(QGraphicsItem *port_, childItems()) {
        if (port_->type() != QFlowEditorNodePin::Type)
            continue;
        QFlowEditorNodePin *port = (QFlowEditorNodePin*) port_;
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

QFlowEditorNodePin* QFlowEditorNode::addPort(const QString &name, bool isOutput, int ptr)
{
    QFlowEditorNodePin *port = new QFlowEditorNodePin(this);
	port->setName(name);
	port->setIsOutput(isOutput);
	port->setPtr(ptr);

    prepare();

	return port;
}

void QFlowEditorNode::addInputPort(const QString &name)
{
	addPort(name, false);
}

void QFlowEditorNode::addOutputPort(const QString &name)
{
	addPort(name, true);
}

void QFlowEditorNode::addInputPorts(const QStringList &names)
{
	foreach(QString n, names)
		addInputPort(n);
}

void QFlowEditorNode::addOutputPorts(const QStringList &names)
{
	foreach(QString n, names)
		addOutputPort(n);
}

#include <QStyleOptionGraphicsItem>

void QFlowEditorNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QFlowEditorNode* QFlowEditorNode::clone()
{
    QFlowEditorNode *b = new QFlowEditorNode(this->title());
    this->scene()->addItem(b);

	foreach(QGraphicsItem *port_, childItems())
	{
        if (port_->type() == QFlowEditorNodePin::Type)
		{
            QFlowEditorNodePin *port = (QFlowEditorNodePin*) port_;
            b->addPort(port->portName(), port->isOutput(), port->ptr());
		}
	}

	return b;
}

QVector<QFlowEditorNodePin*> QFlowEditorNode::ports()
{
    QVector<QFlowEditorNodePin*> res;
	foreach(QGraphicsItem *port_, childItems())
	{
        if (port_->type() == QFlowEditorNodePin::Type)
            res.append((QFlowEditorNodePin*) port_);
	}
	return res;
}

QVariant QFlowEditorNode::itemChange(GraphicsItemChange change, const QVariant &value)
{

    Q_UNUSED(change);
	return value;
}

