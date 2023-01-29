//
// Created by Administrator on 2023/1/29.
//

#pragma once

#include<iostream>
#include<vector>
#include "speaker.h"
#include<map>

using namespace std;

class SpeechManager {
public:
  SpeechManager();

  void showMenu();

  ~SpeechManager();

  void exitSystem();
  vector<int> v1;
  vector<int> v2;
  vector<int> victory;
  int index;
  bool fileIsEmpty;
  //往届记录
  map<int, vector<string>> record;
  map<int, Speaker> speaker;

  void initSpeech();
  void createSpeaker();
  void startSpeech();
  void speechDraw();
  void speechContest();
  void showScore();
  void saveRecord();
  void loadRecord();
  void showRecord();
  void clearRecord();
};
