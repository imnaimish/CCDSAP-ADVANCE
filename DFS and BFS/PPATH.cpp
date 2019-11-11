#include<bits/stdc++.h>
using namespace std;


#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

bool prime[10000];
void sieve(){
	memset(prime, true, sizeof prime);
	prime[0] = prime[1] = false;

	for(int i=2;i*i<=10000;++i){
		if(prime[i]){
			for(int j=i*i;j<=10000;j+=i){
				prime[j] = false;
			}
		}
	}
}


int main(){
	FAST;

	sieve();

	int t; cin>>t;
	while(t--){
		string a,b; cin>>a>>b;
		if(a==b){
			cout<<"0\n"; continue;
		}

		map<string,int> dist;
		queue<string> q;

		bool f = false;

		q.push(a);
		dist[a] = 0;

		while(!q.empty()){
			string v = q.front();

			q.pop();
			bool g = false;
			for(int i=0;i<4;++i){
				for(int j=0;j<=9;++j){
					if(i==0 && j==0)continue;
					string temp = v;
					temp[i] = (char)('0'+j);

					int x = stoi(temp);

					if(prime[x] && dist.find(temp)==dist.end()){
						
						dist[temp] = dist[v]+1;
						q.push(temp);

						if(temp == b){
							f = true; g = true; break; 
						}

					}
					if(g)break;
				}
				if(g)break;
			}
		}	

		if(f){
			cout<<dist[b]<<'\n';
		}else{
			"Impossible\n";
		}
	}
}