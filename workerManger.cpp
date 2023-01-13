//
// Created by Administrator on 2023/1/11.
//

#include "workerManger.h"

WorkerManager::WorkerManager() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open()) {
        cout << "文件不存在" << endl; //测试输出
        this->emp_num = 0;  //初始化人数
        this->fileIsEmpty = true; //初始化文件为空标志
        this->emp_arr = nullptr; //初始化数组
        ifs.close(); //关闭文件
        return;
    }

    //文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空!" << endl;
        this->emp_num = 0;
        this->fileIsEmpty = true;
        this->emp_arr = nullptr;
        ifs.close();
        return;
    }

    int num = WorkerManager::getEmpCount();
    cout << "职工个数为：" << num << endl;  //测试代码
    this->emp_num = num;  //更新成员属性
    this->fileIsEmpty = false;
    this->emp_arr = new Worker *[this->emp_num];
    initializeEmp();
}

WorkerManager::~WorkerManager() {
    if (this->emp_arr != nullptr) {
        delete[] this->emp_arr;
    }
}

void WorkerManager::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void WorkerManager::addEmp() {
    cout << "请输入新增员工数量" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0) {
        int newSize = this->emp_num + addNum;
        auto **newSpace = new Worker *[newSize];

        if (this->emp_arr != nullptr) {
            for (int i = 0; i < this->emp_num; i++) {
                newSpace[i] = this->emp_arr[i];
            }
        }

        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = nullptr;
            switch (dSelect) {
                case 1: //普通员工
                    worker = new Employee(id, name, 1);
                    break;
                case 2: //经理
                    worker = new Manager(id, name, 2);
                    break;
                case 3:  //老板
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            newSpace[this->emp_num + i] = worker;
        }
        delete[] this->emp_arr;
        this->emp_arr = newSpace;
        this->emp_num = newSize;
        this->fileIsEmpty = false;
        //提示信息
        cout << "成功添加" << addNum << "名新职工！" << endl;
        this->save();
    } else {
        cout << "输入有误" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::save() const {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->emp_num; i++) {
        Worker *userInfo = this->emp_arr[i];
        ofs << userInfo->user_id << " "
            << userInfo->user_name << " "
            << userInfo->dept_id << endl;
    }
    ofs.close();
}

int WorkerManager::getEmpCount() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int deptId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> deptId) {
        //记录人数
        num++;
    }

    ifs.close();

    return num;
}

void WorkerManager::initializeEmp() const {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int deptId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> deptId) {
        Worker *worker = nullptr;
        //根据不同的部门Id创建不同对象
        if (deptId == 1)  // 1普通员工
        {
            worker = new Employee(id, name, deptId);
        } else if (deptId == 2) //2经理
        {
            worker = new Manager(id, name, deptId);
        } else //总裁
        {
            worker = new Boss(id, name, deptId);
        }
        //存放在数组中
        this->emp_arr[index] = worker;
        index++;
    }
}

void WorkerManager::showEmpInfo() const {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {
        for (int i = 0; i < emp_num; i++) {
            //利用多态调用接口
            this->emp_arr[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

void WorkerManager::deleteEmp() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
    } else {
        cout << "请输入员工编号" << endl;
        int findId;
        cin >> findId;
        int index = this->isExist(findId);
        if (index == -1) {
            cout << "查无此员工信息" << endl;
        } else {
            for (int i = index; i < this->emp_num - 1; ++i) {
                this->emp_arr[i] = this->emp_arr[i + 1];
            }
            this->emp_num--;
            this->save();
            cout << "删除成功" << endl;
        }
    }

    system("pause");
    system("cls");
}

int WorkerManager::isExist(int id) const {
    int index = -1;
    for (int i = 0; i < emp_num; i++) {
        if (this->emp_arr[i]->user_id == id) {
            index = i;
            break;
        }
    }
    return index;
}

vector<int> WorkerManager::isExist(const string &name) const {
    vector<int> resultArr;
    for (int i = 0; i < emp_num; i++) {
        string userName = this->emp_arr[i]->user_name;
        string::size_type findResult;
        findResult = userName.find(name);
        if (findResult != string::npos) {
            resultArr.push_back(i);
        }
    }
    return resultArr;
}

//int WorkerManager::isExist(const string& name, bool exact) const {
//  int findResultArr[] = {};
//  int findLength = 0;
//  int index = -1;
//  for (int i = 0; i < emp_num; i++) {
//    string userName = this->emp_arr[i]->user_name;
//    string::size_type findResult;
//    if (exact) {
//      if (this->emp_arr[i]->user_name == name) {
//        findLength++;
//        int latestResult[findLength];
//        for (int j = 0; j < findLength; j++) {
//          if (j == findLength - 1) {
//            latestResult[j] = findResultArr[j];
//          } else {
//            latestResult[j] = i;
//          }
//        }
//        index = i;
//      }
//    } else {
//      findResult = userName.find(name);
//      if (findResult != string::npos) {
//        findLength++;
//        int latestResult[findLength];
//        for (int j = 0; j < findLength; j++) {
//          if (j != findLength - 1) {
//            latestResult[j] = findResultArr[j];
//          } else {
//            latestResult[j] = i;
//          }
//        }
//        index = i;
//        cout <<"找到了" << endl;
//        cout << sizeof(latestResult) / sizeof(int) << endl;
//        cout <<"序号" << endl;
//        for (int idx = 0; idx < findLength; ++idx) {
//          cout  << latestResult[idx] << endl;
//        }
//        cout <<"结束" << endl;
//      }
//    }
//  }
//  return index;
//}


void WorkerManager::updateEmp() const {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
    } else {
        cout << "请输入需要修改的员工编号" << endl;
        int id;
        cin >> id;
        int index = isExist(id);
        if (index == -1) {
            cout << "查无此员工" << endl;
        } else {
            Worker *emp = this->emp_arr[index];
            cout << "请输入员工最新部门编号" << endl;
            int deptId;
            cin >> deptId;
            emp->updateDept(deptId);
            cout << "员工" << emp->user_id << "更新成功：\t"
                 << emp->user_name << " "
                 << emp->dept_id
                 << endl;
            this->save();
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::findEmp() const {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {

        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            int index = -1;
            int id;
            cout << "请输入查找的员工编号：" << endl;
            cin >> id;
            index = isExist(id);
            if (index != -1) {
                Worker *worker = this->emp_arr[index];
                worker->showInfo();
            } else {
                cout << "查找失败，查无此人" << endl;
            }
        } else if (select == 2) {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;
            vector<int> resultArr = isExist(name);
            for (int i = 0; i < resultArr.size(); i++) {
                this->emp_arr[resultArr[i]]->showInfo();
            }
        } else {
            cout << "输入有误" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::sortEmp() const {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    } else {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->emp_num; i++) {
            int minOrMax = i;
            for (int j = i + 1; j < this->emp_num; j++) {
                if (select == 1) //升序
                {
                    if (this->emp_arr[minOrMax]->user_id > this->emp_arr[j]->user_id) {
                        minOrMax = j;
                    }
                } else  //降序
                {
                    if (this->emp_arr[minOrMax]->user_id < this->emp_arr[j]->user_id) {
                        minOrMax = j;
                    }
                }
            }

            if (i != minOrMax) {
                Worker *temp = this->emp_arr[i];
                this->emp_arr[i] = this->emp_arr[minOrMax];
                this->emp_arr[minOrMax] = temp;
            }

        }
        cout << "排序成功,排序后结果为：" << endl;
        this->save();
        this->showEmpInfo();
    }
}

void WorkerManager::clearFile() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->emp_arr != nullptr) {
            for (int i = 0; i < this->emp_num; i++) {
                if (this->emp_arr[i] != nullptr) {
                    delete this->emp_arr[i];
                }
            }
            this->emp_num = 0;
            delete[] this->emp_arr;
            this->emp_arr = nullptr;
            this->fileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }

    system("pause");
    system("cls");
}







