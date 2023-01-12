//
// Created by Administrator on 2023/1/11.
//

#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
  public:
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
    void updateDept(int deptId);

    int user_id;
    string user_name;
    int dept_id;
};

