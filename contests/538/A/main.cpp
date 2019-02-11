#include<iostream>
#include<vector>

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii> > vvii;

int main(){
	int x, y, z;
	int a, b, c;
	int totRem = 0;
	cin >> x >> y >> z;
	cin >> a >> b >> c;

	totRem = a + b + c;
	if(a < x) {
		cout << "NO"; return 0;
	}
	
	a -= x;
	totRem -= x;

	if(a + b < y){
		cout << "NO"; return 0;
	}

	totRem -= y;

	if (totRem < z){
		cout << "NO"; return 0;
	}

	cout << "YES";

}