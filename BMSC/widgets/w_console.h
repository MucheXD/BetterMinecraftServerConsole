#pragma once

#include <QWidget>
#include <QDateTime>
#include <QRegularExpression>
#include "ui_w_console.h"
#include "../serverCore.h"
#include "../global.h"
#include "item_log.h"

class w_console : public QWidget
{
	Q_OBJECT

public:
	w_console(QWidget *parent = nullptr);
	void initWidget(serverCore* p_serverCore);
	~w_console();

private:
	void outputTest(QString msg);
	void processLog(QString rawText);
	Ui::w_consoleClass ui_wconsole;
};
