#ifndef IMAGEBLOCK_H
#define IMAGEBLOCK_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class ImageBlock: public QWidget {
	Q_OBJECT

	QLabel *textLabel;
	QLabel *imageLabel;
	QVBoxLayout *verticalLayout;

public:
	explicit ImageBlock(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ImageBlock();
	void SetPixmap(QPixmap &pixmap);
	void SetTitle(const QString &title);
};

#endif // IMAGEBLOCK_H
