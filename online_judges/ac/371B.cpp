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

typedef pair<int,int> pii;

int d[] = {2,3,5};

int solve(int a, int b){
	int ans = 0;
	for(int i = 0; i < 3; i++){
		int x = 0, y = 0;
		while(a > 0 && a%d[i] == 0){
			x++;
			a/=d[i];
		}
		while(b > 0 && b%d[i] == 0){
			y++;
			b/=d[i];
		}
		ans += abs(x - y);
	}
	if(a != b){
		return -1;
	}else{
		return ans;
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int a, b;
	cin >> a >> b;
	cout << solve(a, b);
	return 0;
}


