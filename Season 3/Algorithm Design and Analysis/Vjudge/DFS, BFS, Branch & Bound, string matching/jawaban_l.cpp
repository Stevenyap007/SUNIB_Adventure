#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#define MAXN 1000005
#define MAXM 1005
using namespace std;

char s[MAXN];
int sa[MAXN];
int rak[MAXN];
int tp[MAXN];
int tax[MAXN];
int N,M;

void Qsort(){
    for(int i = 0; i<= M; ++i){
        tax[i] = 0;
    }
    for(int i = 1; i<= N; ++i){
        tax[rak[i]]++;
    }
    for(int i = 1; i<= M; ++i){
        tax[i] += tax[i-1];
    }
    for(int i = N; i>= 1; i--){
        sa[tax[rak[tp[i]]]--] = tp[i];
    }
}

void SufficSort(){
    M = 75;
    for (int i = 1; i <= N; ++i)
    {
        rak[i] = s[i] - '0' + 1;
        tp[i] = i;
    }
    Qsort();
    for(int w = 1, p = 0; p < N; M = p, w <<= 1){
        p = 0;
        for (int i = 1; i <= w; ++i)
        {
            tp[++p] = N - w + i;
        }
        for (int i = 1; i <= N; ++i)
        {
            if(sa[i] > w){
                tp[++p] = sa[i] - w;
            }
        }
        Qsort();
        swap(tp,rak);
        rak[sa[1]] = p = 1;
        for (int i = 2; i <= N; ++i)
        {
            rak[sa[i]] = (tp[sa[i-1]] == tp[sa[i]] && tp[sa[i-1]+w] == tp[sa[i]+w]) ? p : ++p;
        }
   
    }
}

char a[MAXM];
int cmp(int p, int m){
    return strncmp(a+1,s+sa[p],m);
}
bool find(){
    int len = strlen(a+1);
    if(cmp(1, len) < 0){
        return false;
    }
    if(cmp(N, len) > 0){
        return false;
    }
    int l = 1, r = N;
    while (l <= r)
    {
        int mid = (l+r)/2;
        int res = cmp(mid,len);
        if(!res){
            return true;
        }
        if(res < 0){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return false;
}

int main(){
    scanf("%s",s+1);
    N = strlen(s+1);
    SufficSort();
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s",a+1);
        printf("%d\n",(find() ? 1:0));
    }
    return 0;
}