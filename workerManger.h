//
// Created by Administrator on 2023/1/11.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "worker.h"
#include "employee.h"
#include "manager_bak.h"
#include "boss.h"

#define  FILENAME "empFile.txt"
using namespace std;

class WorkerManager {
public:
    int emp_num;
    Worker **emp_arr;
    bool fileIsEmpty;

    WorkerManager();

    ~WorkerManager();

    static void showMenu();

    static void exitSystem();

    void addEmp();

    void save() const;

    static int getEmpCount();

    void initializeEmp() const;

    void showEmpInfo() const;

    int isExist(int id) const;

    vector<int> isExist(const string &name) const;

    void deleteEmp();

    void updateEmp() const;

    void findEmp() const;

    void sortEmp() const;

    void clearFile();
};