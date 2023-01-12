//
// Created by Administrator on 2023/1/11.
//

#include "employee.h"

Employee::Employee(int id, string name, int deptId) {
  this->user_id = id;
  this->user_name = name;
  this->dept_id = deptId;
}

void Employee::showInfo() {
  cout << "职工编号： " << this->user_id
       << " \t职工姓名： " << this->user_name
       << " \t岗位：" << this->getDeptName()
       << " \t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
  return  string("员工");
}

void Employee::updateDept(int deptId) {
  Worker::updateDept(deptId);
}