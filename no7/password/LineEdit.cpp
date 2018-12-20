/*20153292 JeongHyeonjin*/

#include "LineEdit.h"
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlayout.h>
#include <qstring.h>
#include <iostream>

LineEdit::LineEdit(QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent,flags){
	QWidget *widget = new QWidget(this);
	setCentralWidget(widget);

	QGridLayout *grid = new QGridLayout(widget);
	grid->setMargin(10);
	grid->setSpacing(10);

	//username_entry=new QLineEdit(widget);
	username_entry=new QLineEdit(grid);

	password_entry = new QLineEdit(widget);
	password_entry->setEchoMode(QLineEdit::Password);

	grid->addWidget(new QLabel("username",widget),0,0,0);
	//grid->setSpacing(5);
	grid->addWidget(new QLabel("password",widget),1,0,0);

	grid->addWidget(username_entry,0,1,0);
	grid->addWidget(password_entry,1,1,0);

	QPushButton *button = new QPushButton("Ok",widget);
	grid->addWidget(button, 4,1,Qt::AlignRight);

	resize(350,500);

	connect(button, SIGNAL(clicked()),this, SLOT(Clicked()));
}

void LineEdit::Clicked(void){
	std::cout<<password_entry->text().toAscii().constData()<<"\n";
}

int main(int argc,char **argv){
	QApplication app(argc,argv);
	LineEdit *window = new LineEdit();

	window->show();
	return app.exec();
}
