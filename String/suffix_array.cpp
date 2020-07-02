#include <bits/stdc++.h>
using namespace std;

#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

class SuffixArray {
 public:
  // s_ + ' '
  string s;
  // 排序后的后缀
  vector<int> sa;
  // 后缀的序
  vector<int> rank;
  vector<int> lcp;

  SuffixArray(const string& s_) {
    s = s_ + ' ';
    int n = s.size();
    sa.resize(n), rank.resize(n);
    {
      // len = 1
      vector<pair<char, int>> a(n);
      rep(i, 0, n) { a[i] = {s[i], i}; }
      sort(all(a));
      rep(i, 0, n) { sa[i] = a[i].second; }
      rank[sa[0]] = 0;
      rep(i, 1, n) {
        rank[sa[i]] = a[i].first == a[i - 1].first ? rank[sa[i - 1]]
                                                   : rank[sa[i - 1]] + 1;
      }
    }

    for (int len = 1; len < n; len <<= 1) {
      rep(i, 0, n) { sa[i] = (sa[i] - len + n) % n; }
      countSort(sa, rank);

      vector<int> new_rank(n);
      new_rank[sa[0]] = 0;
      rep(i, 1, n) {
        new_rank[sa[i]] =
            rank[sa[i]] == rank[sa[i - 1]] &&
                    rank[(sa[i] + len) % n] == rank[(sa[i - 1] + len) % n]
                ? new_rank[sa[i - 1]]
                : new_rank[sa[i - 1]] + 1;
      }
      rank = new_rank;
    }
  }

  void longestCommonPrefix() {
    int n = s.size();
    lcp = vector<int>(n, 0);
    int k = 0;
    rep(i, 0, n - 1) {
      int prev = sa[rank[i] - 1];
      while (s[i + k] == s[prev + k]) k++;
      lcp[rank[i]] = k;
      k = max(k - 1, 0);
    }
  }

 private:
  void countSort(vector<int>& sa, const vector<int>& rank) {
    int n = sa.size();
    vector<int> count(n + 1, 0);
    rep(i, 0, n) { count[rank[i] + 1]++; }
    rep(i, 1, n) { count[i] += count[i - 1]; }

    vector<int> new_sa(n);
    rep(i, 0, n) { new_sa[count[rank[sa[i]]]++] = sa[i]; }
    sa = new_sa;
  }
};

void printVector(const vector<int>& v, int start) {
  int n = v.size();
  rep(i, start, n) { cout << v[i] << (i == n - 1 ? '\n' : ' '); }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  SuffixArray suffixArray(s);
  suffixArray.longestCommonPrefix();

  printVector(suffixArray.sa, 0);
  printVector(suffixArray.lcp, 1);
}
