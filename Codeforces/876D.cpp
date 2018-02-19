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

const int NMAX = 300005;
bool used[NMAX];
int N;


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> N;
	int ind, j = N; 
	cout << 1 << ' ';
	for(int i = 0; i < N; i++){
		cin >> ind;
		used[ind] = true;
		while(used[j]) j--;
		cout << 1 + (i + 1 - (N - j)) << ' ';
	}
	return 0;
}

