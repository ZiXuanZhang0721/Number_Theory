#include <bits/stdc++.h>
using namespace std;


void decompose_optimized(int tar) {
    cout << tar << " = ";
    
    // 只需要遍历到 sqrt(tar) 即可，i * i <= tar 是一种避免浮点运算的优雅写法
    for (int i = 2; i * i <= tar; ++i) {
        if (tar % i == 0) {
            int cnt = 0;
            // 榨干这个质因数
            while (tar % i == 0) {
                cnt++;
                tar /= i;
            }
            cout << i << "^" << cnt;
            if (tar != 1) cout << " * ";
        }
    }
    
    // 扫尾工作：如果最后榨干后，tar 还不等于 1
    // 说明原数包含一个大于其平方根的巨大质因数（而且最多只有一个）
    if (tar > 1) {
        cout << tar << "^1";
    }
    cout << endl;
}
