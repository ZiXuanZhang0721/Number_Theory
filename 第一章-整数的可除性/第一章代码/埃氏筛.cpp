#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void get_primes(int upper) {
    // 防御性编程：如果有多次调用，确保先清空之前的素数记录
    primes.clear(); 
    
    // 如果 upper 小于 2，直接返回，没有素数
    if (upper < 2) return; 

    vector<bool> is_prime(upper + 1, true);
    is_prime[0] = is_prime[1] = false; // 虽然循环从 2 开始，但严格把 0 和 1 标记为合数是好习惯
    
    // 将 i 声明为 long long，彻底杜绝 i * i 溢出的可能
    for (long long i = 2; i * i <= upper; ++i) {
        if (is_prime[i]) {
            // 将 j 声明为 long long，防止 j += i 在逼近 upper 时发生溢出
            for (long long j = i * i; j <= upper; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    // 收集素数
    for (int i = 2; i <= upper; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}
