#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const size_t MAXN = 105;
class Mat {
 public:
  ll v[MAXN][MAXN];
  size_t m, n;
  Mat(size_t m_, size_t n_) : m(m_), n(n_) { memset(v, 0, sizeof(v)); }

  Mat operator*(const Mat& b) const {
    Mat c(m, b.n);
    for (int i = 0; i < m; i++) {
      for (int k = 0; k < n; k++) {
        if (v[i][k] == 0) continue;
        for (int j = 0; j < b.n; j++) {
          c.v[i][j] += v[i][k] * b.v[k][j];
        }
      }
    }
    return c;
  }

  void setIdentity() {
    for (int i = 0; i < m; i++) v[i][i] = 1;
  }
};

Mat pow(const Mat& a_, int b) {
  Mat a = a_;
  Mat c(a.m, a.n);
  c.setIdentity();
  while (b) {
    if (b & 1) c = c * a;
    a = a * a;
    b >>= 1;
  }
  return c;
}
