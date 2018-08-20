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

int rnk(char x){
	map<char,int> mp;
	mp['6'] = 0;
	mp['7'] = 1;
	mp['8'] = 2;
	mp['9'] = 3;
	mp['T'] = 4;
	mp['J'] = 5;
	mp['Q'] = 6;
	mp['K'] = 7;
	mp['A'] = 8;
	return mp[x];
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	char trump;
	cin >> trump;
	string a, b;
	cin >> a >> b;
	bool X = rnk(a[0]) > rnk(b[0]);
	//cout << rank(a[0]) << '\n';
	//cout << rank(b[0]) << '\n';
	bool higher = false;
	if(a[1] == trump ){
		if(b[1] != trump || X){
			higher = true;
		}
	}else if( a[1] == b[1] && X){
		higher = true;
	}
	if(higher){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}


