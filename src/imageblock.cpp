#include "imageblock.h"

ImageBlock::ImageBlock(QWidget* parent, Qt::WindowFlags f)
	: QWidget(parent, f) {
	widget = new QWidget();
	label = new QLabel();
}

ImageBlock::~ImageBlock() {
	delete widget;
	delete label;
}
