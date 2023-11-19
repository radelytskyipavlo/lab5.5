#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

int Gen(const int a, const int b, const int c, const int m, const int i, const int V1, const int V2, int& recursionDepth)
{
    recursionDepth++;
    if (i == 2)
        return V2;
    if (i == 1)
        return V1;
    return (a * Gen(a, b, c, m, i - 1, V1, V2, recursionDepth)
        + b * Gen(a, b, c, m, i - 2, V1, V2, recursionDepth) + c) % m;
}

int main()
{
    int a, b, c, m, i;
    int V1, V2;

    cout << "i = "; cin >> i;

    a = 31;
    b = 12;
    c = 5;
    m = 151;

    srand((unsigned)time(NULL));
    V1 = rand();
    V2 = rand();

    int recursionDepth = 0;  

    cout << "--------" << endl;
    cout << "| level: " << recursionDepth << " |" << endl; 
    cout << "--------" << endl;
    cout << "| depth: " << i << " |" << endl; 
    cout << "--------" << endl;
    cout << "|" << setw(5) << " V(i)" << " |" << endl;
    cout << "--------" << endl;
    cout << "|" << setw(5) << Gen(a, b, c, m, i, V1, V2, recursionDepth) << " |" << endl;
    cout << "--------" << endl;

    return 0;
}