#pragma once
#include<iostream>
using namespace std;
#include "identity.h"


class Student {
public:
  Student();
  Student(int id, string name, string pwd);
  virtual void menu();
  void applyOrder();
  void showMyOrder();
  void showAllOrder();
  void cancelOrder();
  int id;
};
