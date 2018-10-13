#include <iostream>

using namespace std;

struct wave{
	int time;
	int fun;
	int toWait;
}

bool myfunction (wave w1, wave w2) { return (w1.time<w2.time); }

vector<int>dp;

int sborn(vector<wave> &waves, int instant, int pos){
	if(instant > waves[waves.size()-1].time){return 0;}
	
}

int main(){
	int n;
	cin >> n;
	vector<wave>waves;
	dp.resize(n);
	for (int i=0; i<n;i++){
		dp[i]=0;
	}
	for(int i=0; i<n; i++){
		wave w;
		cin >> w.time >> w.fun >> w.toWait;
		waves.push_back(w);
	}
	sort(waves.begin(), waves.end(), myfunction);
	cout<<sborn(waves, 0, 0);
}