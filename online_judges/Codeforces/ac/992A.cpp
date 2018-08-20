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
	int n, tmp;
	cin >> n;
	set<int> st;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp != 0){
			st.insert(tmp);
		}
	}
	cout << st.size();
	return 0;
}

