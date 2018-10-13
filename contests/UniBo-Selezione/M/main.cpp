#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int>num(100);
	for (int i=1; i<=100; i++){
		num[i-1]=i;
	}
	int n;
	cin >> n;
	string s;
	int k;
	for(int i=0; i<n; i++){
		cin >> s >> k;
		for(int i=0; i<100; i++){
			if(s=="SUBTRACT"){
				num[i]-=k;
			} else if(s=="DIVIDE"){
				num[i]/=k;
			} else if(s=="ADD"){
				num[i]+=k;
			} else if(s=="MULTIPLY"){
				num[i]*=k;
			}
		}
		vector<int> newVector;
		int prev=num[0];
		for (int h:num){
			if(h!=prev && h>=0){
				newVector.push_back(h);
				prev = h;
			}
		}
		num = newVector;
	}
	cout<<100-num.size();
}