#include "controller.h"

using namespace s21;

Controller::Controller(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Controller),
      model(Model::getInstance()),
      uiGraf(std::make_unique<GrafWin>()) {
  ui->setupUi(this);
  ui->InputWindow->setText(" ");
}

Controller &Controller::getInstance() {
  static Controller controller;
  return controller;
}

Controller::~Controller() { delete ui; }

void Controller::on_AdditionalOp_buton_clicked() {
  if (model.additionalOpUse()) {
    ui->AdditionalOp_buton->setText("↩");
    this->setFixedSize(619, 470);
    ui->InputWindow->setFixedSize(581, 81);
  } else {
    ui->AdditionalOp_buton->setText("↪");
    this->setFixedSize(330, 470);
    ui->InputWindow->setFixedSize(290, 81);
  }
}

void Controller::on_AC_buton_clicked() {
  ui->InputWindow->setText(" ");
  model.acUse();
}

void Controller::on_BackSpase_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.delLastChar(ui->InputWindow->text().toStdString())));
}

void Controller::on_Div_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "/")));
}

void Controller::on_Mult_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "*")));
}

void Controller::on_Sub_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "-")));
}

void Controller::on_Sum_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "+")));
}

void Controller::on_degree_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "^")));
}

void Controller::on_Seven_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "7")));
}

void Controller::on_Four_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "4")));
}

void Controller::on_One_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "1")));
}

void Controller::on_Point_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), ".")));
}

void Controller::on_Eight_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "8")));
}

void Controller::on_Five_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "5")));
}

void Controller::on_Two_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "2")));
}

void Controller::on_Zero_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "0")));
}

void Controller::on_Nine_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "9")));
}

void Controller::on_Six_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "6")));
}

void Controller::on_Three_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "3")));
}

void Controller::on_DivWithRem_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "%")));
}

void Controller::on_cos_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "cos(")));
}

void Controller::on_acos_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "acos(")));
}

void Controller::on_sqrt_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "sqrt(")));
}

void Controller::on_open_breck_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "(")));
}

void Controller::on_sin_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "sin(")));
}

void Controller::on_asin_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "asin(")));
}

void Controller::on_ln_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "ln(")));
}

void Controller::on_close_breck_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), ")")));
}

void Controller::on_tan_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "tan(")));
}

void Controller::on_atan_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "atan(")));
}

void Controller::on_log_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "log(")));
}

void Controller::on_x_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "X")));
}

void Controller::on_Exp_buton_clicked() {
  ui->InputWindow->setText(QString::fromStdString(
      model.checkCharValid(ui->InputWindow->text().toStdString(), "e")));
}

void Controller::on_Eqal_buton_clicked() {
  if (model.checkXStatus()) {
    std::pair<std::vector<double>, std::vector<double>> xy =
        model.ResToGraf(ui->InputWindow->text().toStdString(),
                        ui->MaxX_Box->value(), ui->MinX_Box->value());
    if (xy.first.empty()) {
      ui->InputWindow->setText(" ");
      QMessageBox::warning(
          this, "Warning",
          "Error during plotting or incorrectly set MaxX, Minx parameters");
    } else {
      uiGraf->show();
      uiGraf->createGraf(xy, model.maxMinY(xy), ui->MinX_Box->value(),
                         ui->MaxX_Box->value());
    }
  } else {
    QString res = QString::fromStdString(
        model.resultEventCalc(ui->InputWindow->text().toStdString(), 0));
    if (res[0] == 'E') {
      ui->InputWindow->setText(" ");
      QMessageBox::warning(this, "Warning",
                           "There is an error in the equation or the result of "
                           "the calculation is invalid");
    } else {
      ui->InputWindow->setText(res);
    }
  }
}

void Controller::keyPressEvent(QKeyEvent *e) {
  if (e->key() == Qt::Key_Equal) {
    on_Eqal_buton_clicked();
  } else {
    ui->InputWindow->setText(QString::fromStdString(
        model.keyPressEvent(e->key(), e->text().toStdString(),
                            ui->InputWindow->text().toStdString())));
  }
}
