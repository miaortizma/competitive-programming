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
	vector<int> right;
	stack<int> left;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'l'){
			left.push(i+1);
		}else if(s[i] == 'r'){
			right.push_back(i+1);
		}
	}
	for(int i = 0; i < right.size(); i++){
		cout << right[i] << '\n';
	}
	while(left.size()){
		cout << left.top() << '\n';
		left.pop();
	}
	return 0;
}

