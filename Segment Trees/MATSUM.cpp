#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bit;
int n;

void updatey(int x, int y, int val){
  while(y <= n){
    bit[x][y] += val;
    y += (y&-y);
  }
}

void update(int x, int y, int val){
  while(x <= n){
    updatey(x, y, val);
    x += (x&-x);
  }
}

int ready(int x, int y){
  int sum = 0;
  while(y > 0){
    sum += bit[x][y];
    y -= (y&-y);
  }
  return sum;
}

int read(int x, int y){
  int sum = 0;
  while(x > 0){
    sum += ready(x,y);
    x -= (x&-x);
  }
  return sum;
}

int find_sum(int x1, int y1, int x2, int y2){
  return (read(x2,y2) - read(x2,y1-1) - read(x1-1,y2) + read(x1-1,y1-1));
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin>>t;

  while(t--){
    cin>>n;

    bit.clear();

    bit.assign(n+1,vector<int>(n+1,0));
    vector<vector<int>> num(n+1,vector<int>(n+1));

    while(1){
      string s; cin>>s;
      if(s == "END")break;

      if(s == "SET"){
        int x,y,val; cin>>x>>y>>val;
        ++x; ++y;

        update(x,y,val-num[x][y]);
        num[x][y] = val;
      }else{
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        ++x1; ++y1; ++x2; ++y2;
        int sum = find_sum(x1,y1,x2,y2);
        cout<<sum<<'\n';
      }
    }
    cout<<'\n';
  }
}