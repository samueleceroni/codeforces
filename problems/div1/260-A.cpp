
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
9
1 2 1 3 2 2 2 2 3
1 2 2 2 2 2 3 3
*/

map<long long int,long long int> dp;

long long int getBestScore(vector<pair<long long int,long long int> > &v, long long int i){
    if(i >= v.size()){return 0;}
    if(dp.find(i) != dp.end()) {return dp[i];}
    //take
    long long int t = v[i].second*v[i].first;
    if(i < v.size()-1 && v[i+1].first == v[i].first+1){
        t += getBestScore(v, i+2);
    } else {
        t += getBestScore(v, i+1);
    }
    //don't take
    long long int dt = getBestScore(v, i+1);
    // check max
    dp[i] = max(t, dt);
    return dp[i];
}

int main(){
    long long int n;
    cin >> n;
    //vector<long long int> v(n);
    long long int temp;
    map<long long int,long long int> x;
    for(long long int i=0; i<n; i++){
        //cin >> v[i];
        //x[v[i]]++;
        cin >> temp;
        x[temp]++;
    }
    vector<pair<long long int,long long int> > z(x.begin(), x.end());
    if(z.size()==1){cout << z[0].first*z[0].second;return 0;}
    cout << getBestScore(z, 0);
}