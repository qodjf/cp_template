using ll = long long;

const int MOD = 1e9 + 7;

inline ll mul(ll a, ll b) { return a * b % MOD; }

inline ll add(ll a, ll b) { return (a + b) % MOD; }

inline ll sub(ll a, ll b) {
  int x = (a - b) % MOD;
  return x < 0 ? x + MOD : x;
}

ll my_inv(ll);

ll my_pow(ll a, ll b) {
  if (b < 0) a = my_inv(a), b = -b;
  ll r = 1 % MOD;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}

ll my_inv(ll a) { return my_pow(a, MOD - 2); }

namespace Comb {
const int MAXK = 2e5 + 5;
int fac[MAXK], inv_fac[MAXK];

void init() {
  fac[0] = inv_fac[0] = 1;
  for (int i = 1; i < MAXK; ++i) {
    fac[i] = mul(fac[i - 1], i);
    inv_fac[i] = my_inv(fac[i]);
  }
}

int C(int a, int b) {
  if (a < 0 || b < 0 || b > a) {
    return 0;
  }
  return mul(fac[a], mul(inv_fac[b], inv_fac[a - b]));
}

}  // namespace Comb
