#include <stdio.h>

#define mod 100000007

int main(){
    int t;
    scanf("%d",&t);
    int kombinasi = 1;
    while (t--)
    {
        int n, K;
        long long arr[51];
        int c[51];
        scanf("%d%d",&n,&K);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&c[j]);
        }
        long long dp[K+1], dp2[K+1];
        for (int k = 0; k <= K; k++)
        {
            dp[k] = dp2[k] = 0;
        }
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= K; j++)
            {
                dp2[j] = dp[j];
                if(j-arr[i]>=0){
                    dp2[j] += dp2[j-arr[i]];
                }
                if(dp2[j] >= mod){
                    dp2[j] %= mod;
                }
                if(j-(c[i]+1)*arr[i]>=0){
                    dp2[j] = (dp2[j] - dp[j-(c[i]+1)*arr[i]] + mod )%mod;
                }
            }
            for (int j = 0; j <= K ; j++)
            {
                dp[j] = dp2[j];
            }   
        }
        printf("Case %d: %lld\n",kombinasi++,dp[K]);
    }
    
    return 0;
}