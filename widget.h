#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGlobal>
#include <QApplication>
#include <QtCore>
#include <QVariant>
#include <QDir>
#include <QDebug>
#include <iostream>

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
using namespace std;

// [0] include QXlsx headers
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel *lbl;
    QVBoxLayout *vbl;
    QPushButton *btnClose;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
