#pragma once

#include <QGraphicsPathItem>
#include <QPen>
#include <QFont>
#include <QGraphicsScene>
#include <QFontMetrics>
#include <QPainter>

#include <FlowEditorNodeItem.h>

class QFlowEditorNodePinItem;

class QFlowEditorNodeItem : public FlowEditorNodeItem, public QGraphicsPathItem
{
private:

    static const int DEFAULT_MIN_WIDTH = 60;
    static const int DEFAULT_MIN_HEIGHT = 60;
    static const int DEFAULT_BORDER_SPACING = 3;
    static const int DEFAULT_CONTENT_PADDING = 5;
    static const int DEFAULT_CORNER_RADIUS = 5;

public:

	enum { Type = QGraphicsItem::UserType + 3 };

    QFlowEditorNodeItem(const QString &title, QGraphicsItem *parent = 0);

    QFlowEditorNodePinItem* addPin(const QString &name, bool isOutput, int ptr = 0);
    void addInputPin(const std::string &name);
    void addOutputPin(const std::string &name);
	void addInputPorts(const QStringList &names);
	void addOutputPorts(const QStringList &names);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QFlowEditorNodeItem* clone();
    QVector<QFlowEditorNodePinItem*> ports();

	int type() const { return Type; }
    const QString title() const { return titleItem.text(); }

    //QRectF boundingRect() const;

protected:

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

    QGraphicsPathItem borderItem;
    QGraphicsSimpleTextItem titleItem;
    QGraphicsPixmapItem iconItem;

    void prepare();
};
