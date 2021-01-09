#ifndef BUTTON_H
#define BUTTON_H

#include "windows.h"
#include "mmsystem.h"

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsTextItem>
#include <QString>

namespace monopoly
{
    class button : public QObject, public QGraphicsRectItem
    {
        Q_OBJECT
        public:
            //constructors
            button(QString name, QGraphicsItem* parent=nullptr);
            ~button(){}

            //public methods (events)
            void mousePressEvent (QGraphicsSceneMouseEvent* event);
            void hoverEnterEvent (QGraphicsSceneHoverEvent* event);
            void hoverLeaveEvent (QGraphicsSceneHoverEvent* event);

        signals:
            void clicked();

        private:
            QGraphicsTextItem* text;
    };

}

#endif // BUTTON_H
