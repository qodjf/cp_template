#include <bits/stdc++.h>
using namespace std;

namespace Kruskal {
struct DSU {
  vector<int> fa;
  DSU(int n) {
    fa.resize(n);
    for (int i = 0; i < n; i++) fa[i] = i;
  }
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) { fa[find(y)] = find(x); }
  bool test(int x, int y) { return find(x) == find(y); }
};

struct edge {
  int u, v, cost;
  edge(int u_, int v_, int cost_) : u(u_), v(v_), cost(cost_) {}
  bool operator<(const edge &b) const { return cost < b.cost; }
};

int kruskal(int n, vector<edge> &es) {
  DSU dsu(n);
  sort(es.begin(), es.end());
  int ans = 0;
  for (const auto &e : es) {
    if (!dsu.test(e.u, e.v)) {
      dsu.merge(e.u, e.v);
      ans += e.cost;
    }
  }
  return ans;
}
}  // namespace Kruskal
