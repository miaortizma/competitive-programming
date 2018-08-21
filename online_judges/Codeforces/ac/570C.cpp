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

const int nmax = 3e5;

int n, q;
int arr1[nmax+1], arr2[nmax+1];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int  q;
	cin >> n >> q;
	string s;
	cin >> s;
	
	int total = 0;
	int cur = 0;
	int segm = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '.'){
			total++;
			cur++;
		}else if (cur > 0){
			segm++;
			cur = 0;
		}
	}
	if(cur > 0){
		segm++;
	}
	int x;
	char c;
	for(int i = 0; i < q; i++){
		cin >> x >> c;
		x--;
		if(s[x] != c){
			bool left = x - 1 >= 0 && s[x-1] == '.';
			bool right =  x + 1 < n && s[x+1] == '.';
			if(s[x] != '.' && c == '.'){
				if(left && right){
					segm--;	
				}else if(!left && !right){
					segm++;
				}
				total++;
			}else if(c != '.' && s[x] == '.'){
				if(left && right){
					segm++;
				}else if(!left && !right){
					segm--;
				}
				total--;
			}	
			s[x] = c;
		}
		//cout << "total: " << total << " segm: " << segm << '\n';
		cout << total - segm << '\n';
	}
	return 0;
}

