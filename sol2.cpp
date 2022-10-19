#include <bits/stdc++.h>

#define testcase(p1)  for (auto tc__ = ((p1) ? max(p1, 0) : scan<int>()); tc__--; )
#define else(c)       else if (c)

using llong   = long long;
using uchar   = unsigned char;
using ushort  = unsigned short;
using uint    = unsigned int;
using ullong  = unsigned long long;

template <class T = std::string>
T               scan();
template <class T = std::string>
std::vector<T>  scan_vector(const int&);
template <class T = std::string>
void            print(const T& = T(), const std::string& = "\n");
template <class T>
void            print_vector(const std::vector<T>&, const std::string& = " ");

template <class T>
T scan() {
  static T obj;
  std::cin >> obj;
  return obj;
}
template <class T>
std::vector<T> scan_vector(const int& n) {
  std::vector<T> v(n);
  for (auto i = 0; i < n; ++i) {
    v[i] = scan<T>();
  }
  return v;
}
template <class T>
void print(const T& obj, const std::string& end) {
  std::cout << obj << end;
}
template <class T>
void print_vector(const std::vector<T>& v, const std::string& end) {
  for (auto i = 0; i < int(v.size()); ++i) {
    print(v[i], end);
  }
  if (end != "\n") { print(); }
}

int main() {
#ifdef TINY__
  freopen("input.txt", "r", stdin);
#elif TINY___
  freopen("input.txt", "r", stdin);
  freopen("out2.txt", "w", stdout);
#endif
  using namespace std;
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);

  testcase (0) {
    auto n = scan<int>();
    auto a = scan_vector<int>(n);
    print_vector(a);
    print_vector(a);
  }
}
