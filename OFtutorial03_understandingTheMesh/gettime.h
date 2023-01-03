#include <iostream>
#include <ctime>
using namespace std;

string getCurrentDateTime()
{
    time_t tt;
    struct tm *st;

    tt = time(NULL);
    st = localtime(&tt);
    return asctime(st);
}

