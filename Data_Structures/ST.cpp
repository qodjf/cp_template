#include <bits/stdc++.h>
using namespace std;

namespace ST {
constexpr int MAXN = 2e6 + 10;

int logn[MAXN];
void init() {
  logn[1] = 0;
  for (int i = 2; i < MAXN; i++) {
    logn[i] = logn[i / 2] + 1;
  }
}

template <typename T, T (*op)(const T&, const T&)>
class SparseTable {
 public:
  SparseTable(const vector<T>& a) {
    C = a.size();
    R = logn[C] + 1;
    arr = new T[R * C];

    int n = a.size();
    for (int i = 0; i < n; i++) {
      f(0, i) = a[i];
    }
    for (int k = 1; (1 << k) <= n; k++) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        // [i, i + (1 << k)]
        f(k, i) = op(f(k - 1, i), f(k - 1, i + (1 << (k - 1))));
      }
    }
  }

  // op val of [l, r]
  int query(int l, int r) const {
    int s = logn[r - l + 1];
    return op(f(s, l), f(s, r - (1 << s) + 1));
  }

  ~SparseTable() { delete arr; }

 private:
  T* arr;
  int R = 0, C = 0;
  inline T& f(int i, int j) const { return arr[i * C + j]; }
};
}  // namespace ST

int my_min(const int& a, const int& b) { return min(a, b); }

int main() {
  ST::init();
  vector<int> a = {5, 3, 2, 1, 7};

  ST::SparseTable<int, my_min> st(a);
  cout << st.query(0, 2) << endl;
  cout << st.query(2, 4) << endl;
}
