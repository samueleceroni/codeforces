#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> floors(k+1,2);//0 safe, 1 broken
	floors[0] = 0;
	floors[k] = 1;
	int maxSafe = 1;
	int minBroken = k;
	while(n--){
		int fl;
		string state;
		cin >> fl >> state;
		if(state == "SAFE"){
			floors[fl] = 0;
			if(fl>maxSafe){maxSafe = fl;}
		} else {
			floors[fl] = 1;
			if(fl<minBroken){minBroken = fl;}
		}
	}
	if(floors[maxSafe+1] == 2){
		maxSafe++;
		minBroken--;
	} else {
		int temp = maxSafe;
		maxSafe = minBroken;
		minBroken = temp;
	}

	cout << maxSafe << ' ' << minBroken;

}