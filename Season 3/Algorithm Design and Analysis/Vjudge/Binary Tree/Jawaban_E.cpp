#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,mn,n,a,b;
priority_queue <long long> q;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        q.push(-t);
    }
    while (!q.empty())
    {
        a=q.top();
        q.pop();
        if(q.empty()){
            break;
        }
        b=q.top();
        q.pop();
        mn-=a+b;
        q.push(a+b);
    }
    cout << mn;
    
    
}