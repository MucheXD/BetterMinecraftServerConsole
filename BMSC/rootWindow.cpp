#include "rootWindow.h"

rootWindow::rootWindow(QWidget *parent)
    : QWidget(parent)
{
    ui_root.setupUi(this);
    w_console *widget_console = new w_console;
    widget_console->show();
    ui_root.widget_console->layout()->addWidget(widget_console);

    connect(ui_root.btn_serverSSControl, &QPushButton::clicked, this, &rootWindow::callLaunchServer);
    //example->setReadChannel(QProcess::StandardOutput);
    /*connect(serverCoreProcess, &QProcess::readyReadStandardOutput, this, &rootWindow::stdOutput);
    connect(serverCoreProcess, &QProcess::readyReadStandardError, this, &rootWindow::errOutPut);
    connect(ui_root.btn_commandSend, &QPushButton::clicked, this, &QProcessTest::strInput);
    example->start("cmd");
    example->waitForStarted();*/

}

void rootWindow::callLaunchServer(void)
{
    serverCore* core = new serverCore;
    core->startServerCore("");
}

rootWindow::~rootWindow()
{}
