#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2*1e5;
map< int, int > last, best;
int arr[NMAX], parent[NMAX]; 
int n, a, b, ans, bmax;

int main()
{
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		a = -1;
		b = 1;
		if(last.count(arr[i] - 1)){
			b += best[arr[i] - 1];
			a = last[arr[i] - 1];
		}
		if(b > bmax){
			bmax = b;
			ans = i;
		}
		parent[i] = a;
		best[arr[i]] = b;
		last[arr[i]] = i;
	}
	vector<int> v;
	for(int i = 0; i < bmax; i++){
		v.push_back(ans);
		ans = parent[ans];
	}
	cout << bmax << '\n';
	for(int i = 0; i < bmax; i++){
		cout << v[bmax - i - 1] + 1<< ' ';
	}
	return 0;
}

