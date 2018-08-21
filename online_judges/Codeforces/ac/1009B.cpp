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
	string s;
	cin >> s;
	vector<int> twos;
	int n = s.size();
	int b = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '2'){
			twos.push_back(i);
		}else if(s[i] == '1'){
			b++;
		}
	}
	twos.push_back(n);
	string ans = "";
	int a = 0;
	for(int i = 0; i < twos[0]; i++){
		if(s[i] == '0'){
			a++;
		}
	}
	for(int i = 0; i < a; i++){
		ans += "0";
	}
	for(int i = 0; i < b; i++){
		ans += "1";
	}
	int m = twos.size();
	for(int i = 1; i < m; i++){
		a = 0;
		for(int j = twos[i-1]; j < n && j < twos[i]; j++){	
			if(s[j] == '0'){
				a++;
			}
		}
		ans += "2";
		for(int j = 0; j < a; j++){
			ans +="0";
		}	
	}
	cout << ans;
	return 0;
}


