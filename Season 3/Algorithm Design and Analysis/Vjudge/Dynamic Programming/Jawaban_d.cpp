#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll v[105],w[105];


int main(){
    ll n,mx=0,W;
    cin >> n >> W;

    for (ll i = 0; i < n; i++)
    {
        scanf("%lld%lld",&v[i],&w[i]);
        mx+=v[i];
    }
    ll dp[mx+1];
    for (ll i = 0; i <= mx ; i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = mx; j >=v[i]; j--)
        {
            dp[j]=min(dp[j],w[i]+dp[j-v[i]]);
        } 
    }
    ll ans = 0;

    for (ll i = 0; i <= mx; i++)
    {
        if(dp[i]<=W){
            ans = max(ans,i);
        }
    }
    
    cout << ans << endl;

    return 0;
}
