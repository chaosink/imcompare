#include "imcompare.h"
#include "ui_imcompare.h"
#include "mouselabel.h"

#include <QMimeData>
#include <QFile>
#include <QUrl>
#include <QLabel>
#include <QTextStream>
#include <QDebug>

ImCompare::ImCompare(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ImCompare)
{
	ui->setupUi(this);
	// dark, light, obs-Dark, obs-Default, QDark, Rachni, Tungsten
	// SetTheme("Rachni");

	connect(ui->label_5, SIGNAL(Updated(int, int)), this, SLOT(OnMouseUpdated(int, int)));
	connect(ui->label_6, SIGNAL(Updated(int, int)), this, SLOT(OnMouseUpdated(int, int)));

	QImage *image_refenence = new QImage("image/reference.png");
	ui->label_5->setPixmap(QPixmap::fromImage(*image_refenence));
	QImage *image_input = new QImage("image/input.png");
	ui->label_6->setPixmap(QPixmap::fromImage(*image_input));
}

void ImCompare::SetTheme(QString theme) {
	if(theme == "default") {
		setStyleSheet("");
		return;
	}
	QFile file("theme/" + theme + ".qss");
	if(file.open(QFile::ReadOnly))
		setStyleSheet(QTextStream(&file).readAll());
	else
		qWarning() << "Failed to load style sheet file\n";
}

ImCompare::~ImCompare()
{
	delete ui;
}

//当用户拖动文件到窗口部件上时候，就会触发dragEnterEvent事件
void ImCompare::dragEnterEvent(QDragEnterEvent *event)
{
	//如果为文件，则支持拖放
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}

//当用户放下这个文件后，就会触发dropEvent事件
void ImCompare::dropEvent(QDropEvent *event)
{
	//注意：这里如果有多文件存在，意思是用户一下子拖动了多个文件，而不是拖动一个目录
	//如果想读取整个目录，则在不同的操作平台下，自己编写函数实现读取整个目录文件名
	QList<QUrl> urls = event->mimeData()->urls();
	if(urls.isEmpty())
		return;

	//往文本框中追加文件名
	foreach(QUrl url, urls) {
		QString file_name = url.toLocalFile();
		QImage *image = new QImage(file_name);
		ui->label_5->setPixmap(QPixmap::fromImage(*image));

		qDebug() << file_name;
	}
}

void ImCompare::OnMouseUpdated(int x, int y) {
	int local_size = 256;

	int x_image = qBound(local_size / 4, x, ui->label_5->pixmap()->width() - local_size / 4);
	int y_image = qBound(local_size / 4, y, ui->label_5->pixmap()->height() - local_size / 4);
	QPixmap local_image_reference = ui->label_5->pixmap()->copy(x_image - local_size / 4, y_image - local_size / 4, local_size / 2, local_size / 2);
	local_image_reference = local_image_reference.scaled(local_size, local_size);
	ui->label->setPixmap(local_image_reference);

	x_image = qBound(local_size / 4, x, ui->label_6->pixmap()->width() - local_size / 4);
	y_image = qBound(local_size / 4, y, ui->label_6->pixmap()->height() - local_size / 4);
	QPixmap local_image_input = ui->label_6->pixmap()->copy(x_image - local_size / 4, y_image - local_size / 4, local_size / 2, local_size / 2);
	local_image_input = local_image_input.scaled(local_size, local_size);
	ui->label_3->setPixmap(local_image_input);
}
