#include<bits/stdc++.h>
using namespace std;
using ll = long long;
long long maxx = 2147483647;

struct node{
    ll val = maxx;

    void leaf(ll num){
        val = num;
    }

    void merge(node& left, node& right){
        val = (left.val & right.val);
    }

    ll getAns(){
        return val;
    }
};


vector<int> a;
vector<node> t;

void build(int i, int l, int r){
    if(l > r)
        return;
    if(l == r){
        t[i].leaf(a[l]);
        return;
    }

    int m = (l+r)/2;
    build(2*i,l,m);
    build(2*i+1,m+1,r);

    t[i].merge(t[2*i],t[2*i+1]);
    return;
}

ll query(int i, int tl, int tr, int ql, int qr){
    if(ql==tl && qr==tr){
        return t[i].getAns();
    }
    if(ql > qr)
        return maxx;
    //cout<<"YES "<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<'\n';
    int tm = (tr+tl)/2;

    if(tm >= qr){
        return query(2*i, tl, tm, ql, qr);
    }
    if(tm < ql){
        return query(2*i+1,tm+1,tr,ql,qr);
    }

    ll left = query(2*i,tl,tm,ql,tm);
    ll right = query(2*i+1,tm+1,tr,tm+1,qr);
    return (left & right);
}

int main(){

    int T; cin>>T;
    while(T--){
        int n,k; cin>>n>>k;
        a.resize(n); t.resize(4*n);

        for(int i=0;i<n;++i)cin>>a[i];

        build(1,0,n-1);

        if(k >= n/2){
            for(int i=0;i<n;++i){
               cout<<t[1].getAns()<<" ";
            }
            cout<<'\n';
        }else{
            for(int i=0;i<n;++i){
                int l = i-k, r = i+k;
                int ans;
                if(l < 0){
                    l *= -1;
                   ans = query(1,0,n-1,0,r) & query(1,0,n-1,n-l,n-1); 
                }else if(r > n-1){
                    r = r-n+1;
                    ans = query(1,0,n-1,l,n-1) & query(1,0,n-1,0,r-1); 
                }else{
                    ans = query(1,0,n-1,l,r);
                }
                cout<<ans<<" ";
            }
            cout<<'\n';
        }
    }

}