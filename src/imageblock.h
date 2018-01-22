#ifndef IMAGEBLOCK_H
#define IMAGEBLOCK_H

#include <QWidget>
#include <QLabel>

class ImageBlock: public QWidget {
	Q_OBJECT

	QWidget *widget;
	QLabel *label;

public:
	explicit ImageBlock(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ImageBlock();
};

#endif // IMAGEBLOCK_H
