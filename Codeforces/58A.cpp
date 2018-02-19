#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	string str;
	cin >> str;
	string s = "hello";
	int cur = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == s[cur]){
			cur++;
		}
		if(cur == s.size()){
			cout << "YES";
			return 0;
			}
		}	
	
	cout << "NO";
	return 0;
}


