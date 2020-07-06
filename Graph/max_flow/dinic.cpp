#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

namespace Dinic {
constexpr int MAX_V = 1010;
struct Edge {
  int to, cap, rev;
};

vector<Edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void addEdge(int from, int to, int cap) {
  G[from].emplace_back(Edge{to, cap, (int)G[to].size()});
  G[to].emplace_back(Edge{from, 0, (int)G[from].size() - 1});
}

void bfs(int s) {
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (const Edge &e : G[v]) {
      if (e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

int dfs(int v, const int t, int f) {
  if (v == t) return f;
  for (int &i = iter[v]; i < (int)G[v].size(); i++) {
    Edge &e = G[v][i];
    if (e.cap > 0 && level[v] < level[e.to]) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int flow = 0;
  while (true) {
    bfs(s);
    if (level[t] < 0) return flow;
    memset(iter, 0, sizeof(iter));
    int f;
    while ((f = dfs(s, t, INF)) > 0) {
      flow += f;
    }
  }
}
}  // namespace Dinic