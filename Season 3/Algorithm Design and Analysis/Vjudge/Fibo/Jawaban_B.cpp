#include "iostream"
#include "string.h"
#include "string"
#include "cstdio"
using namespace std;
int n;
long long z,y;
string t,f[30];
long long dp[110];
long long match(string a, string b)
{
        int ans = 0;
        bool flag;
        for (int i = 0; i < a.length(); i++)
        {
                if(i+b.length()>a.length())
                        break;
                flag=true;
                for (int j = 0; j < b.length(); j++)
                {
                        if(b[j]!=a[i+j]){
                            flag=false;
                            break;
                        }
                }
                if(flag)
                        ans++;
        }
        return ans;
}

long long cal(int x){
        if(dp[x]!=-1)
                return dp[x];
        if(x<=26)
                return dp[x]=match(f[x],t);
        else
        {
                if(x%2==0)
                        return dp[x]=cal(x-1)+cal(x-2)+z;
                else
                        return dp[x]=cal(x-1)+cal(x-2)+y;
        }
}

int main(int argc, char* argv[]){
    f[0]="0";
    f[1]="1";
    for (int i = 2; i<=26; i++)
            f[i]=f[i-1]+f[i-2];
    int cas=0;
    while (cin>>n>>t)
    {
        memset(dp,-1,sizeof(dp));
        z=match(f[25]+f[26],t)-match(f[26],t)-match(f[25],t);
        y=match(f[26]+f[26],t)-match(f[26],t)-match(f[26],t);
        printf("Case %d: %lld\n",++cas,cal(n));
    }
    return 0;
    
}