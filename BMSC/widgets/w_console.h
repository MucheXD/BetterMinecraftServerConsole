#pragma once

#include <QWidget>
#include "ui_w_console.h"

class w_console : public QWidget
{
	Q_OBJECT

public:
	w_console(QWidget *parent = nullptr);
	~w_console();

private:
	Ui::w_consoleClass ui;
};
