#include <bits/stdc++.h>
using namespace std;
#define ll long long

string next(string str){
	stringstream ss;
	ss << str.substr(0,2) << ' ' << str.substr(3,2);
	int a, b;
	ss >> a >> b;
	b++;
	if(b == 60){
		b = 0;
		a++;
		if(a == 24){
			a = 0;
		}
	}
	string str1, str2;
	stringstream sa;
	if(a < 10){
		sa << "0" << a; 
	}else{
		sa << a;
	}
	sa << ":";
	if(b < 10){
		sa << "0" << b;
	}else{
		sa << b;
	}
	return sa.str();
}

bool ispalindrome(string str){
	for(int i = 0; i < 2; i++){
		if(str[i] != str[4 - i]){
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
	string time;
	cin >> time;
	int cnt = 0;
	
	while(!ispalindrome(time)){
		time = next(time);
		cnt++;
	}
	cout << cnt;

	return 0;
}

