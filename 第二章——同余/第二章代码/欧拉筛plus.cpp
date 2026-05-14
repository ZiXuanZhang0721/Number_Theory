// #include <bits/stdc++.h>
// using namespace std;


// vector<int> phi;

// vector<int> func(int upper) {
//     phi.resize(upper+1);
//     phi[1] = 1;
//     vector<int> primes(upper+1);
//     vector<bool> is_prime(upper+1,1);
//     int cnt = 0;
//     for(int i = 2; i <= upper; ++i) {
//         if (is_prime[i]) {
//             primes[cnt++] = i;
//             phi[i] = i -1;
//         }
//         for (int j = 0; j < cnt && i*primes[j] <= upper; j++) {
//             is_prime[i*primes[j]] = 0;
//             if (i % primes[j] == 0) {
//                 phi[i * primes[j]] = phi[i] * primes[j];  
//                 break;
//             }
//             else {
//                 phi[i * primes[j]] = phi[i] * phi[primes[j]]; // 改成p-1更好
//             }
//         }
//     }
//     primes.resize(cnt);
//     return primes;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> phi;

vector<int> get_primes_and_phi(int upper) {
    if (upper < 1) return {}; // 防御性编程
    
    phi.assign(upper + 1, 0); // 确保清空并重新分配
    phi[1] = 1;               // 核心补漏：处理边界
    
    vector<int> primes(upper + 1);
    vector<bool> is_prime(upper + 1, true);
    is_prime[0] = is_prime[1] = false; // 0和1不是质数
    
    int cnt = 0;
    for(int i = 2; i <= upper; ++i) {
        if (is_prime[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;   // 质数的特权
        }
        // O(N) 的灵魂循环
        for (int j = 0; j < cnt && i * primes[j] <= upper; j++) {
            is_prime[i * primes[j]] = false;
            
            if (i % primes[j] == 0) {
                // 包含分支：质因数种类没变
                phi[i * primes[j]] = phi[i] * primes[j];  
                break; // 保证每个合数只被其最小质因数筛掉
            } else {
                // 互素分支：积性函数大显神威
                phi[i * primes[j]] = phi[i] * (primes[j] - 1); // 省去一次数组读取
            }
        }
    }
    primes.resize(cnt); // 缩除多余空间
    return primes;
}
