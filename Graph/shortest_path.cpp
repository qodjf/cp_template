#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;

namespace Dijkstra {
struct edge {
  int to, cost;
};

vector<int> dijkstra(const vector<vector<edge>> &g, int s) {
  vector<int> d(g.size(), INF);
  priority_queue<P, vector<P>, greater<P>> que;
  d[s] = 0;
  que.emplace(0, s);
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    int u = p.second;
    if (d[u] < p.first) continue;
    for (auto &e : g[u]) {
      int v = e.to;
      if (d[v] > d[u] + e.cost) {
        d[v] = d[u] + e.cost;
        que.emplace(d[v], v);
      }
    }
  }
  return d;
}
}  // namespace Dijkstra
