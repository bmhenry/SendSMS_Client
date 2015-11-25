/********************************************************************************
** Form generated from reading UI file 'threadlistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADLISTITEM_H
#define UI_THREADLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreadListItem
{
public:
    QLabel *titleLabel;
    QLabel *textLabel;

    void setupUi(QWidget *ThreadListItem)
    {
        if (ThreadListItem->objectName().isEmpty())
            ThreadListItem->setObjectName(QStringLiteral("ThreadListItem"));
        ThreadListItem->resize(200, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ThreadListItem->sizePolicy().hasHeightForWidth());
        ThreadListItem->setSizePolicy(sizePolicy);
        ThreadListItem->setMinimumSize(QSize(200, 100));
        ThreadListItem->setMaximumSize(QSize(200, 100));
        titleLabel = new QLabel(ThreadListItem);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(10, 10, 91, 21));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        titleLabel->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        titleLabel->setFont(font);
        textLabel = new QLabel(ThreadListItem);
        textLabel->setObjectName(QStringLiteral("textLabel"));
        textLabel->setGeometry(QRect(10, 30, 161, 16));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        textLabel->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("Corbel"));
        font1.setPointSize(10);
        textLabel->setFont(font1);

        retranslateUi(ThreadListItem);

        QMetaObject::connectSlotsByName(ThreadListItem);
    } // setupUi

    void retranslateUi(QWidget *ThreadListItem)
    {
        ThreadListItem->setWindowTitle(QApplication::translate("ThreadListItem", "Form", 0));
        titleLabel->setText(QApplication::translate("ThreadListItem", "TitleLabel", 0));
        textLabel->setText(QApplication::translate("ThreadListItem", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ThreadListItem: public Ui_ThreadListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADLISTITEM_H
