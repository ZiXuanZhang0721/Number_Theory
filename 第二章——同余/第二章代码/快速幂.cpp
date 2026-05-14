#define int long long

int fast_p_recursion(int a, int n, int m) {
    a = (a % m + m) % m;
    if (n == 0) return 1 % m;
    int half = fast_p_recursion(a, n/2, m);
    if (n % 2 == 0) return half * half % m;
    else return (half * half % m * a) % m;
}

int fast_p_iteration(int a, int n, int m) {
    a = (a % m + m) % m;
    int res = a, ans = 1;
    while (n) {
        if (n & 1) ans = ans * res % m;
        res = res * res % m;
        n >>= 1;
    }
    return ans;
}