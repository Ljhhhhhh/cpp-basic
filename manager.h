#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class Manager :public Identity
{
public:

  //默认构造
  Manager();

  //有参构造  管理员姓名，密码
  Manager(string name, string pwd);

  //选择菜单
  virtual void menu();

  //添加账号
  void addPerson();

  //查看账号
  void showPerson();

  //查看机房信息
  void showComputer();

  //清空预约记录
  void cleanFile();

};