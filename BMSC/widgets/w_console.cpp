#include "w_console.h"

w_console::w_console(QWidget *parent)
	: QWidget(parent)
{
	ui_wconsole.setupUi(this);
}

void w_console::initWidget(serverCore* p_serverCore)
{
	connect(p_serverCore, &serverCore::coreStdOutput, this, &w_console::processLog);
}

//处理日志
void w_console::processLog(QString rawText)
{
	LOGCONTENT logContent;
	QRegularExpression regExp;
	QRegularExpressionMatch matchResult;
	//匹配开头时间戳，若无则为附属行
	regExp.setPattern("^\\[[0-9]{1,2}:[0-9]{1,2}:[0-9]{1,2}]");
	matchResult = regExp.match(rawText);
	logContent.isSubLine = !matchResult.hasMatch();
	//TODO 此处未保存日期，可以通过获取当前日期补充
	if (!logContent.isSubLine)
		logContent.timestamp = QDateTime::fromString(
			matchResult.captured().replace(QRegularExpression("[\\[\\]]"), ""),
			"hh:mm:ss").toSecsSinceEpoch();
	//删除已识别的部分，+1以删去空格(或其他未包括字符)，下不再赘述
	rawText.remove(matchResult.capturedStart(), matchResult.capturedLength() + 1);
	//匹配消息类型(发起者+等级) Eg.[Server thread/INFO]:
	if (!logContent.isSubLine)//附属行一定没有消息类型声明，充分非必要条件
	{
		regExp.setPattern("^\\[.*/.*\\]:");
		matchResult = regExp.match(rawText);
		//匹配消息发起者 Eg.Server thread
		regExp.setPattern("^\\[.*/");
		logContent.from = regExp.match(matchResult.captured())
			.captured().replace(QRegularExpression("[\\[\\/]"), "");
		//匹配消息等级标识 Eg.INFO
		regExp.setPattern("/.*]:$");
		QString levelText = regExp.match(matchResult.captured())
			.captured().replace(QRegularExpression("[\\/\\]:]"), "");
		//将等级标识转换为等级ID
		if (levelText == "INFO")
			logContent.level = 1;
		if (levelText == "WARN")
			logContent.level = 2;
		if (levelText == "ERROR")
			logContent.level = 3;
		rawText.remove(matchResult.capturedStart(), matchResult.capturedLength() + 1);
	}
	else //如果是附属行，删除其前面多余的空格
		rawText.remove(QRegularExpression("^\\s*"));
	//剩下的为正文，去除可能的前后空白符
	logContent.content = rawText.remove(QRegularExpression("^\\s*")).remove(QRegularExpression("\\s*$"));
	qDebug() 
		<< "(" << logContent.from
		<< "," << (int)logContent.level
		<< ")" << logContent.content;
}

void w_console::outputTest(QString msg)
{
	QListWidgetItem* listwidgetItem = new QListWidgetItem();
	listwidgetItem->setSizeHint(QSize(0, 25));
	item_log* logItem = new item_log;
	//item->ui.icon->setPixmap(QPixmap(":/typeIcons/res/type_ServerMain.svg"));
	logItem->ui.text->setText(msg.replace("\n",""));
	ui_wconsole.list_logTable->addItem(listwidgetItem);
	ui_wconsole.list_logTable->setItemWidget(listwidgetItem, logItem);
}

w_console::~w_console()
{}
