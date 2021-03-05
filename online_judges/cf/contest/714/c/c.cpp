#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
typedef long long ll;
struct node {
  map<int, node*> mp;
  ll cnt;
};

node* getNode() {
  node* newNode = new node;
  newNode->cnt = 0;
  newNode->mp[0] = NULL;
  newNode->mp[1] = NULL;
  return newNode;
}

void add(ll a, node *realroot) {
  node *root = realroot;
  if (a == 0) {
    int cur = 0;
    if (!root->mp[cur]) {
      root->mp[cur] = getNode();
    }
    root = root->mp[cur];
    root->cnt += 1ll;
    return;
  }
  while(a) {
    int cur = (a % 2);
    if (!root->mp[cur]) {
      root->mp[cur] = getNode();
    }
    root = root->mp[cur];
    a /= 10ll;
  }
  root->cnt += 1ll;
}

void rem(ll a, node *realroot) {
  node *root = realroot;
  if (a == 0) {
    int cur = 0;
    root = root->mp[cur];
    root->cnt += 1ll;
    return;
  }
  while(a) {
    int cur = (a % 2);
    root = root->mp[cur];
    a /= 10;
  }
  root->cnt -= 1ll;
}

ll query(ll a, node *realroot) {
  node *root = realroot;
  ll ans = 0;
  bool exists = true;
  //cout << ((root->mp[1])->cnt) << "@@@@@@@\n";
  ll x = 0, aa = a;
  while(aa) {
    x += 1;
    aa /= 10ll;
  }
  //cout << x << " " << a << "@@\n"; 
  for (int i = 0; i < 18; ++i) {
    int cur = (a % 2);
    if (exists && root->mp[cur]) {
      root = root->mp[cur];
    } else {
      //cout << "not " << i << "\n";
      exists = false;
    }
    //cout << i << " " << exists << "\n";
    if (exists) {
      if (i >= x -1) ans += root->cnt;
    } else {
      break;
    }
    a /= 10;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll t, a;
  cin >> t;
  node *root = getNode();
  while (t--) {
    char op;
    cin >> op >> a;
    switch (op) {
      case '+':
        add(a, root);
        break;
      case '-':
        rem(a, root);
        break;
      case '?':
        cout << query(a, root) << "\n";
        break;
    }
  }

  return 0;
}
