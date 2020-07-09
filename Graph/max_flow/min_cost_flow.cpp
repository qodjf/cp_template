#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T &a, T b) {
  return a < b && (a = b, true);
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b && (a = b, true);
}

#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 1e9 + 7;

struct MinCostFlow {
  struct Edge {
    int to, cap, cost, rev;
  };

  int V;
  vector<vector<Edge>> G;
  vector<int> h, dist;
  vector<int> prevv, preve;

  MinCostFlow(int V_) {
    V = V_;
    G.resize(V);
    h.resize(V);
    dist.resize(V);
    prevv.resize(V);
    preve.resize(V);
  }

  void addEdge(int from, int to, int cap, int cost) {
    G[from].push_back({to, cap, cost, (int)G[to].size()});
    G[to].push_back({from, 0, -cost, (int)G[from].size() - 1});
  }

  P min_cost_flow(int s, int t, const int expectedFlow) {
    int res = 0, f = 0;
    memset(&h[0], 0, V * sizeof(int));
    while (f < expectedFlow) {
      priority_queue<P, vector<P>, greater<P>> que;
      memset(&dist[0], INF, V * sizeof(int));
      dist[s] = 0;
      que.emplace(0, s);
      while (!que.empty()) {
        P p = que.top();
        que.pop();
        int u = p.second;
        if (dist[u] < p.first) continue;
        for (int i = 0; i < G[u].size(); i++) {
          const Edge &e = G[u][i];
          if (e.cap > 0 &&
              chmin(dist[e.to], dist[u] + e.cost + h[u] - h[e.to])) {
            prevv[e.to] = u;
            preve[e.to] = i;
            que.emplace(dist[e.to], e.to);
          }
        }
      }
      if (dist[t] == INF) {
        // 不能再增广
        break;
      }
      for (int v = 0; v < V; v++) h[v] += dist[v];

      // 沿 s 到 t 的最短路尽量增广
      int d = expectedFlow - f;
      for (int v = t; v != s; v = prevv[v]) {
        d = min(d, G[prevv[v]][preve[v]].cap);
      }
      f += d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        Edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return make_pair(res, f);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int s = 0, t = n + 1;
  MinCostFlow flow(t + 1);
  ll sum = 0;
  // 1..n
  rep(i, 1, n + 1) {
    int stor;
    cin >> stor;
    sum += stor;
    flow.addEdge(s, i, stor, 0);
  }
  int average = sum / n;
  rep(i, 1, n + 1) { flow.addEdge(i, t, average, 0); }
  rep(i, 1, n) {
    flow.addEdge(i, i + 1, INF, 1);
    flow.addEdge(i + 1, i, INF, 1);
  }
  flow.addEdge(n, 1, INF, 1);
  flow.addEdge(1, n, INF, 1);

  P p = flow.min_cost_flow(s, t, INF);
  cout << p.first << endl;
}
