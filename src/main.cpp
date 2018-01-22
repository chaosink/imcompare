#include "imcompare.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	ImCompare w;
	w.show();

	return a.exec();
}
