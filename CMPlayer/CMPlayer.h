#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CMPlayer.h"

class CMPlayer : public QMainWindow
{
    Q_OBJECT

public:
    CMPlayer(QWidget *parent = Q_NULLPTR);

private:
    Ui::CMPlayerClass ui;
};
