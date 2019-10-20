#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lbl = new QLabel("Labl");
    vbl = new QVBoxLayout();
    btnClose = new QPushButton();
    btnClose->setText("Закрыть");

    vbl->addWidget(lbl);
    vbl->addWidget(btnClose);

    setLayout(vbl);


    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
    //    // [1]  Writing excel file(*.xlsx)
    //    QXlsx::Document xlsixW;
    //    xlsxW.write("A1", "Hello Qt!"); // write "Hello Qt!" to cell(A,1). it's shared string.
    //    if ( xlsxW.saveAs("Test.xlsx") ) // save the document as 'Test.xlsx'
    //    {
    //        qDebug() << "[debug] success to write xlsx file";
    //    }
    //    else
    //    {
    //        qDebug() << "[debug][error] failed to write xlsx file";
    //    }

    //    qDebug() << "[debug] current directory is " << QDir::currentPath();

    // [2] Reading excel file(*.xlsx)
    Document xlsxR("1.xlsx");

    if ( xlsxR.load() ) // load excel file
    {
        qDebug() << "[debug] success to load xlsx file.";

        //            for (int i = 0; i < 50; i++)
        //            {
        //                qDebug() << i;
        //                Cell* cell1 = xlsxR.cellAt(i,5) ;
        //                QVariant var = cell1->readValue();
        //                qDebug() << "Значение : " << var.toInt();
        //            }


        //            int row = 7; int col =5;
        //           Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.


        Cell* cell;
        for (int i = 7; i < 50; i++)
        {
            Cell* cell = xlsxR.cellAt(i, 5); // get cell pointer.
            if ( cell != NULL )
            {

                QVariant var = cell->readValue();
                qDebug() << "[" << i << "]" <<"Значение : " << var.toInt();


                //                QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                //                qDebug() << "[debug] cell(1,1) is " << var; // Display value. It is 'Hello Qt!'.
            }
            else
            {
                qDebug() << "[debug][error] cell(1,1) is not set.";
            }
        }

    }
    else
    {
        qDebug() << "[debug][error] failed to load xlsx file.";
    }
}

Widget::~Widget()
{

}

