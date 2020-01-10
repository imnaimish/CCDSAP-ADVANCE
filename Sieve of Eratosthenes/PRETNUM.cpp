#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

int N = 1E6+5;
vector<bool> prime;
void sieve(){
    prime.assign(N,true);
    prime[0] = prime[1] = false;
    for(ll i=2;i*i<=1E6;++i){
        if(prime[i]){
            for(ll j=i*i;j<=1E6;j+=i){
                prime[j] = false;
            }
        }
    }
}

vector<ll> num,cnt;

int main(){

    FAST;

    sieve();
    int t; cin>>t;
    num.resize(N); cnt.resize(N);
    while(t--){
        ll l,r; cin>>l>>r;
        for(ll i = l; i <= r; ++i){
            num[i-l] = i;
            cnt[i-l] = 1;
        }

        for(ll i=2;i<=1E6;++i){
            if(prime[i]){
                for(ll j = ((l-1)/i + 1)*i; j<=r; j+=i){
                    int p = j-l;
                    int c = 0;
                    while(num[p]%i == 0){
                        num[p] /= i;
                        ++c;
                    }
                    cnt[p] = cnt[p]*(c+1);
                }
            }
        }

        int ans = 0;

        for(int i=0;i<=(r-l);++i){
            if(num[i] > 1){
                cnt[i] = cnt[i]*2;
            }
            if(prime[cnt[i]])++ans;
        }
        cout<<ans<<"\n";
    }

}