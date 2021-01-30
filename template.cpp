/**
 *     author: qodjf
 *     created: $%M%$.$%D%$.$%Y%$ $%h%$:$%m%$:$%s%$
 */
#include <bits/stdc++.h>
using namespace std;

// type
using ll = long long;
using db = long double;  // or double, if TL is tight

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define tcT template <class T
#define tcTU tcT, class U
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define rsz resize
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define EACH(a, x) for (auto& a : x)

// INPUT
#define tcTUU tcT, class... U
tcT > void re(complex<T>& c);
tcTU > void re(pair<T, U>& p);
tcT > void re(V<T>& v);
tcT, size_t SZ > void re(AR<T, SZ>& a);

tcT > void re(T& x) { cin >> x; }
void re(double& d) {
  string t;
  re(t);
  d = stod(t);
}
void re(long double& d) {
  string t;
  re(t);
  d = stold(t);
}
tcTUU > void re(T& t, U&... u) {
  re(t);
  re(u...);
}

tcT > void re(complex<T>& c) {
  T a, b;
  re(a, b);
  c = {a, b};
}
tcTU > void re(pair<T, U>& p) { re(p.f, p.s); }
tcT > void re(V<T>& x) { EACH(a, x) re(a); }
tcT, size_t SZ > void re(AR<T, SZ>& x) { EACH(a, x) re(a); }
tcT > void rv(int n, V<T>& x) {
  x.rsz(n);
  re(x);
}

// DEBUG
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

// OUTPUT
template <class T>
void pr(vector<T>& v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    cout << v[i] << (i == n - 1 ? '\n' : ' ');
  }
}

void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
// FILE I/O
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  unsyncIO();
  setPrec();
  // cin.exceptions(cin.failbit);
  // throws exception when do smth illegal
  // ex. try to read letter into int
  if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  // for USACO
}

// utility
template <class T>
inline bool chmax(T& a, T b) {
  return a < b && (a = b, true);
}
template <class T>
inline bool chmin(T& a, T b) {
  return a > b && (a = b, true);
}

#define mst(x, a) memset(x, a, sizeof(x))

// const
constexpr int INF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 1e9 + 7;
const db PI = acos((db)-1);
constexpr int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve() {}

int main() {
  setIO();

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
