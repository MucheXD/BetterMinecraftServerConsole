#pragma once

#include <QWidget>
#include "ui_item_log.h"

class item_log : public QWidget
{
	Q_OBJECT

public:
	item_log(QWidget *parent = nullptr);
	~item_log();
	Ui::item_logClass ui;
private:
	
};
