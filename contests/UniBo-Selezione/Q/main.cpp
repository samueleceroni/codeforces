#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int min = arr[0] + arr[n-1];
	for(int i=1; i<n/2; i++){
		if(arr[i]+arr[n-i-1]<min){
			min = arr[i]+arr[n-1-i];
		}
	}
	cout << min;
}