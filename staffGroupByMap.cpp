#include<string>
#include<vector>
#include<map>
#include<iostream>

using namespace std;
/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

class Worker {
public:
  string name;
  int salary;
};

void createWorker(vector<Worker> &workers) {
  string names = "ABCDEFGHIJ";
  for (int i = 0; i < 10; i++) {
    Worker worker;
    worker.name = "员工";
    worker.name += names[i];
    worker.salary = rand() % 10000 + 10000;
    workers.push_back(worker);
  }
}

void setGroup(vector<Worker> &workers, multimap<int, Worker> &m) {
  for (vector<Worker>::iterator w = workers.begin(); w != workers.end(); w++) {
    int deptId = rand() % 3;
    m.insert(make_pair(deptId, *w));
  }
}

void showWorkerByGroup(multimap<int, Worker> &m) {
  // 0  A  B  C   1  D  E   2  F G ...
  cout << "策划部门：" << endl;

  multimap<int, Worker>::iterator pos = m.find(CEHUA);
  int count = m.count(CEHUA); // 统计具体人数
  int index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
  }

  cout << "----------------------" << endl;
  cout << "美术部门： " << endl;
  pos = m.find(MEISHU);
  count = m.count(MEISHU); // 统计具体人数
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
  }

  cout << "----------------------" << endl;
  cout << "研发部门： " << endl;
  pos = m.find(YANFA);
  count = m.count(YANFA); // 统计具体人数
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
  }

}


int main() {
  srand((unsigned int)time(NULL));

  //1、创建员工
  vector<Worker>workers;
  createWorker(workers);

  //2、员工分组
  multimap<int, Worker>mWorker;
  setGroup(workers, mWorker);

  //3、分组显示员工
  showWorkerByGroup(mWorker);


  for (vector<Worker>::iterator it = workers.begin(); it != workers.end(); it++) {
    cout << "姓名： " << it->name << " 工资： " << it->salary << endl;
  }
  return 0;
}