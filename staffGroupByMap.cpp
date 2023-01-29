#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<algorithm>

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
    std::string name;
    int salary{};
};

void createWorker(std::vector<Worker> &workers) {
    std::string names = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++) {
        Worker worker;
        worker.name = "员工";
        worker.name += names[i];
        worker.salary = rand() % 10000 + 10000;
        workers.push_back(worker);
    }
}

void setGroup(std::vector<Worker> &workers, std::multimap<int, Worker> &m) {
    for (std::vector<Worker>::iterator w = workers.begin(); w != workers.end(); w++) {

        int deptId = rand() % 3;
        m.insert(std::make_pair(deptId, *w));
    }
//    简化写法
//    for (auto &w : workers) {
//        int deptId = rand() % 3;
//        m.insert(make_pair(deptId, w));
//    }
}

void showWorkerByGroup(std::multimap<int, Worker> &m) {
    // 0  A  B  C   1  D  E   2  F G ...
    std::cout << "策划部门：" << std::endl;

    std::multimap<int, Worker>::iterator pos = m.find(CEHUA);
//    auto pos = m.find(CEHUA); // 简化写法
    size_t count = m.count(CEHUA); // 统计具体人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        std::cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << std::endl;
    }

    std::cout << "----------------------" << std::endl;
    std::cout << "美术部门： " << std::endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU); // 统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        std::cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << std::endl;
    }

    std::cout << "----------------------" << std::endl;
    std::cout << "研发部门： " << std::endl;
    pos = m.find(YANFA);
    count = m.count(YANFA); // 统计具体人数Ï
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        std::cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << std::endl;
    }

}

class MyPrint {
public:
    void operator()(int val) {
        std::cout << val << " ";
    }
};

class TransForm {
public:
    int operator()(int val) {
        return val;
    }

};

void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    vector<int> vTarget; //目标容器

    vTarget.resize(v.size()); // 目标容器需要提前开辟空间

    transform(v.begin(), v.end(), vTarget.begin(), TransForm());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
}


int main() {

    test01();
    srand((unsigned int) time(nullptr));

    //1、创建员工
    std::vector<Worker> workers;
    createWorker(workers);

    //2、员工分组
    std::multimap<int, Worker> mWorker;
    setGroup(workers, mWorker);

    //3、分组显示员工
    showWorkerByGroup(mWorker);




//    for (std::vector<Worker>::iterator it = workers.begin(); it != workers.end(); it++) {
//        std::cout << "姓名： " << it->name << " 工资： " << it->salary << std::endl;
//    }

//    简化写法
//    for (auto & worker : workers) {
//        std::cout << "姓名： " << worker.name << " 工资： " << worker.salary << std::endl;
//    }
    return 0;
}