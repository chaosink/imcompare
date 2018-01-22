#ifndef MOUSELABEL_H
#define MOUSELABEL_H

#include <QLabel>
#include <QInputEvent>

class MouseLabel: public QLabel {
	Q_OBJECT

public:
	explicit MouseLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~MouseLabel();

signals:
	void Updated(int x, int y);

protected:
	void mouseMoveEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent *event);
};

#endif // MOUSELABEL_H
