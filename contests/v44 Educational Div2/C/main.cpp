#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int n, k, l;
	cin >> n >> k >> l;
	int totStaves = n*k;
	map<int,int> staves;
	int temp;
	for(int i = 0; i < totStaves; i++){
		cin >> temp;
		staves[temp]++;
	}
	int min = staves.begin()->first;
	int maxMinV = min+l;
	int currV = maxMinV;
	int toBeCreated = n;
	std::map<int,int>::iterator it;
	if(staves[currV]==0){
		it=staves.find(currV);
		it--;
		currV = it->first;
	} else {
		it = staves.find(currV);
	}
	int totVolume = 0;
	while(toBeCreated>0){
		if(toBeCreated>it->second){
			toBeCreated-=it->second;
			totVolume+=(it->first)*(it->second);
		} else {
			totVolume+=(it->first)*(toBeCreated);
			toBeCreated = 0;
		}
		if(staves.begin()==it && toBeCreated>0){cout<<'0';return 0;}
		it--;
	}
	cout << totVolume;

}