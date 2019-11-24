#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif


int n,m;

bool is_ok(int i, int j, vector<vector<char>> &mat){
	if(i<0 || j<0 || i>=n || j>=m || mat[i][j] == 'X')
		return false;
	return true;
}

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int main(){

	freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

	FAST;

	int t; cin>>t;
	while(t--){

		cin>>n>>m;
		vector<vector<char>> mat(n,vector<char>(m));

		int sx,sy,fx,fy;

		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>mat[i][j];
				if(mat[i][j] == 'S'){
					sx = i; sy = j;
				}
				if(mat[i][j] == 'F'){
					fx = i; fy = j;
				}
			}
		}

		vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
		vector<vector<int>> vis(n,vector<int>(m,0));

		queue<pair<int,int>> q;
		q.push({sx,sy});
		dist[sx][sy] = 0;
		vis[sx][sy] = 255;

		while(!q.empty()){
			pair<int,int> v = q.front();
			q.pop();
			for(int i=0;i<8;++i){
				int x = v.f, y = v.s;
				while(is_ok(x+dx[i], y+dy[i], mat)){
					if(vis[x+dx[i]][y+dy[i]] == 0){
						vis[x+dx[i]][y+dy[i]] = ((1 << i) | 0);
						q.push({x+dx[i], y+dy[i]});
						dist[x+dx[i]][y+dy[i]] = dist[v.f][v.s];
					}else if((vis[x+dx[i]][y+dy[i]] != 0) && !(vis[x+dx[i]][y+dy[i]] & (1 << i)) ){
						vis[x+dx[i]][y+dy[i]] = ((1 << i) | vis[x+dx[i]][y+dy[i]]);
						dist[x+dx[i]][y+dy[i]] = min(dist[x+dx[i]][y+dy[i]] ,dist[v.f][v.s]);
					}else break;

					x = x+dx[i]; y = y+dy[i];
				}
			}

		}

		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<dist[i][j]<<" ";
			}
			cout<<'\n';
		}


		if(dist[fx][fx] == INT_MAX){
			cout<<"-1\n";
		}else{
			cout<<dist[fx][fy]-1<<'\n';
		}
	}
}