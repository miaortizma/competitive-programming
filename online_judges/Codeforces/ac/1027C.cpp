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

double square(int x){
	return x * x;
}

double f(int a, int b){
	return square(2*a + 2*b)/(a*b);
}

int besta, bestb; 
double best;

void check(int a, int b){
	double val = f(a, b);
	/*
	cout << "check: \n";
	cout << a << ' ' << b << '\n';
	cout << best << ' ' << val; 
	*/
	if(val < best){
		best = val;
		besta = a;
		bestb = b;
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int T;
	cin >> T;
	while(T--){
		int n, t;
		cin >> n;
		best = 1e9;
		map<int, int> times, sticks;
		for(int i = 0; i < n; i++){
			cin >> t;
			times[t]++;
			if(times[t]%2 == 0){
				sticks[t]++;
			}
		}
		map<int,int>::iterator it, jt;
		for(it = sticks.begin(); it != sticks.end(); it++){
			if((*it).second > 1){
				check((*it).first, (*it).first);
			}else{
				//cout << (*it).first << '\n';
				if(it != sticks.begin()){
					jt = it;
					jt--;
					//cout << "<";
					check((*it).first, (*jt).first);
				}
				jt = it;
				jt++;
				if(jt != sticks.end()){
					//cout << ">";
					check((*it).first, (*jt).first);
				}
				//cout << '\n';
			}	
		}
		cout << besta << ' ' << besta << ' ' << bestb << ' ' << bestb << '\n';
	}
	return 0;
}

