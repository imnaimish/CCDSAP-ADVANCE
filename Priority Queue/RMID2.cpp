#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

int main(){

    FAST;

    int t; cin>>t;
    priority_queue<int> pq1; priority_queue<int, vector<int>, greater<int>> pq2; 
    while(t > 0){
        int n; cin>>n;
        if(n == 0){
            pq2 = priority_queue<int, vector<int>, greater<int>>(); pq1 = priority_queue<int>();
            --t; continue;
        }

        if(n == -1){
            int num = pq1.top();
            cout<<num<<'\n';
            pq1.pop();
            if(pq1.size() < pq2.size()){
                pq1.push(pq2.top()); pq2.pop();
            }
        }else{

            if(pq1.empty()){
                pq1.push(n);
            }else if(pq2.empty()){
                pq1.push(n);
                pq2.push(pq1.top()); pq1.pop();
            }else{
                if(pq1.size() > pq2.size()){
                    pq1.push(n);
                    pq2.push(pq1.top()); pq1.pop();
                }else{
                    pq1.push(n); 
                }

                if(pq1.top() > pq2.top()){
                    int num_pq1 = pq1.top(); pq1.pop();
                    int num_pq2 = pq2.top(); pq2.pop();
                    pq1.push(num_pq2); pq2.push(num_pq1);
                }
            }
        }

    }

}