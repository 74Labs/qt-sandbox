#pragma once

#include <QGraphicsPathItem>
#include <QPen>
#include <QFont>
#include <QGraphicsScene>
#include <QFontMetrics>
#include <QPainter>

#include <FlowEditorNodeItem.h>

class QFlowEditorNodeItem : public sfl::flow::FlowEditorNodeItem, public QGraphicsPathItem
{
private:

    static const int DEFAULT_MIN_WIDTH = 60;
    static const int DEFAULT_MIN_HEIGHT = 60;
    static const int DEFAULT_BORDER_SPACING = 3;
    static const int DEFAULT_CONTENT_PADDING = 5;
    static const int DEFAULT_CORNER_RADIUS = 5;

public:

	enum { Type = QGraphicsItem::UserType + 3 };

    QFlowEditorNodeItem(sfl::flow::Node* node, QGraphicsItem *parent = 0);

    sfl::flow::FlowEditorNodeItemPin* addPin(sfl::flow::NodePin *pin);

    void setPosition(float x, float y);

	int type() const { return Type; }
    const QString title() const { return titleItem.text(); }

protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:

    int contentPadding;
    int borderSpacing;
    int cornerRadius;
	int width;
    int height;

    QPen selectedPen;
    QPen borderPen;
    QFont titleFont;
    QBrush selectedFillBrush;
    QBrush normalFillBrush;

    QGraphicsSimpleTextItem collapseIconItem;
    QGraphicsPathItem borderItem;
    QGraphicsSimpleTextItem titleItem;
    QGraphicsPixmapItem iconItem;

    void prepare();
};
