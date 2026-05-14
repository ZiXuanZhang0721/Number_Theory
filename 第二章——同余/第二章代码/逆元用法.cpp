#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5+5; // 二维int数组应该开多大
const int mod = 1e9+7;
// 1.求组合数

vector<vector<int>> comb;
int mod_reverse[MAXN];
int factorial[MAXN];

int exgcd(int a, int b, int &x, int & y) {
    if (b == 0) {
        y = 0; x = 1;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a/b*x;
    return d;
}

int mod_reverse_exgcd(int a, int &x, int &y) {
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

void init(int upper) {
    factorial[1] =factorial[0] = 1;
    mod_reverse[0] = mod_reverse[1] = 1;
    for(int i = 2; i <= upper; ++i) {
        factorial[i] = (i * factorial[i-1]) % mod;
    }
    int x, y;
    mod_reverse[upper] = mod_reverse_exgcd(factorial[upper], x, y);
    for(int i = upper-1; i > 1; --i) {
        mod_reverse[i] = (i+1) * mod_reverse[i+1] % mod;
    }
}

int caculate_comb(int n, int m) {
    if (m < 0 || m > n) return 0;
    return (factorial[n] * mod_reverse[m] % mod) * mod_reverse[n-m] % mod;
}