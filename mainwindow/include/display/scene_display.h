#pragma once
#include "display/point_shape.h"
#include "widgets/set_pose_widget.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <display/virtual_display.h>
namespace Display {
class DisplayManager;
class SceneDisplay : public QGraphicsScene {
private:
  SetPoseWidget *set_nav_pose_widget_;
  QGraphicsView *view_ptr_;
  Display::VirtualDisplay *curr_handle_display_{nullptr};
  DisplayManager *display_manager_;

public:
  SceneDisplay(QObject *parent = nullptr);
  virtual ~SceneDisplay() = default;
  void Init(QGraphicsView *view_ptr, DisplayManager *manager);
  void AddOneNavGoal();

private:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
};
} // namespace Display