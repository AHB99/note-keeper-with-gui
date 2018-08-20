#pragma once

#include <QWidget>
#include "ui_TestWidg.h"

class TestWidg : public QWidget, public Ui::TestWidg
{
	Q_OBJECT

public:
	TestWidg(QWidget *parent = Q_NULLPTR);
	~TestWidg();
};
