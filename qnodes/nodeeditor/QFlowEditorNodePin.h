#pragma once

#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QFontMetrics>
#include <QPen>
#include <QGraphicsSceneHoverEvent>

class QFlowEditorNodeItem;
class QFlowEditorPinConnection;

class QFlowEditorNodePinItem : public QGraphicsPathItem
{
public:
	enum { Type = QGraphicsItem::UserType + 1 };

    QFlowEditorNodePinItem(QFlowEditorNodeItem *parent);
    ~QFlowEditorNodePinItem();

	void setName(const QString &n);
	void setIsOutput(bool o);
	int radius();
	bool isOutput();
    QVector<QFlowEditorPinConnection*>& connections();
	void setPortFlags(int);

	const QString& portName() const { return name; }
	int portFlags() const { return m_portFlags; }

	int type() const { return Type; }

    QFlowEditorNodeItem* node() const;

	quint64 ptr();
	void setPtr(quint64);

    bool isConnectedTo(QFlowEditorNodePinItem*);

    bool isConnected();

protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void dragEnterEvent(QGraphicsSceneHoverEvent * event);
    void dropEvent(QGraphicsSceneHoverEvent * event);
    void dragLeaveEvent(QGraphicsSceneHoverEvent * event);

private:

    QFlowEditorNodeItem *parentNode;
	QString name;
	bool isOutput_;
    QGraphicsTextItem label;
	int radius_;
	int margin;
    QVector<QFlowEditorPinConnection*> m_connections;
	int m_portFlags;
	quint64 m_ptr;
    bool isHovered;
    bool multiSignal;

    QPen borderPen;
    QPen acceptBorderPen;
    QPen refuseBorderPen;
    QBrush connectedBrush;
    QBrush disconnectedBrush;

};
