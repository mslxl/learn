// Problem: D. Shocking Arrangement
// Contest: Codeforces - Codeforces Round 860 (Div. 2)
// URL: https://codeforces.com/contest/1798/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);

int main() {
  std::size_t t = 1;
  read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  for(std::size_t i = 1; i <= t; i++) solve(t);
  return 0;
}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifdef LOCAL
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)

// clang-format on

void solve(const std::size_t testcase) {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::priority_queue<int, std::vector<int>, std::less<int>> pos, neg;
  int max = 0, min = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    max = std::max(max, a[i]);
    min = std::min(min, a[i]);
    if (a[i] >= 0) {
      pos.push(a[i]);
    } else {
      neg.push(a[i]);
    }
  }
  debug(min, max);
  int value = 0;
  for (int i = 0; i < n; i++) {
    if (value >= 0) {
      if (!neg.empty()) {
        value += neg.top();
        a[i] = neg.top();
        neg.pop();
      } else {
        value += pos.top();
        a[i] = pos.top();
        pos.pop();
      }
    } else {
      if (!pos.empty()) {
        value += pos.top();
        a[i] = pos.top();
        pos.pop();
      } else {
        value += neg.top();
        a[i] = neg.top();
        neg.pop();
      }
    }
    if (value >= max - min) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
  for (auto i : a) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}