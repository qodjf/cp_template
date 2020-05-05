#include <bits/stdc++.h>
using namespace std;

int slideWindow(const vector<int> &nums) {
  auto test = [&](int l, int r) -> bool {
    // test [l, r)
    return true;
  };

  auto addRight = [&](int r) -> void {
    // add r to window
  };

  auto removeLeft = [&](int l) -> void {
    // remove l from window
  };

  int n = nums.size();
  int l = 0, r = 0, ans = 0;
  while (true) {
    if (test(l, r)) {
      ans = max(ans, r - l);
      if (r >= n) break;
      addRight(r);
      r++;
    } else {
      removeLeft(l);
      l++;
    }
  }
  return ans;
}
