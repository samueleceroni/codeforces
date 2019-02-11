#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

#define INF 1e9

using namespace std;

typedef pair<long long,long long> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

int main(){
	long long n, m, k, temp;
	vi v;
	priority_queue<ii, vii, greater<ii>> pq;
	unordered_map<long long, long long> mappa;
	vi sol;
	cin >> n >> m >> k;

	for(long long i = 0; i<n; i++){
		cin >> temp;
		v.push_back(temp);
		if(pq.size() < k*m || pq.top().first < temp){
			if(pq.size() >= k*m){
				pq.pop();
			}
			pq.push({temp, i});
		}
	}
	long long maxBeauty = 0;
	priority_queue<long long, vi, greater<long long>> secpq;
	while(!pq.empty()){
		maxBeauty += pq.top().first;
		secpq.push(pq.top().second);
		pq.pop();
	}

	cout << maxBeauty << endl;

	for(long long i = 0; i < k-1; i++){
		for(long long j = 0; j < m-1; j++){
			secpq.pop();
		}
		cout << secpq.top() + 1 << ' ';
		secpq.pop();
	}
}