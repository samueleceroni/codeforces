#include <iostream>
#include <queue>
using namespace std;

int main(){
	string s;
	cin >> s;
	// char first=s[0];
	// int timesF = 1;
	// for (char c:s){
	// 	if(c==first){timesF++;}
	// 	else{timesF--;}
	// 	if(timesF == 0){
	// 		first = c;
	// 		timesF=1;
	// 	}
	// }
	// timesF = 0;
	// for(char c:s){
	// 	if(c==first) timesF++;
	// }
	// cout << timesF<<": "<<first<<endl;

	// int timesS;
	// char second='\0';
	// for(char c:s){
	// 	if(c!=first){
	// 		if(second=='\0'){
	// 			timesS = 1;
	// 			second = c;
	// 		} else {
	// 			if(c==second){timesS++;}
	// 			else{timesS--;}
	// 			if(timesS==0){
	// 				second = c;
	// 				timesS =1;
	// 			}
	// 		}
	// 	}
	// }
	// timesS=0;
	// for(char c:s){
	// 	if(c==second) timesS++;
	// }
	// cout << timesS<<": "<<second<<endl;
	vector<int>fr('z'-'a'+1,0);
	for(char c:s){
		fr[c-'a']++;
	}
	int max1=0, iMax1;
	for(int i = 0; i<fr.size(); i++){
		if(fr[i]>max1){
			max1=fr[i];
			iMax1 = i;
		}

	}
	fr[iMax1]=0;
	int max2=0, iMax2;
	for(int i = 0; i<fr.size(); i++){
		if(fr[i]>max2){
			max2=fr[i];
			iMax2 = i;
		}
	}

	cout << s.length()-max1-max2;
}