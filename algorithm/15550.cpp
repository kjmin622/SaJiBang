#include <iostream>
using namespace std;
#define A float
#define B 999999998
#define C int
#define D 999999999
#define E double
#define F 999999999

int main() {
    A a = B;
    C b = D;
    E c = F;
    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}