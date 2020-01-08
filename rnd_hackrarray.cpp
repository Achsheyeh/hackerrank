#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    if ((n < 1) || (n > 1000))
      exit(1);

    int *a = new int[n];

    for (int idx = 0; idx < n; ++idx)
      cin >> a[idx];
    
    for (int idx = n-1; idx >= 0; --idx)
      cout << a[idx];
    
    delete[] a;
    return 0;
}
