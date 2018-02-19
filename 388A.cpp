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
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	multiset<int> in;
	in.insert(1);
	for(int i = 1; i < n; i++){
		multiset<int>::iterator it = in.upper_bound(arr[i]);
		if(it == in.end()){
			int size = *(in.begin());
			in.erase(in.begin());
			in.insert(size + 1);
		}else if(it == in.begin()){
			in.insert(1);
		}else{
			it--;
			int size = *it;
			in.erase(it);
			in.insert(size + 1);
		}
	}
	cout << in.size() << '\n';
	return 0;
}

