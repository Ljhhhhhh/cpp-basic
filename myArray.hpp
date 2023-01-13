#pragma once

#include <iostream>

using namespace std;

template<class T>
class MyArray {
public:
    MyArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        pAddress = new T[this->capacity];
    }

    MyArray(const MyArray &arr) {
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->pAddress = new T[this->capacity];
        for (int i = 0; i < this->size; i++) {
            //如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
            // 普通类型可以直接= 但是指针类型需要深拷贝
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //重载= 操作符  防止浅拷贝问题
    MyArray &operator=(const MyArray &myarray) {

        if (this->pAddress != nullptr) {
            delete[] this->pAddress;
            this->capacity = 0;
            this->size = 0;
        }

        this->capacity = myarray.capacity;
        this->size = myarray.size;
        this->pAddress = new T[this->capacity];
        for (int i = 0; i < this->size; i++) {
            this->pAddress[i] = myarray[i];
        }
        return *this;
    }

    //重载[] 操作符  arr[0]
    T &operator[](int index) {
        return this->pAddress[index]; //不考虑越界，用户自己去处理
    }

    //尾插法
    void Push_back(const T &val) {
        if (this->capacity == this->size) {
            return;
        }
        this->pAddress[this->size] = val;
        this->size++;
    }

    //尾删法
    void Pop_back() {
        if (this->size == 0) {
            return;
        }
        this->size--;
    }

    //获取数组容量
    int getCapacity() {
        return this->capacity;
    }

    //获取数组大小
    int getSize() {
        return this->size;
    }

    //析构
    ~MyArray() {
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->capacity = 0;
            this->size = 0;
        }
    }


private:
    T *pAddress;  //指向一个堆空间，这个空间存储真正的数据
    int capacity; //容量
    int size;   // 大小
};