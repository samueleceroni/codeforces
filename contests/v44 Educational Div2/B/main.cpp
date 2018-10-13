#include <iostream>
#include <vector>
using namespace std;

bool canRemove(vector<int>&switcher, vector<int>&sborn){
	
	for(int i = 0; i<switcher.size(); i++){
		if(switcher[i]==1){
			if(sborn[i]-1==0){
				return false;
			}
		}
	}
	return true;
}


int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > lamps;
	vector<int> sborn(m, 0);

	for(int i = 0; i<n; i++){
		vector<int> newSwitch(m,0);
		string s;
		cin >> s;
		for(int j = 0; j<m; j++){
			if(s[j]=='1'){
				newSwitch[j]=1;
				sborn[j]++;
			}
		}
		lamps.push_back(newSwitch);
	}
	for(auto x:lamps){
		if(canRemove(x, sborn)){cout<< "YES";return 0;}
	}
	cout <<"NO";
}