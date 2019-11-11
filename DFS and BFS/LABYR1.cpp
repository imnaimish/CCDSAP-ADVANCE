#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

vector<vector<char>> mat;
vector<vector<bool>> vis;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int row,col,p,q,diameter;

bool check(int i, int j){
	if(i<0 || j<0 || i>=row || j>=col || mat[i][j]=='#')
		return false;
	return true;
}

void dfs(int i, int j, int cnt){
	vis[i][j] = true;
	++cnt;
	for(int k=0;k<4;++k){
		if(check(i+dx[k],j+dy[k]) && !vis[i+dx[k]][j+dy[k]]){
			if(cnt >= diameter){
				diameter = cnt; q = j+dy[k], p = i+dx[k];
			}
			dfs(i+dx[k], j+dy[k], cnt);
		}
	}
}

int main(){

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	
	int t; cin>>t;
	while(t--){
		cin>>col>>row;

		mat.clear(); vis.clear();
		mat.assign(row,vector<char>(col));
		vis.assign(row,vector<bool>(col,false));

		int x=-1,y=-1;
		for(int i=0;i<row;++i){
			for(int j=0;j<col;++j){
				cin>>mat[i][j];
			}
		}

		for(int i=0;i<row;++i){
			bool f = false;
			for(int j=0;j<col;++j){
				if(mat[i][j] == '.'){
					x = i; y = j; f = true; break;
				}
			}
			if(f)break;
		}

		if(x==-1 || y==-1){
			cout<<"Maximum rope length is 0.\n";
			continue;
		}

		diameter = 0;
		dfs(x,y,0);

		diameter = 0;
		vis.assign(row,vector<bool>(col,false));
		dfs(p,q,0);

		cout<<"Maximum rope length is "<<diameter<<".\n";

	}
	

}