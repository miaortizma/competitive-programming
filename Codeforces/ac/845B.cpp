#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin >> s;
	int a = 0, b;
	vector<int> A, B;
	for(int i = 0; i < 6; i++){
		if(i < 3){
			a += s[i] - '0';
			A.push_back(s[i] - '0');
		}else{
			b += s[i] - '0';
			B.push_back(s[i] - '0');
		}
	}
	if(a > b){
		swap(a,b);
		swap(A,B);
	}
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	
	int best = (a == b)?0:6;
	for(int i = 0; i <= b - a; i++){
		int s = b - a - i, cura = 0, curb = 0, next, cur = 0;
		for(int j = 0; j < 3; j++ ){
			if(cura < i){
				cur++;
				next = min(9, i - cura);
				cura += next - A[j];  
			}
			if(curb < s){
				cur++;
				next = max(0, B[j] - s + curb);
				curb += B[j] - next;
			}
		}
		best = min(best, cur);
	}
	cout << best << '\n';
	return 0;
}

