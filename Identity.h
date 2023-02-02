#pragma once
#include<iostream>
using namespace std;

//身份抽象类
class Identity
{
public:

  //操作菜单
  virtual void menu() = 0;

  string name; //用户名
  string pwd;  //密码
};