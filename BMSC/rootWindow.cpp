#include "rootWindow.h"

rootWindow::rootWindow(QWidget *parent)
    : QWidget(parent)
{
    ui_root.setupUi(this);
    w_console *widget_console = new w_console;
    widget_console->show();
    p_subwidget_console = widget_console;
    ui_root.widget_console->layout()->addWidget(widget_console);

    connect(ui_root.btn_serverSSControl, &QPushButton::clicked, this, &rootWindow::callLaunchServer);
}

//创建服务器核心，启动服务器
void rootWindow::callLaunchServer(void)
{
    setServerStatusLabel(0x10);
    serverCore* core = new serverCore;
    //启动核心，如果成功则初始化各部件
    //DEBUG 使用了模拟核心
    //QStringList arg = {""};
    bool isSuccessed = core->startServerCore("./Testing/SimulationConsole.exe");
    if (isSuccessed)
    {
        ((w_console*)p_subwidget_console)->initWidget(core);
    }
}

/*设置topBar显示的服务器状态
* 0x0X 0=停止(stopped)
* 0x1X 0=启动中(starting) 2=停止中(stopping)
* 0x2X 0=运行中(running)
*/
void rootWindow::setServerStatusLabel(char id)
{
    if (id == 0x00)
    {
        ui_root.label_serverStatus->setText("服务器未启动");
        ui_root.label_serverStatus->setProperty("status", "stopped");
    }
    if (id == 0x10)
    {
        ui_root.label_serverStatus->setText("服务器正在启动");
        ui_root.label_serverStatus->setProperty("status", "starting");
    }
    if (id == 0x11)
    {
        ui_root.label_serverStatus->setText("服务器正在停止");
        ui_root.label_serverStatus->setProperty("status", "stopping");
    }
    if (id == 0x20)
    {
        ui_root.label_serverStatus->setText("服务器运行中");
        ui_root.label_serverStatus->setProperty("status", "running");
    }
    ui_root.label_serverStatus->style()->polish(ui_root.label_serverStatus);
}


rootWindow::~rootWindow()
{}
