#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


bool myfunction (pair<string,string>p1, pair<string,string> p2) { return (p1.second<p2.second); }

int main(){
	int t;
	vector<pair<string,string> > students;
	cin >> t;
	while(t--){
		pair <string,string> newMate;
		cin >> newMate.first >> newMate.second;
		students.push_back(newMate);
	}
	stable_sort(students.begin(),students.end());
	stable_sort(students.begin(),students.end(), myfunction);
	for(auto st:students){
		cout << st.first << ' ' << st.second << endl;
	}
	return 0;
}