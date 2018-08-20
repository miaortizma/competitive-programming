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
	ll n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int cur = arr[0];
	int score = 0;
	for(int i = 1; i < n; i++){
		if(arr[i] > cur ){
			cur = arr[i];
			score = 1;
		}else{
			score++;
		}
		if(score == k){
			break;
		}
	}
	cout << cur;
	return 0;
}

