#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> fa;
  DSU(int n) {
    fa.resize(n);
    for (int i = 0; i < n; i++) fa[i] = i;
  }
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) { fa[find(y)] = find(x); }
  bool test(int x, int y) { return find(x) == find(y); }
  int countDS() {
    int cnt = 0;
    for (int i = 0; i < fa.size(); i++) {
      if (find(i) == i) cnt++;
    }
    return cnt;
  }
};
