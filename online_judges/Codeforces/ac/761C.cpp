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
#define a(t) get<0>(t) 
#define b(t) get<1>(t) 
#define c(t) get<2>(t) 
#define id(t) get<3>(t) 

typedef tuple<int, int, int, int> data;
int n, m;

int minDist(int j){
	return min(abs(j), abs(m - 1 - j ) + 1);
}

data score(string s, int id){
	data ans;
	id(ans) = id;
	a(ans) = b(ans) = c(ans) = m;
	for(int j = 0; j < m; j++){
		if('0' <=  s[j] && s[j] <= '9') a(ans) = min(a(ans), minDist(j));	
		if('a' <= s[j] && s[j] <= 'z') b(ans) = min(b(ans), minDist(j));
		if(s[j] == '#' || s[j] == '*' || s[j] == '&') c(ans) = min(c(ans), minDist(j));
	}
	return ans;
}

void print(data A){
	cout << id(A) << ":\n";
	cout << a(A) << ' ' << b(A) << ' ' << c(A) << '\n';
}

bool sorta(data A, data B){
	return a(A) < a(B);
}

bool sortb(data A, data B){
	return b(A) < b(B);
}

bool sortc(data A, data B){
	return c(A) < c(B);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> m;
	string arr[n];
	data scores[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		scores[i] = score(arr[i], i);
	}
	bool checked[n];
	memset(checked, false, sizeof(checked));
	data best[3][3];
	sort(scores, scores + n, sorta);
	for(int i = 0; i < 3; i++){
		best[0][i] = scores[i];
	}
	sort(scores, scores + n, sortb);
	for(int i = 0; i < 3; i++){
		best[1][i] = scores[i];
	}
	sort(scores, scores + n, sortc);
	for(int i = 0; i < 3; i++){
		best[2][i] = scores[i];
	}
	int ans = m*n;
	for(int i = 0; i < 3; i++){
		memset(checked, false, sizeof(checked));
		int cur = 0;
		checked[id(best[0][i])] = true;
		cur += a(best[0][i]);
		for(int j = 0; j < 3; j++){
			if(!checked[id(best[1][j])]){
				checked[id(best[1][j])] = true;
				cur += b(best[1][j]);
				break;
			}
		}
		for(int j = 0; j < 3; j++){
			if(!checked[id(best[2][j])]){
				checked[id(best[2][j])] = true;
				cur += c(best[2][j]);
				break;
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}


