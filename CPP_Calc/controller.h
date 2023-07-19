#ifndef SRC_CPP_CALC_CONTROLLER_H
#define SRC_CPP_CALC_CONTROLLER_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>

#include "./ui_view.h"
#include "grafwin.h"
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Controller;
}
QT_END_NAMESPACE

class Controller : public QMainWindow {
  Q_OBJECT

 public:
  static Controller& getInstance();
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;
  ~Controller();

 private slots:

  void on_AdditionalOp_buton_clicked();

  void on_AC_buton_clicked();

  void on_BackSpase_buton_clicked();

  void on_Div_buton_clicked();

  void on_Mult_buton_clicked();

  void on_Sub_buton_clicked();

  void on_Sum_buton_clicked();

  void on_degree_buton_clicked();

  void on_Seven_buton_clicked();

  void on_Four_buton_clicked();

  void on_One_buton_clicked();

  void on_Point_buton_clicked();

  void on_Eight_buton_clicked();

  void on_Five_buton_clicked();

  void on_Two_buton_clicked();

  void on_Zero_buton_clicked();

  void on_Nine_buton_clicked();

  void on_Six_buton_clicked();

  void on_Three_buton_clicked();

  void on_DivWithRem_buton_clicked();

  void on_cos_buton_clicked();

  void on_acos_buton_clicked();

  void on_sqrt_buton_clicked();

  void on_open_breck_buton_clicked();

  void on_sin_buton_clicked();

  void on_asin_buton_clicked();

  void on_ln_buton_clicked();

  void on_close_breck_buton_clicked();

  void on_tan_buton_clicked();

  void on_atan_buton_clicked();

  void on_log_buton_clicked();

  void on_x_buton_clicked();

  void on_Eqal_buton_clicked();

  void on_Exp_buton_clicked();

 private:
  Controller(QWidget* parent = nullptr);

  std::unique_ptr<GrafWin> uiGraf;
  Ui::Controller* ui;
  s21::Model& model;

 protected:
  void keyPressEvent(QKeyEvent* e) override;
};      // Controller
#endif  // SRC_CPP_CALC_CONTROLLER_H
