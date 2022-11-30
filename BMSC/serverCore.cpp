#include "serverCore.h"
serverCore::serverCore()
{
	serverCoreProcess = new QProcess;
}

bool serverCore::startServerCore(QString serverPath, QStringList arguments, int timeout)
{
	connect(serverCoreProcess, &QProcess::readyReadStandardOutput, this, &serverCore::stdOutputForwarding);
	connect(serverCoreProcess, &QProcess::readyReadStandardError, this, &serverCore::errOutputForwarding);
		serverCoreProcess->start(serverPath, arguments);
	if (!serverCoreProcess->waitForStarted())
		return false;
	else
		return true;
}

void serverCore::inputTOCore(QString str)
{
	
}

void serverCore::stdOutputForwarding(void)
{
	emit coreStdOutput(serverCoreProcess->readAllStandardOutput());
}

void serverCore::errOutputForwarding(void)
{
	emit coreErrOutput(serverCoreProcess->readAllStandardError());
}