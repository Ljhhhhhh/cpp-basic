#include <iostream>
#include <fstream>
#include "globalFile.h"

using namespace std;

int main() {

  ifstream ifs;
  ifs.open(ORDER_FILE, ios::in);

  if (!ifs.is_open())
  {
    cout << "文件不存在" << endl;
    ifs.close();
    return 0;
  }

  string date;    // 日期
  string interval;//时间段
  string stuId;   //学生编号
  string stuName; //学生姓名
  string roomId;  //机房编号
  string status;  //预约状态


  while (ifs >> date && ifs >> interval && ifs
    >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
    cout << date << "===" << stuName << endl;
  }


  return 0;
}