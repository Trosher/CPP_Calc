#include <gtest/gtest.h>

#include <string>

#include "../CPP_Calc/model.h"

std::mutex g_singleThread;

TEST(Test, calc0) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" 2+2", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 4);
}

TEST(Test, calc1) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" 1*2*3*4*5*6*7*8*9", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 362880);
}

TEST(Test, calc2) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" 1/2/3/4/5/6/7/8/9", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 0.000003);
}

TEST(Test, calc3) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" 10%4", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 2);
}

TEST(Test, calc4) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" 2-2", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 0);
}

TEST(Test, calc5) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" 2^2^3", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 256);
}

TEST(Test, calc6) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" 2/0", 0);
  aga.acUse();
  ASSERT_TRUE(res[0] == 'E');
}

TEST(Test, calc7) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" sqrt(-2)", 0);
  aga.acUse();
  ASSERT_TRUE(res[0] == 'E');
}

TEST(Test, calc8) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(
      " 15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))",
      0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), -30.072164999999998);
}

TEST(Test, calc9) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" sin(10)", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), -0.54402099999999998);
}

TEST(Test, calc10) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" cos(10)", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), -0.83907200000000004);
}

TEST(Test, calc11) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" tan(10)", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 0.64836099999999997);
}

TEST(Test, calc12) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" asin(0.1)", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 0.10016700000000001);
}

TEST(Test, calc13) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" acos(0.1)", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 1.470629);
}

TEST(Test, calc14) {
  s21::Model& aga = s21::Model::getInstance();
  std::string res = aga.resultEventCalc(" atan(10)", 0);
  aga.acUse();
  EXPECT_DOUBLE_EQ(std::stod(res), 1.471128);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
