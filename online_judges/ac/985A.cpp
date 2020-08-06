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
	int n;
	cin >> n;
	int arr[n/2];
	for(int i = 0; i < n/2; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n/2);
	int a = 0, b = 0;
	for(int i  = 0; i < n/2; i++){
		a += abs(arr[i] - (i+1)*2+1),
		b += abs(arr[i] - (i+1)*2); 
	}
	cout << min(a, b);
	return 0;
}


