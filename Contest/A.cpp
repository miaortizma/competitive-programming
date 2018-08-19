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


bool check(string s, int j, string q){
	int n = q.size();
	for(int i = 0; i < n; i++){
		if(s[i + j] != q[i]){
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	string names[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	string s;
	cin >> s;
	int n = s.size();
	int count = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < n; j++){
			if(j+names[i].size() == n + 2) break;
			if(check(s, j, names[i])){
				count++;
			}
		}
	}
	if(count != 1){
		cout << "NO";
	}else{
		cout << "YES";
	}
	return 0;
}

