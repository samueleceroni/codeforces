#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int i=0, j=1;
	string enc;
	string dec;
	cin >> enc;
	while(i<enc.size()){
		dec+=enc[i];
		i+=j;
		j++;
	}
	cout<< dec;
}