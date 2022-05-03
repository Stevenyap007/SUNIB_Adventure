#include <stdio.h>

long long int M, N, a[400001], pref[400001], ans = 0;

long long int max(long long int a, long long int b) {
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main() {
    scanf("%lld", &N);

    a[0] = 0;
    for(long long int i = 1; i <= N; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &M);
    // Prefix Sum Algorithm
    pref[0] = 0;
    for(long long int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    // Sliding Window (2 pointers) Algorithm
    long long int l = N + 1;
    long long int r = N;
    long long int current = 0;
    while(l > 0) {
        if(l > r) {
            while(l > r) {
                l--;
            }
            current = a[l];
        }
        else {
            // Optimized Sliding Window Query Using Prefix Sum
            while(current > M && r > l) {
                long long int temp = pref[r] - pref[l - 1];
                r--;
                current -= temp;
            }
            if(current <= M) {
                ans = max(ans , current);
            }
            l--;
            current += (r - l + 1) * a[l];
        }
        if(current <= M) {
            ans = max(ans , current);
        }
    }
    printf("%lld\n", ans);
    return 0;
}