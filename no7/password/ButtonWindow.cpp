#include "ButtonWindow.h"
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qapplication.h>
#include <iostream>

ButtonWindow::ButtonWindow(QWidget *parent, Qt::WindowFlags flags):QMainWindow(parent, flags){
	this->setWindowTitle("This is window Title");
	QPushButton *button=new QPushButton("Click me ! ",this);
	button->setGeometry(50,30,70,20);
	connect(button, SIGNAL(clicked()),this,SLOT(Clicked()));
}

ButtonWindow::~ButtonWindow(){
}

void ButtonWindow::Clicked(void){
	std::cout<<"clicked\n";
}

int main(int argc, char **argv){
	QApplication app(argc,argv);
	ButtonWindow *window=new ButtonWindow();

	window->show();
	return app.exec();
}
