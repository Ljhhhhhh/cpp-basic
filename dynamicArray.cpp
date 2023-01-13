#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<iostream>

using namespace std;

class Person {
public:
  Person(string name, int score) {
    this->m_Name = name;
    this->m_Score = score;
  }

  string m_Name; //姓名
  int m_Score;  //平均分
};


void createPerson(vector<Person>&v)
{
  string nameSeed = "ABCDE";
  for (int i = 0; i < 5; i++)
  {
    string name = "选手";
    name += nameSeed[i];

    int score = 0;

    Person p(name, score);

    //将创建的person对象 放入到容器中
    v.push_back(p);
  }
}

void setScore(vector<Person>&v) {
  for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
    deque<int>d;
    for(int i = 0; i <10; i++) {
      int score = rand() % 41 +60;
      d.push_back(score);
    }

    sort(d.begin(), d.end());

    //去除最高和最低分
    d.pop_back();
    d.pop_front();

    //取平均分
    int sum = 0;
    for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
    {
      sum += *dit; //累加每个评委的分数
    }

    int avg = sum / d.size();
    //将平均分 赋值给选手身上
    it->m_Score = avg;
  }
}

void showScore(vector<Person>&v)
{
  for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << "姓名： " << it->m_Name << " 平均分： " << it->m_Score << endl;
  }
}

int main() {

  //随机数种子
  srand((unsigned int)time(NULL));

  //1、创建5名选手
  vector<Person>v;  //存放选手容器
  createPerson(v);

  //测试
  //for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
  //{
  //	cout << "姓名： " << (*it).m_Name << " 分数： " << (*it).m_Score << endl;
  //}

  //2、给5名选手打分
  setScore(v);

  //3、显示最后得分
  showScore(v);

  system("pause");

  return 0;
}
