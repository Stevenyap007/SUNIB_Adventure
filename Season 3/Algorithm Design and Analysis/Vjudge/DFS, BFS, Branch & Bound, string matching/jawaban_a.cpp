#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e9+7;
ll arr[20];
ll mat[20][20];
ll dp[20][(1<<20)];
ll n,m,k;

ll solve(int ind,int mask){

if(m==__builtin_popcount(mask)){
    return 0;
}


ll &ret=dp[ind][mask];

if (ret!=-1) return ret;

for(int i=0;i<n;i++){
    if(!((1<<i)&mask)){

        ret = max(ret,solve(i,((1<<i)|mask))+mat[ind][i]+arr[i]);
    }
}


return ret;
}


int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


memset(dp,-1,sizeof (dp));
 cin>>n>>m>>k;
 for (int i = 0; i < n; i++)
 {
cin>>arr[i];
 }
 
 while (k--)
 {
    int x,y,z;
    cin>>x>>y>>z;
     mat[x-1][y-1]=z;
 }
 



 cout<<solve(19,0)<<"\n";

}