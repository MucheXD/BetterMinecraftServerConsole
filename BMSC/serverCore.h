#pragma once
#include <QProcess>
#include <QString>
class serverCore
{
public:
	serverCore(void);
	bool startServerCore(QString serverPath, QStringList arguments = {}, int timeout = 5000);
private:
	
	QProcess *serverCoreProcess;
};

