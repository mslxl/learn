#pragma GCC optimize(2)
// clang-format off
#include <bits/stdc++.h> 
using i16 = short; using i32 = int; using i64 = long long; using u16= unsigned short; using u32 = unsigned int; using u64 = unsigned long long;using f32 = float; using f64 = double; using f128 = long double;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>; using pil = std::pair<i32, i64>; using pli = std::pair<i64, i32>;
template<class T> using V = std::vector<T>;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(); void init();
int TESTCASE = 1; int main() { init(); for(int i = 1; i <= TESTCASE; i++){ solve(); if(i != TESTCASE) std::cout << "\n"; } return 0;}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#define TO_STRING(type) void _to_string_##type(std::ostream& buffer, const type& value); std::ostream& operator<<(std::ostream& buff, const type& value){ _to_string_##type(buff, value); return buff; }\
  void _to_string_##type(std::ostream& buffer, const type& value)
template<class T> T lowbit(T x) { return (-x) & x; };
template<class T> T highbit(T x) { while(x != lowbit(x)) x -= lowbit(x); return x; }
template<class T> T fstTrue(T l, T r, std::function<bool(T)> check){ assert(l <= r); while(l < r){ T mid = l + (r - l) / 2; if(check(mid)) r = mid; else l = mid + 1; } return r; }
template<class T> T lstTrue(T l, T r, std::function<bool(T)> check){ assert(l <= r); while(l < r){ T mid = l + (r - l + 1)/2; if(check(mid)) l = mid; else r = mid - 1; } return l; }
template<class T> T gcd(T a, T b) { return std::__gcd(a, b); }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; };
template<const int T> struct MInt { const static int mod = T; int x; MInt(int x = 0) : x(x % mod) {} MInt(long long x) : x(int(x % mod)) {} MInt(unsigned long long x): x(int(x % mod)){} int val() { return x; } MInt operator + (const MInt &a) const { int x0 = x + a.x; return MInt(x0 < mod ? x0 : x0 - mod); } MInt operator - (const MInt &a) const { int x0 = x - a.x; return MInt(x0 < 0 ? x0 + mod : x0); } MInt operator * (const MInt &a) const { return MInt(1LL * x * a.x % mod); } MInt operator / (const MInt &a) const { return *this * a.inv(); } bool operator == (const MInt &a) const { return x == a.x; }; bool operator != (const MInt &a) const { return x != a.x; }; void operator += (const MInt &a) { x += a.x; if (x >= mod) x -= mod; } void operator -= (const MInt &a) { x -= a.x; if (x < 0) x += mod; } void operator *= (const MInt &a) { x = 1LL * x * a.x % mod; } void operator /= (const MInt &a) { *this = *this / a; } friend MInt operator + (int y, const MInt &a){ int x0 = y + a.x; return MInt(x0 < mod ? x0 : x0 - mod); } friend MInt operator - (int y, const MInt &a){ int x0 = y - a.x; return MInt(x0 < 0 ? x0 + mod : x0); } friend MInt operator * (int y, const MInt &a){ return MInt(1LL * y * a.x % mod);} friend MInt operator / (int y, const MInt &a){ return MInt(y) / a;} friend std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.x;} friend std::istream &operator>>(std::istream &is, MInt &t){return is >> t.x;} MInt pow(int64_t n) const { MInt res(1), mul(x); while(n){ if (n & 1) res *= mul; mul *= mul; n >>= 1; } return res; } MInt inv() const { int a = x, b = mod, u = 1, v = 0; while (b) { int t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); } if (u < 0) u += mod; return u; } };
#ifdef LOCAL
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#define maxnum(type) std::numeric_limits<type>::max()
#define minnum(type) std::numeric_limits<type>::min()
#define pb push_back
#define pf push_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define all1(x) ++(x).begin(), (x).end()
#define rall1(x) (x).rbegin(), --(x).rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
template<class R, class A> R mmax(R x, A y){ return std::max(x, (R) y); } template<class R, class A, class... AS> R mmax(R x, A xx, AS... xxs){ return std::max(x, mmax((R)xx, xxs...));  }
template<class R, class A> R mmin(R x, A y){ return std::min(x, (R) y); } template<class R, class A, class... AS> R mmin(R x, A xx, AS... xxs){ return std::min(x, mmin((R)xx, xxs...));  }
using std::cout; using std::cin; using std::endl;
#define endl "\n"
// clang-format on
#define int i64
// using i128 = __int128; 
void init(){
 // read(TESTCASE);
 std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
 std::cin >> TESTCASE; 
}

using Z = MInt<256>;
using Instr = std::tuple<std::string, int, int>;


void solve() {
  int n;
  std::cin >> n;
  V<Instr> ins(n);
  V<int> record(n + 1);
  Z reg(0);
  
  
  for(int i = 0 ; i < n; i++){
    std::string s;
    std::cin >> s;
    std::get<0>(ins[i]) = s;
    if(s == "add"){
      std::cin >> std::get<1>(ins[i]);
    }else{
      std::cin >> std::get<1>(ins[i]) >> std::get<2>(ins[i]);
    }
  }
	int pc = 0;
	
	debug("fin init");
	while(record[pc] < 300){
	  debug(pc,n,record[pc]);
	  if(pc >= n){
	    std::cout << "Yes";
	    return;
	  }
	  
	  std::string a;
	  int v, k;
	  std::tie(a, v, k) = ins[pc];
	  debug(a, v, k, reg);
	  
	  record[pc]++;
	  if(a == "add"){
	    reg = reg + v;
	    pc++;
	  }else if(a == "blt"){
	    if(reg.val() < v){
	      pc = k-1;
	    }else{
	      pc++;
	    }
	  }else if(a == "bgt"){
	    if(reg.val() > v){
	      pc = k-1;
	    }else{
	      pc++;
	    }
	  }else if(a == "beq"){
	    if(reg.val() == v){
	      pc = k-1;
	    }else{
	      pc++;
	    }
	  }else if(a == "bne"){
	    if(reg.val() != v){
	      pc = k-1;
	    }else{
	      pc++;
	    }
	  }else assert(0);
	  debug(pc, reg);
	  
	}
	std::cout << "No";
}
