#include <bits/stdc++.h>

template <class t = std::string>
t               scan();
template <class t = std::string>
std::vector<t>  scan_vector(const int&);
template <class t = std::string>
void            print(const t& = t(), const std::string& = "\n");
template <class t>
void            print_vector(const std::vector<t>&, const std::string& = " ");

template <class t>
t scan() {
  static t obj;
  std::cin >> obj;
  return obj;
}
template <class t>
std::vector<t> scan_vector(const int& n) {
  std::vector<t> v(n);
  for (auto i = 0; i < n; ++i) {
    v[i] = scan<t>();
  }
  return v;
}
template <class t>
void print(const t& obj, const std::string& end) {
  std::cout << obj << end;
}
template <class t>
void print_vector(const std::vector<t>& v, const std::string& end) {
  for (auto i = 0; i < int(v.size()); ++i) {
    print(v[i], end);
  }
  if (end != "\n") { print(); }
}

#define loop(t) for (auto time__ = ((t) ? max(t, 0) : scan<int>()); time__--; )
#define else(c) else if (c)

using namespace std;
using llong   = long long;
using uchar   = unsigned char;
using ushort  = unsigned short;
using uint    = unsigned int;
using ullong  = unsigned long long;

int main() {
#ifdef TINY__
  freopen("input.txt", "r", stdin);
#elif TINY___
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);

  loop (0) {
    
  }
}
