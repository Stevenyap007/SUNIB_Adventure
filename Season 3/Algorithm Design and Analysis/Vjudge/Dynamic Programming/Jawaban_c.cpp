#include <stdio.h>

int dp[100007];
int koin[107];
int number[107];
int freq[100007];

int main(){
    int a,f,ans=0,j;
    int n;

    scanf("%d", &f);
    for (int d = 0; d < f; ++d)
    {
        scanf("%d%d",&n,&a);

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &koin[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &number[i]);
        }
        

        for (int i = 1; i <= a; ++i)
        {
            dp[i] = 0;
        }
        dp[0] = 1, ans =0;
        
        for (int i = 0; i < n; ++i)
        {
            for(j = 0; j<=a; ++j){
                freq[j] = 0;
            }
            for(j = koin[i]; j<=a; ++j){
                if(!dp[j] && dp[j-koin[i]] && freq[j - koin[i]]+1 <= number[i]){
                    dp[j] = 1,++ans, freq[j] = freq[j - koin[i]] + 1;
                }
            }
        }
        printf("Case %d: %d\n",d+1, ans);
        
    }
    
    return 0;
}