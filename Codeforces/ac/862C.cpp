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

const int NMAX = 1e6 + 1;

void binary(int x){
	string s = "";
	while(x){
		if(x&1) s+="1";
		else s +=  "0";
		x/=2;
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
}

bool used[NMAX];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, x, last;
	cin >> n >> x;
	used[x] = true;
	n--;
	cout << x << '\n';
	bool ok = true;
	while(n > 0){
		int i;
		for( i = last; i < NMAX; i++){
			if(!used[(x^i)] && !used[i]){
				cout << x <<": " << i <<"^" << (x^i) << '\n';
				used[x] = false;
				used[i] = true;
				used[(x^i)] = true;
				x = (x^i);
				last = min(i, (x^i)) + 1;
				break;
			}
		}
		if(i == NMAX) ok = false;
		n--;	
	}
	if(ok){
		cout << "YES\n";
		for(int i = 1; i <NMAX; i++){
		if(used[i]) cout << i << ' ';
	}	
	}else{
	cout << "NO";	
	}
	
		return 0;
}

