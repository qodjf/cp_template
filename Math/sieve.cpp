#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<int> lp;
void linearSieveLp(int N) {
  lp = vector<int>(N + 1, 0);
  for (int i = 2; i <= N; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (p > lp[i] || i * p > N) break;
      lp[i * p] = p;
    }
  }
}
