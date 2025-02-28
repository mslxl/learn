// Problem: C. Cube
// Contest: Codeforces - The 18th Zhejiang Provincial Collegiate Programming
// Contest URL: https://codeforces.com/group/DERTxRJh4A/contest/103055/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void read_batch(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(const std::size_t testcase);
int main() {
  std::size_t t = 1;
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  read(t); // std::cin >> t;
  for(std::size_t i = 1; i <= t; i++) solve(t);
  return 0;
}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#define TO_STRING(type) void _to_string_##type(std::ostream& buffer, const type& value); std::ostream& operator<<(std::ostream& buff, const type& value){ _to_string_##type(buff, value); return buff; }\
  void _to_string_##type(std::ostream& buffer, const type& value)
#ifdef LOCAL
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#define pb push_back
#define pf push_front
#define mk std::make_pair
#define mt std::make_tuple
#define mmax(a,  b) a = std::max(a, (decltype(a)) b);
#define mmin(a, b) a = std::min(a, (decltype(a)) b);
// clang-format on
typedef long long ll;
#define rep(i, s, e) for (int i = (s); (i) < e; i++)

struct Point {
  int x, y, z;
  Point() {}
  Point(int x, int y, int z) : x(x), y(y), z(z) {}
  bool operator<(const Point b) const {
    if (x != b.x) return x < b.x;
    if (y != b.y) return y < b.y;
    if (z != b.z) return z < b.z;
    return 0;
  }

  ll dis(Point b) const {
    const auto &a = *this;
    return std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2) +
           std::pow(a.z - b.z, 2);
  }
};

Point pts[8];

bool is_cube() {
  ll max_dis = -1;
  rep(i, 0, 8)
      rep(j, 0, i) if (!(pts[i] < pts[j]) && !(pts[j] < pts[i])) return false;

  std::vector<ll> all_dis;
  rep(i, 0, 8) rep(j, 0, i) all_dis.push_back(pts[i].dis(pts[j]));

  std::sort(all_dis.begin(), all_dis.end());
  
  rep(i, 0, 12) rep(j, 0, i) if (all_dis[i] != all_dis[j]) return false;
  rep(i, 0, 12)
      rep(j, 0, i) if (all_dis[12 + i] != all_dis[12 + j]) return false;
  rep(i, 0, 4)
      rep(j, 0, i) if (all_dis[24 + i] != all_dis[24 + j]) return false;
  if (all_dis[0] + all_dis[12] != all_dis[24]) return 0;
  return true;
}

void solve(std::size_t testcase) {
  for (int i = 0; i < 8; ++i) {
    std::cin >> pts[i].x >> pts[i].y >> pts[i].z;
  }
  std::cout << (is_cube() ? "YES\n" : "NO\n");
}
