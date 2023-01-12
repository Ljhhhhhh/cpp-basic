//
// Created by Administrator on 2023/1/11.
//
#include<iostream>
using namespace std;
#include "workerManger.h"

int main() {
  WorkerManager wm;
  int choice = 0;

  while (true) {
    WorkerManager::showMenu();
    cout << "请输入你的选择" << endl;
    cin >> choice;

    switch (choice) {
      case 0:
        wm.exitSystem();
        break;
      case 1:
        wm.addEmp();
        break;
      case 2:
        wm.showEmpInfo();
        break;
      case 3:
        wm.deleteEmp();
        break;
      case 4:
        wm.updateEmp();
        break;
      case 5:
        wm.findEmp();
        break;
      case 6:
        wm.sortEmp();
        break;
      case 7:
        wm.clearFile();
        break;
      default:
        system("cls");
        break;
    }
  }
  return 0;
}