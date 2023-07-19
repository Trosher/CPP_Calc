#ifndef SRC_CPP_CALC_MODEL_H
#define SRC_CPP_CALC_MODEL_H

#include <math.h>

#include <queue>
#include <stack>
#include <string>
#include <vector>

namespace s21 {

class Model {
 public:
  Model(const Model &) = delete;
  Model(Model &&) = delete;
  Model &operator=(const Model &) = delete;
  Model &operator=(Model &&) = delete;
  static Model& getInstance();
  ~Model();

  bool additionalOpUse();
  void acUse();
  std::string delLastChar(std::string str);
  std::string checkCharValid(std::string str, const std::string ch);
  std::string keyPressEvent(const int index_sim, const std::string sim,
                            std::string str);
  std::string resultEventCalc(std::string str, double X);
  bool checkXStatus();
  std::pair<std::vector<double>, std::vector<double>> ResToGraf(std::string str,
                                                                double MaxX,
                                                                double MinX);
  std::pair<double, double> maxMinY(
      std::pair<std::vector<double>, std::vector<double>> xy);

 public:
  Model();

  std::string getResult(std::string &str, double X);
  double getNum(std::string &str, unsigned &i);
  double calc(std::stack<std::pair<double, char>> &pol_stack,
              std::queue<std::pair<double, char>> &pol_que);
  void unarOpTransform(std::string &str,
                       std::stack<std::pair<double, char>> &pol_stack,
                       std::queue<std::pair<double, char>> &pol_que,
                       unsigned &i);
  void strToPolQue(std::string &str,
                   std::stack<std::pair<double, char>> &pol_stack,
                   std::queue<std::pair<double, char>> &pol_que, double X);
  int checkPrior(char op);
  void pushStekToQue(char &op, std::stack<std::pair<double, char>> &pol_stack,
                     std::queue<std::pair<double, char>> &pol_que);
  void binCalc(std::stack<std::pair<double, char>> &pol_stack,
               std::queue<std::pair<double, char>> &pol_que);
  void unarCalc(std::stack<std::pair<double, char>> &pol_stack,
                std::queue<std::pair<double, char>> &pol_que);
  void delZeroForNum(std::string &str);
  bool strInStr(std::string &str, unsigned &i, std::string op_str);
  void charCheck(std::string &str, const std::string ch);
  void unrOpCheck(std::string &str, const std::string ch);
  void binOpCheck(std::string &str, const std::string ch);
  void numPoinExpCheck(std::string str);
  void pointCheck(std::string &str, const std::string ch);
  void expCheck(std::string &str, const std::string ch);
  void numCheck(std::string &str, const std::string ch);
  void closeBrCheck(std::string &str, const std::string ch);
  bool isNum(const char c);
  bool isBinOp(const char c);
  bool noNumChar(const char c);

 private:
  const int allKey_[21] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 46,
                           43, 45, 47, 42, 94, 40, 41, 88, 69, 32};
  bool additionalOpStat_;
  unsigned countOpenBr_;
  unsigned countCloseBr_;
  bool pointFlag_;
  bool pointZero_;
  unsigned pointX_;
  bool pointRes_;
  bool expPoint_;
};  // Model

};  // namespace s21

#endif  // SRC_CPP_CALC_MODEL_H
