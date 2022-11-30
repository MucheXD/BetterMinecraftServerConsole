#include "rootWindow.h"

rootWindow::rootWindow(QWidget *parent)
    : QWidget(parent)
{
    ui_root.setupUi(this);
    w_console *widget_console = new w_console;
    widget_console->show();
    ui_root.widget_console->layout()->addWidget(widget_console);

    connect(ui_root.btn_serverSSControl, &QPushButton::clicked, this, &rootWindow::callLaunchServer);

}

void rootWindow::callLaunchServer(void)
{
    serverCore* core = new serverCore;
    bool isSuccessed = core->startServerCore("./Testing/SimulationConsole.exe");
    connect(core, &serverCore::coreStdOutput, this, &rootWindow::outputTest);
}

void rootWindow::outputTest(QString msg)
{
    qDebug() << msg;
}

rootWindow::~rootWindow()
{}
