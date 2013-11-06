#include <QFlowEditor.h>

#include <QFlowEditorNode.h>
#include <QFlowEditorNodePin.h>
#include <QFlowEditorNodePinConnection.h>

QFlowEditor::QFlowEditor(QWidget *parent) :
    QGraphicsView(parent)
{
    conn = 0;
    scene = new QGraphicsScene();
    scene->installEventFilter(this);
    scene->setFont(QFont("Ubuntu", 10));
    setScene(scene);
}

QFlowEditor::~QFlowEditor()
{
    delete scene;
}

void QFlowEditor::addItem(QGraphicsItem *item)
{
    scene->addItem(item);
}

QGraphicsItem* QFlowEditor::itemAt(const QPointF &pos)
{
	QList<QGraphicsItem*> items = scene->items(QRectF(pos - QPointF(1,1), QSize(3,3)));

	foreach(QGraphicsItem *item, items)
		if (item->type() > QGraphicsItem::UserType)
			return item;

	return 0;
}

bool QFlowEditor::eventFilter(QObject *o, QEvent *e)
{
	QGraphicsSceneMouseEvent *me = (QGraphicsSceneMouseEvent*) e;

	switch ((int) e->type())
	{
	case QEvent::GraphicsSceneMousePress:
	{

		switch ((int) me->button())
		{
		case Qt::LeftButton:
		{
			QGraphicsItem *item = itemAt(me->scenePos());
            if (item && item->type() == QFlowEditorNodePin::Type)
			{
                conn = new QFlowEditorPinConnection(0);
                scene->addItem(conn);
                conn->setSourcePin((QFlowEditorNodePin*) item);
                conn->setStartPos(item->scenePos());
                conn->setEndPos(me->scenePos());
				conn->updatePath();

				return true;
            } else if (item && item->type() == QFlowEditorNode::Type)
			{
				/* if (selBlock)
					selBlock->setSelected(); */
				// selBlock = (QNEBlock*) item;
			}
			break;
		}
		case Qt::RightButton:
		{
			QGraphicsItem *item = itemAt(me->scenePos());
            if (item && (item->type() == QFlowEditorPinConnection::Type || item->type() == QFlowEditorNode::Type))
				delete item;
			// if (selBlock == (QNEBlock*) item)
				// selBlock = 0;
			break;
		}
		}
	}
	case QEvent::GraphicsSceneMouseMove:
	{
		if (conn)
		{
            conn->setEndPos(me->scenePos());
			conn->updatePath();
			return true;
		}
		break;
	}
	case QEvent::GraphicsSceneMouseRelease:
	{
		if (conn && me->button() == Qt::LeftButton)
		{
			QGraphicsItem *item = itemAt(me->scenePos());
            if (item && item->type() == QFlowEditorNodePin::Type)
			{
                QFlowEditorNodePin *port1 = conn->sourcePin();
                QFlowEditorNodePin *port2 = (QFlowEditorNodePin*) item;

                if (port1->node() != port2->node() && port1->isOutput() != port2->isOutput() && !port1->isConnectedTo(port2))
				{
                    conn->setEndPos(port2->scenePos());
                    conn->setDestinationPin(port2);
					conn->updatePath();
					conn = 0;
					return true;
				}
			}

			delete conn;
			conn = 0;
			return true;
		}
		break;
	}
	}
	return QObject::eventFilter(o, e);
}
