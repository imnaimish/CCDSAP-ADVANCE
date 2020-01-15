#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int l,r,k; cin>>l>>r>>k;
        if(k < l || k > r){
            cout<<"-1\n"; continue;
        }

        if(k == l && r == k){
            cout<<l<<" "<<r<<"\n";
            cout<<"0\n";
            continue;
        }

        int cnt = 1;
        cout<<l<<" "<<r<<"\n";
        while(1){
            int m = (l+r)/2;
            int l1 = l, r1 = m, l2 = m+1, r2 = r;
            if(k>=l1 && k<=r1){
                l = l1; r = r1;
            }else{
                l = l2; r = r2;
            }
            cout<<l<<" "<<r<<'\n';
            ++cnt;
            if(k == l && k == r){
                break;
            }
        }
        cout<<cnt<<"\n";
    }
}