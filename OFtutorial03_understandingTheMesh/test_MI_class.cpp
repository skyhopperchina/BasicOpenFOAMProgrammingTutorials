#include<iostream>
using namespace std;

class out {
private:
    int m_a;
public:
    out(int a): m_a(a){}
    void showoutmember(){cout<<"class out  m_a="<<m_a<<endl;}
};

class in {
    private:
    int m_b;
    public:
    in(int b): m_b(b){}
        void showinmember() {
            cout<<"nested class in show  m_b="<<m_b<<" ;"<<endl;
        }
};

class MI_class:
public out,
public in
{
    private:
        int m_c;
    public:
        MI_class(int c): m_c(c) {}
};

// int out::m_a = 7;

int main() {
    MI_class A(10);
    // A.showoutmember();


    return 0;
};