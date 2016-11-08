/*
Dwarf Therapist
Copyright (c) 2009 Trey Stout (chmod)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QDialog>
#include <QDesktopWidget>
#include <QPropertyAnimation>

#include "ui_notification.h"
#include "notifierwidget.h"

class NotificationWidget : public QFrame {
    Q_OBJECT
public:
    NotificationWidget(NotifierWidget::notify_info ni, NotifierWidget *parent = 0);
    ~NotificationWidget();

     void display(NotifierWidget::notify_info ni);

private:
    Ui::NotificationWidget *ui;
    QPropertyAnimation *m_fader;
    bool m_mouse_hover;

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private slots:
    void close_notification();
    void url_clicked(const QString &url);
    void fade_out_start();
    void opacity_changed(qreal);

signals:
    void closed();

};
#endif // NOTIFICATION_H
