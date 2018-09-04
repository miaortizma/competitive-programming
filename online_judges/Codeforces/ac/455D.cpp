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

const int nmax = 1e5;
int n, m, l, r, q, c, last, tmp;

const int len = ceil(sqrt(nmax));
//const int len = 1;
//block query ans
int e[len+10][nmax+10];
//block
deque<int> b[len+10];

void transform(){
	l = (l + last - 1)%n;
	r = (r + last - 1)%n;
	c = (c + last - 1)%n + 1;
	if(l > r){
		swap(l, r);
	}
}

void move(int l, int r){
	int mov;
	int L = l/len;
	int R = r/len;
	bool terminate = false;
	for(int i = r; l <= i && !terminate; ){
		int x = i/len;
		if( (i+1) % len == 0 && i - len + 1 >= l ){
			//cout << i << "<\n";
			//it means last entire segment
			int add;
			if(x == L){
				if(x == R){	
					add = b[x].back();
				}else{
					add = mov;
				}
				terminate = true;
			}else{
				if(x == R){
					mov = b[x].back();
				}
				add = b[x-1].back();
			}
			e[x][add]++;
			e[x][b[x].back()]--;
			b[x].push_front(add);
			b[x].pop_back();
			i -= len;
		}else{
			//3 cases makes part of left or right incomplete or both are in same incomplete segment
			if(L == R){
				l = l - x*len;
				r = r - x*len;
				mov = b[x][r];
				for(int i = r; i > l; i--){
					b[x][i] = b[x][i - 1];
				}
				b[x][l] = mov;
				terminate = true;
			}else if(x == R){
				r = r - x*len;
				mov = b[x][r];
				for(int i = r; i > 0; i--){
					b[x][i] = b[x][i - 1];
				}
				b[x][0] = b[x-1].back();
				e[x][mov]--;
				e[x][b[x][0]]++;
				i = x*len - 1;
			}else{
				l = l - x*len;
				e[x][b[x].back()]--;
				for(int i = b[x].size(); i > l; i--){
					b[x][i] = b[x][i - 1];
				}
				b[x][l] = mov;
				e[x][mov]++;
				terminate = true;
			}
		}
	}
}

ll query(int l, int r, int c){
	ll ans = 0;
	for(int i = l; i <= r; ){
		int x = i/len;
		if(i % len == 0 && i + len - 1 <= r ){
			ans += e[x][c];	
			i += len;
		}else{
			if(b[x][i - x*len] == c){
				ans++;
			}
			i++;
		}
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		int x = i/len;
		e[x][tmp]++;
		b[x].push_back(tmp);
	}
	cin >> m;
	//cout << len; 
	while(m--){
		cin >> q >> l >> r;
		if(q == 1){
			transform();
			move(l, r);
		}else{
			cin >> c;
			transform();
			last = query(l, r, c);
			cout << last << '\n';
		}
	}
	return 0;
}
