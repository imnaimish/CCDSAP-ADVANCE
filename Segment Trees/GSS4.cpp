#include<bits/stdc++.h>
using namespace std;

int n,q,T=1;
using ll  = long long;
vector<ll> a,t;
vector<bool> ok;

void build(int i, int tl, int tr){
    if(tl > tr)
        return;
    if(tl == tr){
        t[i] = a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(2*i,tl,tm);
    build(2*i+1,tm+1,tr);
    t[i] = t[2*i]+t[2*i+1];
}

ll query(int i, int tl, int tr, int ql, int qr){
    if(tl==ql && tr==qr){
        return t[i];
    }
    int tm = (tl+tr)/2;
    if(qr <= tm){
        return query(2*i,tl,tm,ql,qr);
    }else if(tm < ql){
        return query(2*i+1,tm+1,tr,ql,qr);
    }

    ll ans1 = query(2*i,tl,tm,ql,tm);
    ll ans2 = query(2*i+1,tm+1,tr,tm+1,qr);
    return (ans2+ans1);
}

bool check(int l, int r){
    int ans = query(1,0,n-1,l,r);
    return (ans == (r-l+1));
}

void update(int i, int tl, int tr, int pos){
    if(tl > tr)
        return;
    if(tl == tr){
        if(t[i] >= 0)t[i] = sqrt(t[i]);
        if(t[i] == 1)ok[tl] = true;
        return;
    }

    int tm = (tl+tr)/2;
    if(pos <= tm){
        update(2*i,tl,tm,pos);
    }else{
        update(2*i+1,tm+1,tr,pos);
    }
    t[i] = t[2*i]+t[2*i+1];
}
int main(){
    while(scanf("%d",&n) != EOF){
        a.clear(); t.clear(); ok.clear();
        a.resize(n); t.resize(4*n); ok.assign(n,false);

        for(int i=0;i<n;++i){
            scanf("%lld",&a[i]);
            if(a[i] <= 1)
                ok[i] = true;
        }

        build(1,0,n-1);

        vector<ll> ans;
        scanf("%d",&q);
        while(q--){
            int i; scanf("%d",&i);
            if(i == 0){
                int l,r; scanf("%d%d",&l,&r);
                --l; --r;
                if(l > r)
                    swap(r,l);
                if(!check(l,r)){
                    for(int i=l;i<=r;++i){
                        if(!ok[i])update(1,0,n-1,i);
                    }
                }
            }else{
                int l,r; scanf("%d%d",&l,&r);
                --l; --r;
                if(l > r)
                    swap(r,l);
                ans.push_back(query(1,0,n-1,l,r));
            }
        }
        printf("Case #%d:\n",T);
         ++T;
        for(int i=0;i<ans.size();++i){
            printf("%lld\n",ans[i]);
        }
        printf("\n");
    }

}