#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class T>
ll inversePairs(vector<T> &a, int l, int r) {
  if (l + 1 >= r) return 0;

  int m = (l + r) / 2;
  ll cnt = inversePairs(a, l, m) + inversePairs(a, m, r);

  vector<T> tmp(a.begin() + l, a.begin() + m);
  int i = 0, lsize = m - l;
  int j = m, tail = l;
  while (i < lsize && j < r) {
    if (tmp[i] > a[j]) {
      cnt += lsize - i;
      a[tail++] = a[j++];
    } else {
      a[tail++] = tmp[i++];
    }
  }
  while (i < lsize) {
    a[tail++] = tmp[i++];
  }

  return cnt;
}
