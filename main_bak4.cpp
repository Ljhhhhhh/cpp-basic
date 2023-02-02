#include<iostream>

using namespace std;

#include "speechManager.h"

int main() {
  srand((unsigned int) time(NULL));
  SpeechManager spm;
  int choice = 0;
  while (true) {
    spm.showMenu();
    cout << "请输入你的选择" << endl;
    cin >> choice;

    for (map<int, Speaker>::iterator it = spm.speaker.begin(); it != spm.speaker.end(); it++) {
      cout << "选手编号：" << it->first
           << " 姓名： " << it->second.name
           << " 成绩： " << it->second.score[0] << endl;
    }
    switch (choice) {
      case 1:  //开始比赛
        spm.startSpeech();
        break;
      case 2:  //查看记录
        spm.showRecord();
        break;
      case 3:  //清空记录
        spm.clearRecord();
        break;
      case 0:  //退出系统
        spm.exitSystem();
        break;
      default:
        system("cls"); //清屏
        break;
    }
  }
  system("pause");
  return 0;
}