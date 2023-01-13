//
// Created by Administrator on 2023/1/11.
//

#include "boss.h"

Boss::Boss(int id, string name, int deptId) {
    this->user_id = id;
    this->user_name = name;
    this->dept_id = deptId;
}

void Boss::showInfo() {
    cout << "职工编号： " << this->user_id
         << " \t职工姓名： " << this->user_name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName() {
    return "员工";
}

void Boss::updateDept(int deptId) {
    Worker::updateDept(deptId);
}
