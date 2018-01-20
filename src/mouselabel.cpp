#include "mouselabel.h"

MouseLabel::MouseLabel(QWidget* parent, Qt::WindowFlags f)
	: QLabel(parent, f) {}

MouseLabel::~MouseLabel() {}

void MouseLabel::mouseMoveEvent(QMouseEvent* event) {
	emit Updated(event->x(), event->y());
}

void MouseLabel::wheelEvent(QWheelEvent* event) {
	emit Updated(event->x(), event->y());
}
