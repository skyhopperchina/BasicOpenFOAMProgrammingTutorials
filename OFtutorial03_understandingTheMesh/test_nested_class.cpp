#include<iostream>
using namespace std;

class out {
// private:
    

public:

    static int m_a;
    // out(int a): m_a(a){}
    void showmember(){cout<<"class out  m_a="<<m_a<<endl;}

    class in {
    public:
        void showA() {
            cout<<"nested class in show  m_a="<<m_a<<" ;"<<endl;
        }
    };

};

int out::m_a = 7;

int main() {
    out ini;
    ini.showmember();
    // ini.m_a=7;
    // ini.showmember();
    out::in instance1;
    // instance1.=4;
    instance1.showA();
    // out::in i;
    // i.showA();
    return 0;
}