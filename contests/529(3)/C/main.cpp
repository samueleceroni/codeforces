#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int findMaxPow(int n){
	int i = 1;
	while(n>i){
		i*=2;
	}
	if(n<i){
		i/=2;
	}
	return i;
}


void isPossible(int n, int k, vector<int> &v){
	int remaining = n, maxPow;
	do{
		maxPow = findMaxPow(remaining);
		remaining -= maxPow;
		v.push_back(maxPow);
	}while(remaining>0);
	if(v.size()>=k){
		return;
	}
	int i = 0;
	while(v.size() < k && i < v.size()){
		if(v[i]==1){i++;continue;}
		int curr = v[i];
		v[i]/=2;
		v.push_back(curr/2);
	}	
}

int main(){
	int n, k;
	vector<int> sol;
	cin >> n >> k;
	isPossible(n,k,sol);
	if(sol.size()==k){
		cout << "YES" << endl;
		for(auto x : sol){
			cout << x << ' ';
		}
	} else {
		cout << "NO";
	}
}