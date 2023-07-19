#include "grafwin.h"

#include "ui_grafwin.h"

GrafWin::GrafWin(QWidget *parent) : QWidget(parent), ui(new Ui::GrafWin()) {
  ui->setupUi(this);
}

GrafWin::~GrafWin() { delete ui; }

void GrafWin::qVectorFromStdVector(QVector<double> &Q,
                                   const std::vector<double> &V) {
  for (auto it : V) {
    Q.append(it);
  }
}

void GrafWin::createGraf(
    std::pair<std::vector<double>, std::vector<double>> &xy,
    std::pair<double, double> MaxMinY, double MinX, double MaxX) {
  QVector<double> x, y;
  ui->widget->clearGraphs();
  ui->widget->xAxis->setRange(MinX - (abs(MinX) * 0.1),
                              MaxX + (abs(MaxX) * 0.1));
  ui->widget->yAxis->setRange(MaxMinY.second - (abs(MaxMinY.second) * 0.1),
                              MaxMinY.first + (abs(MaxMinY.first) * 0.1));
  ui->widget->addGraph();
  qVectorFromStdVector(x, xy.first);
  qVectorFromStdVector(y, xy.second);
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
}
