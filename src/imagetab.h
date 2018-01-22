#ifndef IMAGETAB_H
#define IMAGETAB_H

#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include "mouselabel.h"

class ImageTab: public QWidget {
	Q_OBJECT

	QHBoxLayout *horizontalLayoutOfTabWidget;
	QScrollArea *scrollArea;
	QWidget *scrollAreaWidgetContents;
	QHBoxLayout *horizontalLayoutOfScrollArea;

public:
	MouseLabel *mouseLabel;

	explicit ImageTab(QImage *image, QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ImageTab();
};

#endif // IMAGETAB_H
