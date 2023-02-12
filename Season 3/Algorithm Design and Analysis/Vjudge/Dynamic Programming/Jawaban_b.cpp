#include <stdio.h>
#include <string.h>

int main(){
    int ara[110],dp[100010], i, t, n, k;
    
    scanf("%d", &t);

    for (int a = 1; a <= t; a++)
    {
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &ara[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (i = 0; i < n; i++)
        {
            for (int j = ara[i]; j <= k; j++)
            {
                dp[j] = (dp[j] + dp[j-ara[i]]) % 100000007;
            }
        }
        printf("Case %d: %d\n",a,dp[k]);
        
    }
    





    return 0;
}