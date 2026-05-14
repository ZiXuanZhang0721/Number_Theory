#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;


// 快速幂
int fast_power(int a, int n) {
    a = (a % mod + mod) % mod;
    int res = a, ans = 1;
    while (n) {
        if (n & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        n >>= 1;
    }
    return ans;
}

// 1.费马小定理
int mod_reverse(int a) {
    if (a % mod == 0) return -1;
    return fast_power(a, mod-2);
}

// 2.欧拉定理求逆元
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

int mod_reverse_o(int a) {
    return fast_power(a, phi(mod)-1);
}

// 3. exgcd逆元

int x, y;

int exgcd(int a, int b, int &x, int & y) {
    if (b == 0) {
        y = 0; x = 1;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a/b*x;
    return d;
}

int mod_reverse_exgcd(int a) {
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}