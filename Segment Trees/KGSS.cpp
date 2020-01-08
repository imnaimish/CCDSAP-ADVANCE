#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

struct node{
    ll fmaxx,smaxx,ans;
    void leaf(int num){
        ans = fmaxx = num;
        smaxx = INT_MIN;
    }
    void merge(node &a, node &b){
        fmaxx = max(max(a.fmaxx,b.smaxx),max(a.smaxx,b.fmaxx));
        smaxx = min(max(a.fmaxx,b.smaxx), max(a.smaxx,b.fmaxx));
        ans = fmaxx + smaxx;
    }
};

vector<int> a;
vector<node> t;
int n,q;

void build(int i, int tl, int tr){
    if(tl > tr)
        return;
    if(tl == tr){
        t[i].leaf(a[tl]);
    }else{
        int tm = (tl+tr)>>1, x = i<<1, y = x|1;
        build(x,tl,tm);
        build(y,tm+1,tr);
        t[i].merge(t[x],t[y]);
    }
}

void update(int i, int tl, int tr, int pos, int val){
    if(tl > tr)
        return;
    if(tl == tr){
        t[i].leaf(val);
        return;
    }
    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    if(pos <= tm){
        update(x,tl,tm,pos,val);
    }else{
        update(y,tm+1,tr,pos,val);
    }
    t[i].merge(t[x],t[y]);
}

node query(int i, int tl, int tr, int ql, int qr){
    if(tl == ql && tr == qr){
        return t[i];
    }
    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    if(qr <= tm){
        return query(x,tl,tm,ql,qr);
    }else if(tm < ql){
        return query(y,tm+1,tr,ql,qr);
    }
    node a1 = query(x,tl,tm,ql,tm);
    node a2 = query(y,tm+1,tr,tm+1,qr);
    node temp;
    temp.merge(a1,a2);
    return temp;
}

int main(){

    FAST;
    cin>>n;
    a.resize(n); t.resize(4*n);
    for(int i=0;i<n;++i)
        cin>>a[i];

    build(1,0,n-1);
    cin>>q;
    while(q--){
        char ch; cin>>ch;
        if(ch == 'Q'){
            int l,r; cin>>l>>r;
            if(l > r)
                swap(l,r);
            node temp = query(1,0,n-1,l-1,r-1);
            cout<<temp.ans<<'\n';
        }else{
            int pos,val; cin>>pos>>val;
            update(1,0,n-1,pos-1,val);
        }
    }
}