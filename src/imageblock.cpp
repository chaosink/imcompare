#include "imageblock.h"

ImageBlock::ImageBlock(QWidget* parent, Qt::WindowFlags f)
	: QWidget(parent, f) {
	textLabel = new QLabel(this);
	textLabel->setAlignment(Qt::AlignCenter);

	imageLabel = new QLabel(this);
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
	imageLabel->setSizePolicy(sizePolicy);
	imageLabel->setMinimumSize(QSize(256, 256));

	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setSpacing(0);
	verticalLayout->setContentsMargins(0, 0, 0, 0);
	verticalLayout->addWidget(textLabel);
	verticalLayout->addWidget(imageLabel);
}

ImageBlock::~ImageBlock() {}

void ImageBlock::SetPixmap(QPixmap &pixmap) {
	imageLabel->setPixmap(pixmap);
}

void ImageBlock::SetTitle(const QString &title) {
	textLabel->setText(title);
}
