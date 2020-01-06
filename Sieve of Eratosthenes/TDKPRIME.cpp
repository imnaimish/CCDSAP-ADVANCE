#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

const int N = 1E8;
int prime[N>>6];

bool notPrime(int x){
	return (prime[x>>6] & (1<<((x>>1)&31)));
}

void makeComposite(int x){
	prime[x>>6] |= (1<<((x>>1)&31));
}

void sieve(){
	memset(prime,0,sizeof prime);

	int maxx = sqrt((double)N)+1;
	for(int i=3;i<=maxx;i+=2){
		if(!notPrime(i)){
			for(int j=i*i,k=i<<1;j<N;j+=k){
				makeComposite(j);
			}
		}
	}
}

int main(){

	FAST;

	sieve();

	vector<int> p;
	p.push_back(2);

	for(int i=3;i<N;i+=2){
		if(!notPrime(i)){
			p.push_back(i);
		}
	}

	int t; cin>>t;
	while(t--){
		int id; cin>>id; --id;
		cout<<p[id]<<'\n';
	}

}