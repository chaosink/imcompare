#include "imagetab.h"

ImageTab::ImageTab(QWidget* parent, Qt::WindowFlags f)
	: QWidget(parent, f) {
	scrollArea = new QScrollArea(this);
	scrollArea->setWidgetResizable(true);

	horizontalLayoutOfTabWidget = new QHBoxLayout(this);
	horizontalLayoutOfTabWidget->addWidget(scrollArea);

	scrollAreaWidgetContents = new QWidget();
	scrollAreaWidgetContents->setGeometry(QRect(0, 0, 514, 126));
	scrollArea->setWidget(scrollAreaWidgetContents);

	horizontalLayoutOfScrollArea = new QHBoxLayout(scrollAreaWidgetContents);
	horizontalLayoutOfScrollArea->addWidget(mouseLabel);

	horizontalLayoutOfScrollArea->setSpacing(0);
	horizontalLayoutOfScrollArea->setContentsMargins(0, 0, 0, 0);

	mouseLabel = new MouseLabel(scrollAreaWidgetContents);
	QImage *image = new QImage("image/input.png");
	mouseLabel->setPixmap(QPixmap::fromImage(*image));

	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(mouseLabel->sizePolicy().hasHeightForWidth());
	mouseLabel->setSizePolicy(sizePolicy);
	mouseLabel->setMouseTracking(true);
}

ImageTab::~ImageTab() {
	delete horizontalLayoutOfTabWidget;
	delete scrollArea;
	delete scrollAreaWidgetContents;
	delete horizontalLayoutOfScrollArea;
	delete mouseLabel;
}
