#ifndef IMCOMPARE_H
#define IMCOMPARE_H

#include <QMainWindow>
#include <QLabel>
#include <QDragLeaveEvent>
#include "imagetab.h"
#include "imageblock.h"

namespace Ui {
class ImCompare;
}

class ImCompare : public QMainWindow {
	Q_OBJECT

	int x_last = 0, y_last = 0;

public:
	explicit ImCompare(QWidget *parent = 0);
	~ImCompare();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	void keyPressEvent(QKeyEvent *event);

private slots:
	void UpdateImageBlock(int x, int y);
	void OnTabMoved();
	void OnTabClosed(int index);

private:
	Ui::ImCompare *ui;
	void SetTheme(QString theme);
	void AddImageTab(QString title, QImage *image);
	void AddImageBlock();
};

#endif // IMCOMPARE_H
