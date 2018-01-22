#include "imagetab.h"

ImageTab::ImageTab(QImage *image, QWidget* parent, Qt::WindowFlags f)
	: QWidget(parent, f) {
	scrollArea = new QScrollArea(this);
	scrollArea->setWidgetResizable(true);

	horizontalLayoutOfTabWidget = new QHBoxLayout(this);
	horizontalLayoutOfTabWidget->addWidget(scrollArea);
	horizontalLayoutOfTabWidget->setSpacing(0);
	horizontalLayoutOfTabWidget->setContentsMargins(0, 0, 0, 0);

	scrollAreaWidgetContents = new QWidget();
	scrollArea->setWidget(scrollAreaWidgetContents);

	mouseLabel = new MouseLabel(scrollAreaWidgetContents);
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(mouseLabel->sizePolicy().hasHeightForWidth());
	mouseLabel->setSizePolicy(sizePolicy);
	mouseLabel->setMouseTracking(true);

	horizontalLayoutOfScrollArea = new QHBoxLayout(scrollAreaWidgetContents);
	horizontalLayoutOfScrollArea->addWidget(mouseLabel);
	horizontalLayoutOfScrollArea->setSpacing(0);
	horizontalLayoutOfScrollArea->setContentsMargins(0, 0, 0, 0);

	mouseLabel->setPixmap(QPixmap::fromImage(*image));
}

ImageTab::~ImageTab() {}
