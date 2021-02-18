template <class T = long long>
struct PushRelabel {
  struct Edge {
    int to, rev;
    T f, c;
  };
  int n;
  vector<vector<Edge>> g;
  // 余流
  vector<T> ec;
  vector<int> H, hCnt;
  vector<Edge*> cur;
  // height -> eccess nodes
  vector<vector<int>> hs;
  PushRelabel(int n_)
      : n(n_), g(n), ec(n), cur(n), H(n), hs(2 * n), hCnt(2 * n) {}

  void addEdge(int u, int v, T cap, T rcap = 0) {
    if (u == v) return;
    g[u].push_back({v, sz(g[v]), 0, cap});
    g[v].push_back({u, sz(g[u]) - 1, 0, rcap});
  }

  void addFlow(Edge& e, T f) {
    Edge& rev = g[e.to][e.rev];
    if (!ec[e.to] && f) hs[H[e.to]].push_back(e.to);
    e.f += f, e.c -= f, ec[e.to] += f;
    rev.f -= f, rev.c += f, ec[rev.to] -= f;
  }

  inline void relabel(int u) {
    H[u] = INF;
    for (auto& e : g[u]) {
      if (e.c && chmin(H[u], H[e.to] + 1)) {
        cur[u] = &e;
      }
    }
  }

  bool bfs_init_height(int s, int t) {
    memset(H.data(), INF, sizeof(int) * H.size());
    queue<int> que;
    H[t] = 0;
    que.push(t);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (auto& e : g[u]) {
        int v = e.to;
        Edge& rev = g[e.to][e.rev];
        if (rev.c && chmin(H[v], H[u] + 1)) {
          que.push(v);
        }
      }
    }
    return H[s] != INF;
  }

  T maxFlow(int s, int t) {
    if (!bfs_init_height(s, t)) return 0;
    H[s] = n;
    for (int i = 0; i < n; i++) {
      if (H[i] != INF) {
        hCnt[H[i]]++;
      }
      cur[i] = g[i].data();
    }

    int hi = 0;
    // prevent add t to hs
    ec[t] = 1;
    for (auto& e : g[s]) {
      if (!ec[e.to] && e.c) {
        chmax(hi, H[e.to]);
      }
      addFlow(e, e.c);
    }

    for (;;) {
      while (hs[hi].empty()) {
        if (hi == 0) return --ec[t];
        hi--;
      }

      int u = hs[hi].back();
      hs[hi].pop_back();

      // discharge
      while (ec[u] > 0) {
        if (cur[u] == g[u].data() + sz(g[u])) {
          relabel(u);

          // gap heuristic
          if (++hCnt[H[u]], !--hCnt[hi] && hi < n) {
            for (int i = 0; i < n; i++) {
              if (H[i] > hi && H[i] < n) --hCnt[H[i]], H[i] = n + 1;
            }
          }

          hi = H[u];
        } else if (cur[u]->c && H[u] == H[cur[u]->to] + 1)
          addFlow(*cur[u], min(ec[u], cur[u]->c));
        else
          ++cur[u];
      }
    }
  }
};
