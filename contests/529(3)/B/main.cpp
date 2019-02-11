#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v){
		cin >> x;
	}
	if(n <=2){cout << 0;return 0;}
	sort(v.begin(), v.end());
	cout<<min(v.back()-v[1], v[v.size()-2]-v[0]);
	return 0;
}