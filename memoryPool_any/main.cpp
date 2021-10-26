#include "managerpool.hpp"

using namespace std;

int main () {
    char *p = new char[128];
    delete[] p;
    return 0;
}

