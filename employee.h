//
// Created by Administrator on 2023/1/11.
//

#pragma once

#include<iostream>

using namespace std;

#include "worker.h"

class Employee : public Worker {
public:
    Employee(int id, string& name, int deptId);

    virtual void showInfo();

    virtual string getDeptName();

    void updateDept(int deptId);
};