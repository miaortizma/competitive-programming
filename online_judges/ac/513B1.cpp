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

int check(vector<int> v, int tetra){
	int n = v.size();
	int ans = 0; 
	for(int i = 0; i < n; i++){
		int temp = v[i];
		for(int j = i; j < n; j++){
			temp = min(temp, v[j]);
			ans += temp;
		}
	}
	if(tetra == ans){
		for(int i = 0; i < n; i++){
			cout << v[i] << ' ';
		}
		cout << "\n value: " << ans << '\n';
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ll n, m;
	cin >> n >> m;
	m--;
	deque<int> v;
	v.push_back(n);
	for(ll i = 0; i < n - 1; i++){
		if((m & (1LL << i))){
			v.push_back(n - 1LL - i);	
		}else{
			v.push_front(n - 1LL - i);
		}
	}
	for(int i = 0; i < n; i++){
		cout << v[i] << ' ';
	}
	return 0;
}


