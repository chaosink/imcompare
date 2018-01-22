#ifndef IMAGETAB_H
#define IMAGETAB_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mouselabel.h"

class ImageTab: public QWidget {
	Q_OBJECT

	QWidget *tab;
	QHBoxLayout *horizontalLayoutOfTabWidget;
	QScrollArea *scrollArea;
	QWidget *scrollAreaWidgetContents;
	QHBoxLayout *horizontalLayoutOfScrollArea;
	MouseLabel *mouseLabel;

public:
	explicit ImageTab(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ImageTab();
};

#endif // IMAGETAB_H
