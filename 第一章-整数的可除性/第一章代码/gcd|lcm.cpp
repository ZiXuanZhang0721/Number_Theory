// 1. recursion

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b , a%b);
}

// 2. iteration

int gcd_i(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int lcm(int a, int b) {
    return a*b / gcd(a,b);
}