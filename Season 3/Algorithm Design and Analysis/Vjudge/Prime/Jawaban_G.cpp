#include <bits/stdc++.h>
using namespace std;

const int N=46341;
int prim[4791]={3,5,7}, pn=3;

bool isprime(long long n) {
    if(n==2) return true;
    if(n<2 || n%2==0) return false;
    for (int i = 0; i < pn && (long long)prim[i]*prim[i]<=n; i++)
    {
        if(n%prim[i]==0){
            return false;
        }
        return true;
    } 
}

void genprime(){
    for (int i = 12; i <=N; i+=6)
    {
        if(isprime(i-1)){
            prim[pn++] == i-1;
        }
        if(isprime(i+1)){
            prim[pn++] = i+1;
        } 
    }   
}

int main(){
    long long l, r;
    int count = 0;
    genprime();

    cin >> l >> r;
    if(l<2) l =2;
    if(l==2 && l<=r) count++, l++;
    if(l%2==0) l++;
    for (long long i = l; i <=r; i+=2)
    {
        if(isprime(i))
            count++;
    
    cout << count << endl;
    return 0;
    }
}