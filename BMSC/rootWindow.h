#pragma once

#include <QtWidgets/QWidget>
#include <QStringList>
#include <QDebug>
#include "ui_rootWindow.h"
#include "widgets/w_console.h"
#include "serverCore.h"

class rootWindow : public QWidget
{
    Q_OBJECT

public:
    rootWindow(QWidget *parent = nullptr);
    ~rootWindow();

private:
    void callLaunchServer(void);
    void setServerStatusLabel(char id);
    Ui::rootWindowClass ui_root;
    void* p_subwidget_console;
};
