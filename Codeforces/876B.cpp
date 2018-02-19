#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, k, m, c;
	cin >> n >> k >> m;
	int arr[n];
	unordered_map<int,vector<int> > freq;
	for(int i = 0; i < n; i++){
		cin >> c;
		freq[c%m].push_back(c); 	
	}
	for(auto fr : freq){
		if(fr.second.size() >= k){
			cout << "Yes\n";
			for(int i = 0; i < k; i++){
				cout << fr.second[i] << ' ';
			}
			return 0;
		}
	}
	cout << "No"; 
	return 0;
}

