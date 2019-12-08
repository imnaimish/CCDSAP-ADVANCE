#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    ll prefSum, suffSum, totalSum, ansSum;

    void leaf(int value){
        prefSum  = suffSum = totalSum = ansSum = value;
    }

    void merge(node& left, node& right){

        totalSum = left.totalSum + right.totalSum;
        prefSum = max(left.prefSum, left.totalSum + right.prefSum);
        suffSum = max(right.suffSum, right.totalSum + left.suffSum);
        ansSum = max({totalSum, prefSum, suffSum, left.ansSum, right.ansSum, left.suffSum + right.prefSum});

    }

    int getAns(){
        return ansSum;
    }

};

vector<ll> a;
vector<node> t;

void build(int i, int l, int r){
    if(l>r)
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

node query(int i, int tl, int tr, int ql, int qr){

    if(tl==ql && tr==qr){
        return t[i];
    }

    int tm = (tr+tl)/2;
    if(tm >= qr){
        return query(2*i, tl, tm, ql, qr);
    }
    if(tm < ql){
        return query(2*i+1, tm+1, tr, ql, qr);
    }

    node left = query(2*i, tl, tm, ql, tm);
    node right = query(2*i+1, tm+1, tr, tm+1, qr);
    node ans; ans.merge(left,right);
    return ans;
}

int main(){

    int n; cin>>n;
    a.resize(n); t.resize(4*n);

    for(int i=0;i<n;++i)cin>>a[i];

    build(1,0,n-1);

    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        --l; --r;
        node temp = query(1,0,n-1,l,r);
        cout<<temp.getAns()<<'\n';
    }
    
}