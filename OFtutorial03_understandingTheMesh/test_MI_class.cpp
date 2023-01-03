#include <iostream>
#include "gettime.h"
using namespace std;

class out
{
private:
    int m_a = 7;

public:
    // out(int a) : m_a(a) {}
    void showoutmember() { cout << "nested class out member m_a=" << m_a << endl; }
};

class in
{
private:
    int m_b = 5;

public:
    // in(int b) : m_b(b) {}
    void showinmember() { cout << "nested class in member m_b=" << m_b << endl; }
};

class MI_class : public out,
                 public in
{
private:
    int m_c;

public:
    MI_class(int c) : m_c(c) {}
    void showmember()
    {
        cout << "MI_Class member m_c=" << m_c << endl;
    }
    void set(int val) { this->m_c = val+1; }
};

int main()
{
    cout << "Current time: " << getCurrentDateTime() << endl;
    cout << "*******************************************\ntest_MI_Class.cpp start!\n--------------------------------------\n";
    MI_class A(10);
    A.set(100);
    A.showmember();
    // A:out(7);
    A.showoutmember();
    A.showinmember();
    // cout << A.m_a << endl;

    cout << "\n--------------------------------------\ntest_MI_Class.cpp End!\n*******************************************\n";
    return 0;
};