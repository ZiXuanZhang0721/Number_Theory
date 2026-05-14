#include <bits/stdc++.h>
using namespace std;




vector<int> func(int upper) {
    vector<int> primes(upper+1);
    vector<bool> is_prime(upper+1,1);
    int cnt = 0;
    for(int i = 2; i <= upper; ++i) {
        if (is_prime[i]) primes[cnt++] = i;
        for (int j = 0; j < cnt && i*primes[j] <= upper; j++) {
            is_prime[i*primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
    primes.resize(cnt);
    return primes;
}