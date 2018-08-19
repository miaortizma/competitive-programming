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

const int NMAX = 1e5+10;
int id[NMAX];
int sz[NMAX];
int first[NMAX];
int last[NMAX];
int arr[NMAX];
int type[NMAX];


int root(int i){
	while(i != id[i]){
		id[i] = id[id[i]];
		i = id[i];
	} 
	return i;
}

void merge(int a, int b){
	a = root(a), b = root(b);
	if(a == b) return;
	if(sz[b] > sz[a]){
		swap(a , b);
	}
	id[b] = a;
	sz[a] += sz[b];
	first[a] = min(first[a], first[b]);
	last[a] = max(last[a], last[b]);
}


bool islucky(int n){
	while(n > 0){
		if(n%10 != 4 && n%10 != 7 ){
			return false;
		}
		n = n/10;
	}
	return true;
}

bool ispalindrome(int n){
	stringstream ss;
	ss << n;
	string s;
	ss >> s;
	n = s.size();
	for(int i = 0; i < n/2; i++){
		if(s[i] != s[n - 1 - i]){
			return false;
		}
	}
	return true;
}

bool check(int i, int j){
	int n = j - i + 1;
	if(n == 1) return false;
	bool dp[n][2];
	memset(dp, false, sizeof(dp));
	for(int k = i; k <= j; k++){
		
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, k;
	cin >> n >> k;
	bool possible = true;
	sort(arr, arr + n);
	for(int i = 0; i < n; i++){
		id[i] = first[i] = last[i] =i;
		sz[i] = 1;
		cin >> arr[i];
		type[i] = 0;
		if(islucky(arr[i])){
			type[i] = 1;
		}
		if(ispalindrome(arr[i])){
			type[i] = (type[i] == 1) ? 3:2;
		} 
		if(type[i] == 0){
			possible = false;
		}
	}
	if(possible){
			
	}
	if(possible){
		cout << "Yes";
	}else{
		cout << "No";
	}
	
	return 0;
}

