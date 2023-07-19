#include "model.h"

using namespace s21;

Model::Model()
    : additionalOpStat_(false),
      countOpenBr_(0),
      countCloseBr_(0),
      pointFlag_(true),
      pointZero_(true),
      pointX_(0),
      pointRes_(false),
      expPoint_(true) {
  ;
}

Model& Model::getInstance() {
  static Model model;
  return model;
}

Model::~Model() { ; }

// The interaction functions with ui

void Model::acUse() {
  additionalOpStat_ = false;
  countOpenBr_ = 0;
  countCloseBr_ = 0;
  pointFlag_ = true;
  pointZero_ = true;
  pointX_ = 0;
  pointRes_ = false;
  expPoint_ = true;
}

bool Model::additionalOpUse() { return additionalOpStat_ = !additionalOpStat_; }

bool Model::isNum(const char c) {
  return ((c >= '0' && c <= '9') || c == 'X');
}

bool Model::isBinOp(const char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

bool Model::noNumChar(const char c) { return (c != ')' && c != 'X'); }

void Model::numPoinExpCheck(std::string str) {
  size_t i = str.size() - 2;
  while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == 'e') {
    if (str[i] == '.') {
      pointFlag_ = false;
    } else if (str[i] == 'e') {
      expPoint_ = false;
    }
    i--;
  }
}

std::string Model::delLastChar(std::string str) {
  char Last_char_str = str.back();
  if (pointRes_ == true) {
    str = " ";
    acUse();
  } else if (str.size() != 1) {
    if (pointFlag_ || expPoint_) {
      numPoinExpCheck(str);
    }
    if (Last_char_str == ')') {
      countCloseBr_ -= 1;
    } else if (Last_char_str == '(') {
      countOpenBr_ -= 1;
    } else if (Last_char_str == 'X') {
      pointX_ -= 1;
    } else if (Last_char_str == '.') {
      pointFlag_ = true;
    } else if (Last_char_str == 'e') {
      pointFlag_ = expPoint_ = true;
    } else if (!pointZero_ && Last_char_str == '0') {
      pointZero_ = true;
    }
    if (Last_char_str != ' ') {
      str.resize(str.size() - 1);
      if (pointFlag_ && !expPoint_) {
        numPoinExpCheck(str);
      }
    }
    if (str.back() != 'e' && str.back() != 'X') {
      for (size_t i = str.size() - 1; str[i] >= 'a' && str[i] <= 'z'; i--) {
        str.resize(str.size() - 1);
      }
    }
  }
  return str;
}

void Model::closeBrCheck(std::string &str, const std::string ch) {
  if ((isNum(str.back()) || str.back() == ')') &&
      countOpenBr_ > countCloseBr_) {
    str += ch;
    countCloseBr_ += 1;
  }
}

void Model::pointCheck(std::string &str, const std::string ch) {
  char Last_char_str = str.back();
  if (isNum(Last_char_str) && pointFlag_ && Last_char_str != 'X') {
    str += ch;
    pointFlag_ = false;
    pointZero_ = true;
  }
}

void Model::numCheck(std::string &str, const std::string ch) {
  char Last_char_str = str.back();
  if (ch[0] == '0' && noNumChar(Last_char_str)) {
    if (!isNum(Last_char_str) && Last_char_str != '.' && pointZero_) {
      str += ch;
      pointZero_ = false;
    } else if (pointZero_) {
      str += ch;
    }
  } else if (ch[0] == 'X' && !isNum(Last_char_str) &&
             noNumChar(Last_char_str)) {
    str += ch;
    pointX_ += 1;
  } else if (ch[0] != 'X' && noNumChar(Last_char_str)) {
    str += ch;
  }
}

void Model::binOpCheck(std::string &str, const std::string ch) {
  char Last_char_str = str.back();
  if ((ch[0] == '+' || ch[0] == '-') &&
      (isNum(Last_char_str) || Last_char_str == '(' || Last_char_str == ')' ||
       Last_char_str == ' ' || Last_char_str == 'e')) {
    str += ch;
    if (Last_char_str != 'e') {
      expPoint_ = true;
      pointFlag_ = true;
      pointZero_ = true;
    }
  } else if (isNum(Last_char_str) || Last_char_str == ')') {
    str += ch;
    pointFlag_ = true;
    expPoint_ = true;
    pointZero_ = true;
  }
}

void Model::unrOpCheck(std::string &str, const std::string ch) {
  char Last_char_str = str.back();
  if (isBinOp(Last_char_str) || Last_char_str == ' ' || Last_char_str == '(') {
    str += ch;
    countOpenBr_ += 1;
  }
}

void Model::expCheck(std::string &str, const std::string ch) {
  char Last_char_str = str.back();
  if (isNum(Last_char_str) && expPoint_) {
    str += ch;
    expPoint_ = false;
    pointFlag_ = false;
  }
}

std::string Model::checkCharValid(std::string str, const std::string ch) {
  if (pointRes_ == true) {
    str = " ";
    acUse();
  }
  if (isNum(ch[0])) {
    numCheck(str, ch);
  } else if (isBinOp(ch[0])) {
    binOpCheck(str, ch);
  } else if (ch[0] == ')') {
    closeBrCheck(str, ch);
  } else if (ch[0] == '.') {
    pointCheck(str, ch);
  } else if (ch[0] == 'e') {
    expCheck(str, ch);
  } else {
    unrOpCheck(str, ch);
  }
  return str;
}

std::string Model::keyPressEvent(const int index_sim, const std::string sim,
                                 std::string str) {
  for (int i = 0; i < 18; i++) {
    if (allKey_[i] == index_sim) {
      str = checkCharValid(str, sim);
    }
  }
  if (allKey_[18] == index_sim) {
    str = checkCharValid(str, "X");
  } else if (allKey_[19] == index_sim) {
    str = checkCharValid(str, "e");
  } else if (allKey_[20] == index_sim) {
    str = delLastChar(str);
  }
  return str;
}

// Functions of the Polish calculator

double Model::getNum(std::string &str, unsigned &i) {
  std::string Num_str;
  while (i < str.size() && (isNum(str[i]) || str[i] == '.' || str[i] == 'e' ||
                            (str[i] == '-' && Num_str.back() == 'e') ||
                            (str[i] == '+' && Num_str.back() == 'e'))) {
    Num_str += str[i];
    ++i;
  }
  --i;
  return std::stod(Num_str);
}

int Model::checkPrior(char op) {
  int prior = -1;
  if (op == '-' || op == '+') {
    prior = 1;
  } else if (op == '*' || op == '/' || op == '%') {
    prior = 2;
  } else if (op == '^') {
    prior = 4;
  } else if (op != '(' && op != ')') {
    prior = 3;
  }
  return prior;
}

void Model::pushStekToQue(char &op,
                           std::stack<std::pair<double, char>> &pol_stack,
                           std::queue<std::pair<double, char>> &pol_que) {
  int prior = checkPrior(op), steck_prior, end_cycle = 1;
  while (!pol_stack.empty() && end_cycle) {
    steck_prior = checkPrior(pol_stack.top().second);
    if ((steck_prior >= prior || steck_prior == -1) && prior != -1) {
      if ((prior == 4 && prior == steck_prior) || steck_prior == -1) {
        pol_stack.push({0, op});
        end_cycle = 0;
      } else {
        pol_que.push(pol_stack.top());
        pol_stack.pop();
      }
    } else if (prior == -1) {
      if (op == '(') {
        pol_stack.push({0, op});
        end_cycle = 0;
      } else if (pol_stack.top().second != '(') {
        pol_que.push(pol_stack.top());
        pol_stack.pop();
      } else {
        pol_stack.pop();
        end_cycle = 0;
      }
    } else {
      pol_stack.push({0, op});
      end_cycle = 0;
    }
  }
  if (end_cycle) {
    pol_stack.push({0, op});
  }
}

bool Model::strInStr(std::string &str, unsigned &i, std::string op_str) {
  bool res = true;
  size_t j = 0;
  for (; j < op_str.size() && res; j++, i++) {
    if (str[i] != op_str[j]) {
      res = false;
    }
  }
  if (res == false) {
    i -= j;
  } else {
    i -= 1;
  }
  return res;
}

void Model::unarOpTransform(std::string &str,
                             std::stack<std::pair<double, char>> &pol_stack,
                             std::queue<std::pair<double, char>> &pol_que,
                             unsigned &i) {
  char UnarOp;
  if (strInStr(str, i, "cos")) {
    UnarOp = '1';
  } else if (strInStr(str, i, "sin")) {
    UnarOp = '2';
  } else if (strInStr(str, i, "tan")) {
    UnarOp = '3';
  } else if (strInStr(str, i, "acos")) {
    UnarOp = '4';
  } else if (strInStr(str, i, "asin")) {
    UnarOp = '5';
  } else if (strInStr(str, i, "atan")) {
    UnarOp = '6';
  } else if (strInStr(str, i, "sqrt")) {
    UnarOp = '7';
  } else if (strInStr(str, i, "ln")) {
    UnarOp = '8';
  } else if (strInStr(str, i, "log")) {
    UnarOp = '9';
  }
  if (pol_stack.empty()) {
    pol_stack.push({0, UnarOp});
  } else {
    pushStekToQue(UnarOp, pol_stack, pol_que);
  }
}

void Model::strToPolQue(std::string &str,
                         std::stack<std::pair<double, char>> &pol_stack,
                         std::queue<std::pair<double, char>> &pol_que,
                         double X) {
  for (unsigned i = 1; i < str.size(); i++) {
    if (isNum(str[i])) {
      if (str[i] == 'X') {
        pol_que.push({X, ' '});
      } else {
        pol_que.push(std::make_pair(getNum(str, i), ' '));
      }
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      unarOpTransform(str, pol_stack, pol_que, i);
    } else {
      if (pol_stack.empty() && str[i] != '-' && str[i] != '+') {
        pol_stack.push({0, str[i]});
      } else {
        if ((str[i] == '-' || str[i] == '+') &&
            (str[i - 1] == '(' || str[i - 1] == ' ')) {
          char op = str[i] == '+' ? 'p' : 'm';
          pushStekToQue(op, pol_stack, pol_que);
        } else {
          pushStekToQue(str[i], pol_stack, pol_que);
        }
      }
    }
  }
  while (!pol_stack.empty()) {
    pol_que.push(pol_stack.top());
    pol_stack.pop();
  }
}

void Model::binCalc(std::stack<std::pair<double, char>> &pol_stack,
                     std::queue<std::pair<double, char>> &pol_que) {
  double num = pol_stack.top().first;
  char op = pol_que.front().second;
  pol_que.pop();
  pol_stack.pop();
  if (op == '+') {
    pol_stack.top().first = pol_stack.top().first + num;
  } else if (op == '-') {
    pol_stack.top().first = pol_stack.top().first - num;
  } else if (op == '*') {
    pol_stack.top().first = pol_stack.top().first * num;
  } else if (op == '/') {
    pol_stack.top().first = pol_stack.top().first / num;
  } else if (op == '^') {
    pol_stack.top().first = pow(pol_stack.top().first, num);
  } else if (op == '%') {
    pol_stack.top().first = fmod(pol_stack.top().first, num);
  }
}

void Model::unarCalc(std::stack<std::pair<double, char>> &pol_stack,
                      std::queue<std::pair<double, char>> &pol_que) {
  char op = pol_que.front().second;
  pol_que.pop();
  if (op == '1') {
    pol_stack.top().first = cos(pol_stack.top().first);
  } else if (op == '2') {
    pol_stack.top().first = sin(pol_stack.top().first);
  } else if (op == '3') {
    pol_stack.top().first = tan(pol_stack.top().first);
  } else if (op == '4') {
    pol_stack.top().first = acos(pol_stack.top().first);
  } else if (op == '5') {
    pol_stack.top().first = asin(pol_stack.top().first);
  } else if (op == '6') {
    pol_stack.top().first = atan(pol_stack.top().first);
  } else if (op == '7') {
    pol_stack.top().first = sqrt(pol_stack.top().first);
  } else if (op == '8') {
    pol_stack.top().first = log(pol_stack.top().first);
  } else if (op == '9') {
    pol_stack.top().first = log10(pol_stack.top().first);
  } else if (op == 'p') {
    pol_stack.top().first = fabs(pol_stack.top().first);
  } else if (op == 'm') {
    pol_stack.top().first = -pol_stack.top().first;
  }
}

double Model::calc(std::stack<std::pair<double, char>> &pol_stack,
                    std::queue<std::pair<double, char>> &pol_que) {
  char op;
  while (pol_stack.size() != 1 || !pol_que.empty()) {
    op = pol_que.front().second;
    if (op == ' ') {
      pol_stack.push(pol_que.front());
      pol_que.pop();
    } else if (isBinOp(op)) {
      binCalc(pol_stack, pol_que);
    } else {
      unarCalc(pol_stack, pol_que);
    }
  }
  return pol_stack.top().first;
}

std::string Model::getResult(std::string &str, double X) {
  std::stack<std::pair<double, char>> pol_stack;
  std::queue<std::pair<double, char>> pol_que;
  strToPolQue(str, pol_stack, pol_que, X);
  return std::to_string(calc(pol_stack, pol_que));
}

void Model::delZeroForNum(std::string &str) {
  for (int i = str.size() - 1, stop_target = 0;; i--) {
    if (str[i] == '0') {
      str.erase(i, 1);
    } else if (str[i] == '.') {
      str.erase(i, 1);
      stop_target = 1;
    } else {
      stop_target = 1;
    }
    if (stop_target) {
      break;
    }
  }
}
#include <iostream>
std::string Model::resultEventCalc(std::string str, double X) {
  if ((str.size() == 1 || pointRes_ == true) && pointX_ == 0) {
    acUse();
    return " ";
  }
  if (countOpenBr_ != countCloseBr_ ||
      (str.back() != ')' && !isNum(str.back()))) {
    pointRes_ = true;
    return "E";
  }
  std::string res = getResult(str, X);
  delZeroForNum(res);
  pointRes_ = true;
  if (res.size() >= 2) {
    if (res[0] == 'n' || res[0] == 'i' || res[1] == 'i') {
      res = "E";
    }
  }
  return res;
}

std::pair<double, double> Model::maxMinY(
    std::pair<std::vector<double>, std::vector<double>> xy) {
  std::pair<double, double> MaxMinX = {2.22507385850720138e-308,
                                       1.79769313486231571e+308};
  for (auto it : xy.second) {
    if (it > MaxMinX.first) {
      MaxMinX.first = it;
    }
    if (it < MaxMinX.second) {
      MaxMinX.second = it;
    }
  }
  return MaxMinX;
}

std::pair<std::vector<double>, std::vector<double>> Model::ResToGraf(
    std::string str, double MaxX, double MinX) {
  std::pair<std::vector<double>, std::vector<double>> xy;
  if (str.size() == 1 || pointRes_ == true) {
    acUse();
  } else if (MinX >= MaxX) {
    pointRes_ = true;
  } else {
    double h = (MaxX - MinX) / 100.0 * 2.0;
    for (double X = MinX; X <= MaxX; X += h) {
      std::string res = resultEventCalc(str, X);
      if (res[0] != 'E') {
        double res_num = std::stod(res);
        xy.second.push_back(res_num);
        xy.first.push_back(X);
      }
    }
    pointRes_ = true;
  }
  return xy;
}

bool Model::checkXStatus() { return pointX_ > 0 ? 1 : 0; }
