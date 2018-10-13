#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;
int m,n;
vector<vector<int> > grid;

int findPath(int x, int y, vector<vector<int> >&memo){
	if(y == m-1 && x == n-1){ return 0;}
	if( y >= m || x >= n ){ return -1;}
	if(memo[x][y]<INF){return memo[x][y];}
	int toR, toD, tempMin;
	toR = findPath(x+grid[x][y], y, memo);
	toD = findPath(x, y+grid[x][y], memo);
	if(toD ==-1 && toR == -1){
		memo [x][y]=-1;
		return -1;
	}
	if(toD==-1){
		memo[x][y] = toR;
		return toR;
	}
	if(toR == -1){
		memo[x][y] = toD;
		return toD;
	}
	memo [x][y] = 1 + min(toD,toR);
	return memo[x][y];
}


int main(){
	int x=0,y=0;
	cin >> m >> n;
	vector<vector<int> > memo(m,vector<int> (n,INF));
	for (int i=0; i<m; i++){
		vector<int>row;
		string rowc;
		cin >>rowc;
		for(char c:rowc){
			row.push_back(c-'0');
		}
		grid.push_back(row);
	}


	int tempor = findPath(0,0,memo);
	if(tempor == -1){cout<<"IMPOSSIBLE";}
	else {cout << tempor+1;}

}