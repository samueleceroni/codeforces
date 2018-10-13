#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){

	vector<int>t1(3);
	vector<int>t2(3);
	cin >> t1[0]>> t1[1]>> t1[2]>>t2[0]>>t2[1]>>t2[2];
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	if(t1[0]*t1[0] + t1[1]*t1[1] != t1[2]*t1[2]){cout <<"NO";return 0;}
	if(t2[0]*t2[0] + t2[1]*t2[1] != t2[2]*t2[2]){cout <<"NO";return 0;}

	if(t1[2]!=t2[2]){cout << "NO";return 0;}
	if((t1[0]==t2[0] && t1[1]==t2[1]) || (t1[0]==t2[1] && t1[1]==t2[0])){
		cout << "YES";return 0;
	} else{
		cout<<"NO";return 0;
	}
}