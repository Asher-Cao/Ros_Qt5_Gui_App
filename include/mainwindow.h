/*
 * @Author: chengyangkj chengyangkj@qq.com
 * @Date: 2023-10-01 06:31:04
 * @LastEditors: chengyangkj chengyangkj@qq.com
 * @LastEditTime: 2023-10-06 06:30:27
 * @FilePath: /examples/centralwidget/mainwindow.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DockAreaWidget.h"
#include "DockManager.h"
#include "DockWidget.h"
#include "display/display_manager.h"
#include <QCalendarWidget>
#include <QComboBox>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QGraphicsItem>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QProgressBar>
#include <QMainWindow>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSettings>
#include <QTableWidget>
#include <QToolBar>
#include <QTreeView>
#include <QWidgetAction>
QT_BEGIN_NAMESPACE
namespace Ui {
class CMainWindow;
}
QT_END_NAMESPACE

class CMainWindow : public QMainWindow {
  Q_OBJECT

public:
  CMainWindow(QWidget *parent = nullptr);
  ~CMainWindow();

protected:
  virtual void closeEvent(QCloseEvent *event) override;

private:
  QAction *SavePerspectiveAction = nullptr;
  QWidgetAction *PerspectiveListAction = nullptr;
  QComboBox *PerspectiveComboBox = nullptr;

  Ui::CMainWindow *ui;

  ads::CDockManager *dock_manager_;
  ads::CDockAreaWidget *StatusDockArea;
  ads::CDockWidget *TimelineDockWidget;
  Display::DisplayManager *display_manager_;
  QLabel *label_time_;
  QPushButton *pushButton_status_;
  QProgressBar *battery_bar_;
  QLabel *label_battery_v_;
  private : void setupUi();
private slots:
  void savePerspective();
};
#endif // MAINWINDOW_H
