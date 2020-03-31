    #include<bits/stdc++.h>
    using namespace std;
     
     
    const int N = 1e5 + 100;
    int A[N], B[N], C[N];
     
    int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(NULL);
      int t;
      cin >> t;
      while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
          cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
          cin >> B[i];
        }
        bool ok = true;
        int components = 0;
        C[0] = B[0] - A[0];
        if (C[0] < 0)
          ok = false;
        if (C[0] > 0)
          components = 1;
        for (int i = 1; i < n; ++i) {
          C[i] = B[i] - A[i];
          if (C[i] < 0)
            ok = false;
          if (C[i] > 0) {
            if (C[i - 1] > 0) {
              if (C[i - 1] != C[i])
                ok = false;
            } else {
              components++;
            }
          }
        }
        if (components <= 1 && ok) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
      return 0;
    }
