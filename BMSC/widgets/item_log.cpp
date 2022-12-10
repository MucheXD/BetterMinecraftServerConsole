#include "item_log.h"

item_log::item_log(QWidget *parent)
	: QWidget(parent)
{
	ui_logitem.setupUi(this);
}

void item_log::setContent(LOGCONTENT content)
{
	if (content.level == 1)
		ui_logitem.widget_root->setProperty("type", "info");
	if (content.level == 2)
		ui_logitem.widget_root->setProperty("type", "warning");
	if (content.level == 3)
		ui_logitem.widget_root->setProperty("type", "error");
	ui_logitem.widget_root->setStyle(ui_logitem.widget_root->style());
	QFontMetrics fontMetrics(ui_logitem.text->font());
	ui_logitem.text->setText(content.content);
}

item_log::~item_log()
{}
