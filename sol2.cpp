#include <bits/stdc++.h>

#define testcase(t) for (auto tc__ = (t ? max(t, 0) : scan<i32>()); tc__--; )
#define else(c)     else if (c)

template <class T = std::string>
T scan() {
	static T obj;
	std::cin >> obj;
	return obj;
}
template <class T = std::string>
std::vector<T> scan_vector(const int& n) {
	std::vector<T> v(n);
	for (auto& e : v) { e = scan<T>(); }
	return v;
}
template <class T = std::string>
void print(const T& obj = T(), const std::string& end = "\n") {
	std::cout << obj << end;
}
template <class T>
void print_vector(const std::vector<T>& v, const std::string& end = " ") {
	for (auto& e : v) { print(e, end); }
	if (end != "\n") { print(); }
}
void solve();

using namespace std;
using i8 = char;
using i16 = short;
using i32 = int;
using i64 = long long;
using isize = long int;
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using usize = unsigned long int;
using f32 = float;
using f64 = double;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(15);
	testcase (0) { solve(); }
}

void solve() {

}
