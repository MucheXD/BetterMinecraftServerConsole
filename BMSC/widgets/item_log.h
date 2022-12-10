#pragma once

#include <QtWidgets/QWidget>
#include <QFontMetrics>
#include "ui_item_log.h"
#include "../global.h"

class item_log : public QWidget
{
	Q_OBJECT

public:
	item_log(QWidget *parent = nullptr);
	void setContent(LOGCONTENT content);
	~item_log();
	
private:
	Ui::item_logClass ui_logitem;
};
