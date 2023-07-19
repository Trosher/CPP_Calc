#ifndef SRC_CPP_CALC_GRAFWIN_H
#define SRC_CPP_CALC_GRAFWIN_H

#include <QWidget>

#include "qcustomplot.h"

namespace Ui {
class GrafWin;
}

class GrafWin : public QWidget {
  Q_OBJECT

 public:
  explicit GrafWin(QWidget *parent = nullptr);
  ~GrafWin();
  void createGraf(std::pair<std::vector<double>, std::vector<double>> &xy,
                  std::pair<double, double> MaxMinY, double MinX, double MaxX);

 private:
  void qVectorFromStdVector(QVector<double> &Q, const std::vector<double> &V);
  Ui::GrafWin *ui;
};

#endif  // SRC_CPP_CALC_GRAFWIN_H
