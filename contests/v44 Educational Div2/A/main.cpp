#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, temp;
	cin >> n;
	vector<int> pieces(n, 0);
	for(int i = 0; i<n/2; i++){
		cin >> temp;
		pieces[temp-1]=1;
	}

	// try to even
	int currPiece = 0, movesEven=0;
	for(int i = 0; i<n; i++){
		if(pieces[i]==1){
			movesEven+=abs(currPiece-i);
			currPiece+=2;
			if(currPiece>n){
				break;
			}
		}

	}
	// try to odd
	int movesOdd=0;
	currPiece = 1;
	for(int i = 0; i<n; i++){
		if(pieces[i]==1){
			movesOdd+=abs(currPiece-i);
			currPiece+=2;
			if(currPiece>n){
				break;
			}
		}

	}

	cout<<min(movesOdd,movesEven);
}