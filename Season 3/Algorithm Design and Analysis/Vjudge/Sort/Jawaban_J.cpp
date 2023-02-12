#include<bits/stdc++.h>
using namespace std;
const int MOD = 10000007;



int merge_array(int a[],int l, int m, int r){
    vector<int> x(a+l,a+m+1);
    vector<int> y(a+m+1,a+r+1);
    int i = 0, j = 0;
    int cnt = 0;
    while( i < x.size() && j < y.size() ){
        if(x[i] <= y[j]){
            a[l] = x[i];i++;l++;
        } else {
            a[l] = y[j];j++;l++;
            cnt += x.size() - i;
            cnt %= MOD;
        }
    }
    while( i < x.size()){
        a[l] = x[i];l++;i++;
    }
    while( j < y.size()){
        a[l] = y[j];l++;j++;
    }
    return cnt % MOD;
}

int merge_sort(int a[],int l, int r){
    int cnt=0;
    if(l < r){
        int m = (l+r) / 2;
        cnt += merge_sort(a,l,m);
        cnt %= MOD;
        cnt += merge_sort(a,m+1,r);
        cnt %= MOD;
        cnt += merge_array(a,l,m,r);
        cnt %= MOD;
    }
    return cnt % MOD;
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    cout << merge_sort(a,0,n-1) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }
    

}
