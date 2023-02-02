//
// Created by Administrator on 2023/1/11.
//

#include "manager_bak.h"

Manager::Manager(int id, string name, int deptId) {
    this->user_id = id;
    this->user_name = name;
    this->dept_id = deptId;
}

void Manager::showInfo() {
    cout << "职工编号： " << this->user_id
         << " \t职工姓名： " << this->user_name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

string Manager::getDeptName() {
    return string("经理");
}

void Manager::updateDept(int deptId) {
    Worker::updateDept(deptId);
}
