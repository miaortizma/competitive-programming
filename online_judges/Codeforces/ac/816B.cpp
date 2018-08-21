#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k, q;

struct tree_node{
	int val;
	int sum;
};


tree_node tree[400000];
int lazy[400000];

void update_tree(int node, int a, int b, int i, int j){
	if(lazy[node]!= 0){
		tree[node].val += lazy[node];
		if(a != b){
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(a > b || a > j || b < i) return;
	
	if(a >= i && b <= j){
		tree[node].val += 1;
		if(a != b){
			lazy[node*2] += 1;
			lazy[node*2 + 1] += 1;
		}
		if(tree[node].val >= k){
			tree[node].sum = b - a + 1;
		}
		cout << a << ' ' << b << '\n';
		cout <<"^^";
		return;
	}
	update_tree(node*2, a, (a+b)/2, i, j); 
	update_tree(1+node*2, 1+(a+b)/2, b, i, j);
	tree[node].sum = tree[node*2].sum + tree[node*2 + 1].sum;
}

int query_tree(int node, int a, int b, int i, int j){
	if(a > b || a > j || b < i) return 0;
	if(lazy[node] != 0){
		tree[node].val += lazy[node];
		if(a != b){
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(a >= i && b <= j){
		cout << a << ' '<<b << '\n';
		return tree[node].sum;
	}
	int q1 = query_tree(node*2, a, (a+b)/2, i, j); 
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
	return q1 + q2; 
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	cin >> n >> k >> q;
	int l, r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		update_tree(1, 1, 200000, l, r);
		cout << "****************\n";
	}
	cout << "-------------------\n";
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		cout << query_tree(1, 1, 200000, l, r) << '\n';
	}
	return 0;
}

