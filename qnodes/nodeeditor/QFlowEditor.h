#pragma once

#include <QGraphicsView>
#include <QFont>
#include <QGraphicsScene>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QFontDatabase>

class QFlowEditorPinConnection;

class QFlowEditor : public QGraphicsView
{

    Q_OBJECT

public:

    explicit QFlowEditor(QWidget *parent = 0);

    ~QFlowEditor();

    void addItem(QGraphicsItem *item);

	bool eventFilter(QObject *, QEvent *);

signals:

    void itemSelected();
    void itemMoved();
    void itemsConnected();
    void itemsDisconnected();

private:

	QGraphicsItem *itemAt(const QPointF&);

private:
	QGraphicsScene *scene;
    QFont font;
    QFlowEditorPinConnection *conn;
	// QNEBlock *selBlock;
};
