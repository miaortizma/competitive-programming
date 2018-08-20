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

bool rec(int col, int row){
	if(col == 0 && row == 0){
		return false;
	}else{
		return !rec();
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, m;
	cin >> n >> m;
	bool moves[n*m+1];
	for(int i = 2; i < )

	return 0;
}
