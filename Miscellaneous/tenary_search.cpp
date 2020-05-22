using ll = long long;

ll cost(int x) {}

// get argmin. use '<' instead of '>' to get argmax
ll tenarySearch(ll l, ll r) {
  while (l != r) {
    ll lm = (2 * l + r) / 3;
    ll rm = (l + 2 * r) / 3;
    if (cost(lm) > cost(rm)) {
      l = lm + 1;
    } else {
      r = rm;
    }
  }
  return l;
}
