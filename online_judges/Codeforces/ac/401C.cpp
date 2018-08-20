#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
	int color;
	node* before;
	node* next;
};

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, m;
	cin >> n >> m;
	node front, back;
	front.next = &back;
	if(n){
		front.color = 0;
	}
	while(n || m){
		
	}
	return 0;
}


