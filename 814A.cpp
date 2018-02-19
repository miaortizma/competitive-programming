#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int a, b;
	cin >> a >> b;
	vector<int> A;
	map<int,int> B;
	int t;
	bool flag = false, seen = false;
	for(int i = 0; i < a; i++){
		cin >> t;
		A.push_back(t);
	}
	for(int i = 0; i < b; i++){
		cin >> t;
		B[t]++;
	}
	if(B.size() >= 2){
		flag = true;
	}else{
		int mx = 0, mn = B.begin()->first;
		for(int i = 0; i < a; i++){
			if(A[i] == 0){
				if( mn < mx ){
					flag = true;
					break;
				}
				seen = true; 
			}else{
				mx = max(mx, A[i]);
				if(A[i] != mx || (seen && mn < A[i])){
					flag = true;
					break;
				}
			}
		}
	}
	
	if(flag2 || flag1){
		cout << "Yes";
	}else{
		cout << "No";
	}
	int mx = 0;
	return 0;
}

