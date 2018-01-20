#ifndef IMCOMPARE_H
#define IMCOMPARE_H

#include <QMainWindow>
#include <QLabel>
#include <QDragLeaveEvent>

namespace Ui {
class ImCompare;
}

class ImCompare : public QMainWindow
{
	Q_OBJECT

public:
	explicit ImCompare(QWidget *parent = 0);
	~ImCompare();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);

private slots:
	void OnMouseUpdated(int x, int y);

private:
	Ui::ImCompare *ui;
	void SetTheme(QString theme);
};

#endif // IMCOMPARE_H
