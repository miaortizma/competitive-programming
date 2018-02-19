#include <bits/stdc++.h>
using namespace std;
#define ll long long

int diff = 'a' - 'A';


bool check(string s){
	for(int i = 1; i < s.size(); i++){
		if(s[i] > 'Z'){
			return false;
		}
	}
	return true;
	
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	string s;
	cin >> s;
	if(check(s)){
		for(int i = 0; i < s.size(); i++){
			if(s[i] > 'Z'){
				cout << char(s[i] - 32);
			}else{
				cout << char(s[i] + 32);
			}
		}
	}else{
		cout << s;
	}
	cout << '\n';
	return 0;
}


