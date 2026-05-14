#include <bits/stdc++.h>
using namespace std;


int phi(int x) {
    int n = x;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            n /= i;
            n *= (i-1);
            while(x % i == 0) x /= i;
        }
    }
    if (x > 1) n = (n/x) * (x-1);
    return n;
}
