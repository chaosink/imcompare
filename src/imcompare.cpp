#include "imcompare.h"
#include "ui_imcompare.h"
#include "mouselabel.h"
#include <cassert>
#include <QMimeData>
#include <QDebug>
#include <QDateTime>
#include <QFileInfo>

ImCompare::ImCompare(QWidget *parent) : QMainWindow(parent), ui(new Ui::ImCompare) {
	ui->setupUi(this);
	// dark, light, obs-Dark, obs-Default, QDark, Rachni, Tungsten
	// SetTheme("Rachni");

	connect(ui->imageTabWidget->tabBar(), SIGNAL(tabMoved(int, int)), this, SLOT(OnTabMoved()));
	connect(ui->imageTabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(OnTabClosed(int)));
}

void ImCompare::OnTabMoved() {
	UpdateImageBlock(x_last, y_last);
}

void ImCompare::OnTabClosed(int index) {
	ui->imageTabWidget->removeTab(index);
	auto layout = ui->horizontalLayoutOfImageBlockWidget;
	ImageBlock *imageBlock = dynamic_cast<ImageBlock*>(layout->itemAt(index)->widget());
	imageBlock->setParent(nullptr);

	if(ui->imageTabWidget->count() == 0) {
		ui->usageLabel->setVisible(true);
		ui->imageTabWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));
	}
}

void ImCompare::keyPressEvent(QKeyEvent *event) {
	QDateTime now = QDateTime::currentDateTime();
	QString s = now.toString("yyyy-MM-dd_HH-mm-ss");
	QString file_name;
	for(int i = 0; i < 100; ++i) {
		file_name = s + QString("_%2").arg(i, 2, 10, QLatin1Char('0'));
		if(!QFile::exists(file_name)) break;
	}

	if(event->key() == Qt::Key_S) {
		QPixmap result = this->grab();
		result = result.copy(0, result.height() - ui->imageBlockWidget->height() - 6, (ui->horizontalLayoutOfImageBlockWidget->count() - 1) * (256 + 2) + 4 * 2 - 2 , ui->imageBlockWidget->height() + 6);
		result.save(file_name + ".png");
		for(int i = 0; i < ui->imageTabWidget->count(); ++i) {
			ImageBlock *block = dynamic_cast<ImageBlock*>(ui->horizontalLayoutOfImageBlockWidget->itemAt(i)->widget());
			block->GetPixmap()->save(file_name + "_" + block->GetTitle() + ".png");
		}
	}
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

ImCompare::~ImCompare() {
	delete ui;
}

void ImCompare::AddImageTab(QString title, QImage *image) {
	ImageTab *tab = new ImageTab(image);
	connect(tab->mouseLabel, SIGNAL(Updated(int, int)), this, SLOT(UpdateImageBlock(int, int)));
	ui->imageTabWidget->insertTab(ui->imageTabWidget->currentIndex() + 1, tab, QString());
	ui->imageTabWidget->setTabText(ui->imageTabWidget->indexOf(tab), title);
	ui->imageTabWidget->setCurrentWidget(tab);
}

void ImCompare::AddImageBlock() {
	ImageBlock *block = new ImageBlock(ui->imageBlockWidget);
	ui->horizontalLayoutOfImageBlockWidget->insertWidget(0, block);
	block->SetTitle("test");
}

void ImCompare::dragEnterEvent(QDragEnterEvent *event) {
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}

void ImCompare::dropEvent(QDropEvent *event) {
	if(ui->imageTabWidget->count() == 0) {
		ui->usageLabel->setVisible(false);
		ui->imageTabWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
	}

	QList<QUrl> urls = event->mimeData()->urls();
	if(urls.isEmpty())
		return;

	foreach(QUrl url, urls) {
		QString file_name = url.toLocalFile();
		QImage *image = new QImage(file_name);
		if(image->isNull()) continue;
		AddImageBlock();
		AddImageTab(QFileInfo(file_name).baseName(), image);
	}
	UpdateImageBlock(x_last, y_last);
}

void ImCompare::UpdateImageBlock(int x, int y) {
	int local_size = 256;

	auto tabWidget = ui->imageTabWidget;
	for(int i = 0; i < tabWidget->count(); ++i) {
		const QPixmap *pixmap = dynamic_cast<ImageTab*>(tabWidget->widget(i))->mouseLabel->pixmap();
		int x_image = qBound(local_size / 4, x, pixmap->width() - local_size / 4);
		int y_image = qBound(local_size / 4, y, pixmap->height() - local_size / 4);
		QPixmap image_block = pixmap->copy(x_image - local_size / 4, y_image - local_size / 4, local_size / 2, local_size / 2);
		image_block = image_block.scaled(local_size, local_size);
		ImageBlock *block = dynamic_cast<ImageBlock*>(ui->horizontalLayoutOfImageBlockWidget->itemAt(i)->widget());
		block->SetPixmap(image_block);
		block->SetTitle(tabWidget->tabText(i));
	}
	x_last = x;
	y_last = y;
}
