#include <iostream>
#include<vector>
#include<utility>
using namespace std;

bool findPath(int currNode, vector<int> &g, const vector<pair<int,int> > &dir, vector<int> &visited, int &nVisited){
	if(currNode == 1 && nVisited == g.size()-1){return true;}
	visited[currNode] = true;
	nVisited++;
	// ho gia una strada da provare a percorrere
	if(g[currNode]!=0){return findPath(g[currNode], g, dir, visited, nVisited);}

	// non so dove andare
	if(visited[dir[currNode].first] || visited[dir[currNode].second]){
		return false;	//uno dei due e' stato visitato
	}
	visited[dir[currNode].second] = true;
	visited[dir[currNode].first] = true;
	g[currNode] = dir[currNode].first;
	g[dir[currNode].first] = dir[currNode].second;
	if(!findPath(g[dir[currNode].first], g, dir, visited, nVisited)){
		g[currNode] = dir[currNode].second;
		g[dir[currNode].second] = dir[currNode].first;
		return findPath(g[dir[currNode].second], g, dir, visited, nVisited);
	} else {
		return true;
	}
}

int main(){
	int n;
	cin >> n;
	vector<pair<int,int> > dir(n+1);
	vector<int> visited(n+1, false);
	int nVisited = 0;
	vector<int> g(n+1,0);
	for(int i = 1; i<= n; i++){
		cin >> dir[i].first >> dir[i].second;
	}

	findPath(1, g, dir, visited, nVisited);

	cout <<"1 ";
	int currNode = g[1];
	while(currNode != 1){
		cout<<currNode<<' ';
		currNode = g[currNode];
	}

}