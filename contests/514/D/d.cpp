#include <iostream>

using namespace std;



int main(){

	int n;
	cin >> n;

	int maxL, maxR, maxY=0, minY = INF, isPositive = -1, x, y, yOneShot=0;
	for (int i=0; i<n; i++){
		cin >> x >> y;
		if(y>0){
			if(isPositive == -1){
				isPositive = 1;
			} else if (isPositive == 0){
				cout << -1;
				return 0;
			}
		}
		if(y<0){
			if(isPositive == -1){
				isPositive = 0;
			} else if (isPositive == 1){
				cout << -1;
				return 0;
			}
		}
		if(y==0){
			if(yOneShot==1){
				cout << -1;
				return 0;
			}
			else yOneShot = 1;
		}
		if(y!=0){
			if((isPositive == 1 && y>maxY)||(isPositive == 0 && y<maxY)){maxY=y;}
			if((isPositive == 1 && y<minY)||(isPositive == 0 && y>minY)){minY=y;}
		}
		if(x<maxL || i==0){maxL=x;}
		if(x>maxR || i==0){maxR=x}

	}
}