#include <iostream>
#include<vector>
#include<utility>
using namespace std;

bool findPath(const vector<pair<int,int> > &g, vector<int> &sol, int solPos, vector<bool> &visited, int &nVisited){
	if(nVisited = g.size()-1 && (g[sol.back()].first == 1 || g[sol.back()].second == 1)){return true;}
	int node = sol[solPos];
	if(visited[node] == true){return false;}
	visited[node] = true;
	nVisited++;
	//check se tutti son visitati

	if(sol.size()-1 > solPos){	// qualcuno dopo di me
		// if(visited[sol[solPos+1]]==true){ //dopo di me gia visitato ma e' il nodo di partenza e tutti son stati visitati
		// 	sol.pop_back();
		// 	return true;
		// }
		if(visited[sol[solPos+1]]==true){ //dopo di me gia visitato
			visited[node] = false;
			nVisited--;
			return false;
		} else // dopo di me non ancora visitato
		return findPath(g, sol, solPos+1, visited, nVisited);
	} else {	//nessuno dopo di me
		// provo le due strade
		sol.push_back(g[node].first);
		sol.push_back(g[node].second);
		if(!findPath(g, sol, solPos+1, visited, nVisited)){ // se da falso in un modo prova l'altro
			sol.pop_back();
			sol.pop_back();
			sol.push_back(g[node].second);
			sol.push_back(g[node].first);
			return findPath(g, sol, solPos+1, visited, nVisited); // vedi come va il secondo modo
		} else {
			return true; //il primo modo ha funzionato
		}
	}

}

int main(){
	int n;
	cin >> n;
	vector<pair<int,int> > g(n+1);
	vector<int> sol;
	vector<bool> visited(n+1, false);
	int nVisited = 0;
	sol.reserve(n);
	for(int i=1; i<n+1; i++){
		cin >> g[i].first >> g[i].second;
	}
	sol.push_back(g[1].first);
	sol.push_back(g[1].second);
	if(!findPath(g, sol, 0, visited, nVisited)){
		sol.pop_back();
		sol.pop_back();
		sol.push_back(g[1].second);
		sol.push_back(g[1].first);
		findPath(g, sol, 0, visited, nVisited);
	}
	for(auto x:sol){
		cout << x;
	}
}