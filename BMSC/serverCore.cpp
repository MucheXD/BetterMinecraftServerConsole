#include "serverCore.h"
serverCore::serverCore()
{
	serverCoreProcess = new QProcess;
}

bool serverCore::startServerCore(QString serverPath, QStringList arguments, int timeout)
{
	serverCoreProcess->start(serverPath, arguments);
	return serverCoreProcess->waitForStarted();
}