#pragma once

#include <QProcess>
#include <QString>
class serverCore : public QObject
{
	Q_OBJECT
public:
	serverCore(void);
	void inputTOCore(QString str);
	bool startServerCore(QString serverPath, QStringList arguments = {}, int timeout = 5000);
private:
	QProcess *serverCoreProcess;
	void stdOutputForwarding(void);
	void errOutputForwarding(void);
signals:
	void coreStdOutput(QString msg);
	void coreErrOutput(QString msg);
};

