#include <bits/stdc++.h>
using namespace std;

template <typename ValueType, ValueType defaultVal,
          void (*chadd)(ValueType&, ValueType)>
class BIT {
 private:
  vector<ValueType> a;
  int n;
  inline int lowbit(int x) { return x & -x; }

 public:
  BIT(int n_) : n(n_) { a = vector<ValueType>(n + 1, defaultVal); }

  ValueType sum(int k) {
    ValueType s = defaultVal;
    while (k >= 1) {
      chadd(s, a[k]);
      k -= lowbit(k);
    }
    return s;
  }

  void add(int k, ValueType x) {
    while (k <= n) {
      chadd(a[k], x);
      k += lowbit(k);
    }
  }
};
