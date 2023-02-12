#include<bits/stdc++.h>

using namespace std;

int a,b,c;
priority_queue<int>pq;
stack<int>s;
queue<int>q;

int main(){
    while(cin >> a){
        while (!pq.empty())
        {
            pq.pop();
        }
        while (!s.empty())
        {
            s.pop();
        }
        while (!q.empty())
        {
            q.pop();
        }

        int pr=0, st=0, qu=0;
        while(a--){
            cin >> b >> c;
            if(b==1){
                pq.push(c);
                s.push(c);
                q.push(c);
            }else {
                if(pq.empty()){
                    pr=1, st =1, qu=1;
                    continue;
                }
                if(pq.top()!=c){
                    pr = 1;
                }
                if(s.top()!=c){
                    st = 1;
                }
                if(q.front()!=c){
                    qu = 1;
                }
                pq.pop(),s.pop(),q.pop();
            }
        }
        if(pr+st+qu == 3){
            cout << "impossible" << endl;
        }else if(pr+st+qu!=2){
            cout << "not sure" << endl;
        }else if(!pr){
            cout << "priority queue" << endl;
        }else if(!st){
            cout << "stack" << endl;
        }else if(!qu){
            cout << "queue" << endl;
        }
  
    }


    
    return 0;
}