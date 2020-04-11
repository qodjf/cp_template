namespace KMP {
vector<int> next;

void build(const string &pattern) {
  int n = pattern.length();
  next.resize(n + 1);
  for (int i = 0, j = next[0] = -1; i < n; next[++i] = ++j) {
    while (~j && pattern[i] != pattern[j]) j = next[j];
  }
}

vector<int> match(const string &pattern, const string &text) {
  vector<int> res;
  int n = pattern.length(), m = text.length();
  build(pattern);
  for (int i = 0, j = 0; i < m; ++i) {
    while (~j && text[i] != pattern[j]) j = next[j];
    j++;
    if (j == n) res.push_back(i - n + 1), j = next[j];
  }
  return res;
}
};  // namespace KMP
