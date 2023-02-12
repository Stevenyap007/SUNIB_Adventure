#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10005;
int n,k,A[maxn],d[2][105];

int main(){
    int O;
    for (cin >>O;O--;)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin>>A[i];
        memset(d[0],0,sizeof(d[0]));
        d[0][(A[0]%k+k)%k] = true;
        int t=1;
        for (int i = 1; i < n; i++,t^=1)
        {
            memset(d[t],0,sizeof(d[t]));
            A[i] = (A[i]%k+k)%k;
            for (int j = 0; j < k; j++)if(d[!t][j])
                d[t][(j+A[i])%k] = d[t][(j+k-A[i])%k]=true;
        }
        cout<<(d[!t][0]?"Divisible":"Not divisible")<<endl;   
    }

    return 0;
}