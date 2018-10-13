#include <iostream>

using namespace std;

int main(){
	int n, l, a;
	cin >> n >> l >> a;
	int currT=0, totBreaks=0;

	for (int i=0; i<n; i++){
		int arr, time;
		cin >> arr >> time;
		if(arr-currT >= a){
			totBreaks+=(arr-currT)/a;
		}
		currT=arr+time;
	}
	if(currT<l){
		totBreaks+=(l-currT)/a;
	}


	cout << totBreaks;
}