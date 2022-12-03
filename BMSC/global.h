#pragma once
#include <QString>

const uint PROGRAMBUILDVER = 0xA0000003;

struct LOGCONTENT
{
	QString rawText;
	QString content;
	QString from;
	long long timestamp;//unix时间戳，精确到秒
	char level = 0;//0=NULL 1=INFO 2=WARN 3=ERROR
	bool isSubLine = false;//是否为附属行
};