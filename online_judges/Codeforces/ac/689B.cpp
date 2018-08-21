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
	int n, t;
	cin >> n;
	typedef pair<int,int> pii;
	priority_queue<pii> q;
	int arr[n], stt[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		stt[i] = n;
		arr[i]--;
	}
	stt[0] = 0;
	q.push(pii(0,0));
	while(q.size()){
		pii T = q.top();
		q.pop();
		int i = T.second, d = T.first;
		if(i - 1 >= 0 && d + 1 < stt[i - 1]){
			stt[i - 1] = d + 1;
			q.push(pii(d + 1, i - 1));
		}
		if(i + 1 < n && d + 1 < stt[i + 1]){
			stt[i + 1] = d + 1;
			q.push(pii(d + 1, i + 1));
		}
		if(d + 1 < stt[arr[i]]){
			stt[arr[i]] = d + 1;
			q.push(pii(d + 1, arr[i]));
		}
	}
	for(int i = 0; i < n; i++){
		cout << stt[i] << ' ';
	}
	return 0;
}


