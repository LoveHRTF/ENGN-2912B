#ifndef __ABOUTDIALOG_HPP__
#define __ABOUTDIALOG_HPP__

#include <QDialog>

// This file is created by QT from the file AboutDialog.ui
#include "ui_AboutDialog.h"

class AboutDialog : public QDialog, public Ui::AboutDialog {
  Q_OBJECT

public:
  AboutDialog(QWidget * parent = 0, Qt::WindowFlags flags = 0);
  ~AboutDialog();

public slots:
  void on_close_button_clicked() { accept(); }
};


#endif  /* __ABOUTDIALOG_HPP__ */
