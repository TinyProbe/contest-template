#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ldouble long double
#define loop(var, init, end) \
        for (llong var = (init), __end = (end), __asc = var < __end; \
                __asc ? var < __end : var-- > __end; \
                __asc ? ++var : var)

class Fastio {
    static constexpr size_t kBufferSize = 1 << 20;
    char read_buffer_[kBufferSize];
    size_t read_len_;
    size_t read_cur_;
    char write_buffer_[kBufferSize];
    size_t write_len_;

public:
    Fastio() : read_len_(), read_cur_(), write_len_() {}
    ~Fastio() { flush(); }

    inline void flush() {
        try {
            if (write_len_ > 0)
                fwrite(write_buffer_, sizeof(char), write_len_, stdout);
            write_len_ = 0;
        } catch (exception const &e) {
            cerr << e.what() << '\n';
        }
    }

    inline Fastio &operator>>(bool &b) {
        char const *token = readtoken_();
        b = !lower_compare_(token, "true") ? true :
                (!lower_compare_(token, "false") ? false : atoll(token));
        return *this;
    }
    inline Fastio &operator>>(char &c) { c = readchar_(); return *this; }
    inline Fastio &operator>>(short &s) { s = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(int &i) { i = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(long &l) { l = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(long long &ll) { ll = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(unsigned char &uc) { uc = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(unsigned short &us) { us = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(unsigned int &ui) { ui = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(unsigned long &ul) { ul = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(unsigned long long &ull) { ull = atoll(readtoken_()); return *this; }
    inline Fastio &operator>>(float &f) { f = atof(readtoken_()); return *this; }
    inline Fastio &operator>>(double &d) { d = atof(readtoken_()); return *this; }
    inline Fastio &operator>>(long double &ld) { ld = atof(readtoken_()); return *this; }
    inline Fastio &operator>>(char *cstr) { strcpy(cstr, readtoken_()); return *this; }
    inline Fastio &operator>>(std::string &str) { str = readtoken_(); return *this; }

    inline Fastio &operator<<(bool b) { return *this << (b ? "true" : "false"); }
    inline Fastio &operator<<(char c) { write_buffer_[write_len_++] = c; return *this; }
    inline Fastio &operator<<(short s) { return *this << std::to_string(s); }
    inline Fastio &operator<<(int i) { return *this << std::to_string(i); }
    inline Fastio &operator<<(long l) { return *this << std::to_string(l); }
    inline Fastio &operator<<(long long ll) { return *this << std::to_string(ll); }
    inline Fastio &operator<<(unsigned char uc) { return *this << (char)uc; }
    inline Fastio &operator<<(unsigned short us) { return *this << std::to_string(us); }
    inline Fastio &operator<<(unsigned int ui) { return *this << std::to_string(ui); }
    inline Fastio &operator<<(unsigned long ul) { return *this << std::to_string(ul); }
    inline Fastio &operator<<(unsigned long long ull) { return *this << std::to_string(ull); }
    inline Fastio &operator<<(float f) { return *this << std::to_string(f); }
    inline Fastio &operator<<(double d) { return *this << std::to_string(d); }
    inline Fastio &operator<<(long double ld) { return *this << std::to_string(ld); }
    inline Fastio &operator<<(char const *cstr) { writestr_(cstr, -1); return *this; }
    inline Fastio &operator<<(std::string const &str) { writestr_(str.c_str(), str.size()); return *this; }

private:
    inline int lower_compare_(char const *lhs, char const *rhs) {
        while (*lhs && *rhs && tolower(*lhs) == tolower(*rhs))
            ++lhs, ++rhs;
        return *lhs - *rhs;
    }

    inline char readchar_() {
        if (read_cur_ == read_len_) {
            read_cur_ = 0;
            try {
                read_len_ = fread(read_buffer_, sizeof(char), kBufferSize, stdin);
            } catch (exception const &e) {
                cerr << e.what() << '\n';
            }
            if (read_cur_ == read_len_)
                return '\0';
        }
        return read_buffer_[read_cur_++];
    }

    inline char const *readtoken_() {
        static char token_buffer[kBufferSize];
        size_t len = 0;
        do
            token_buffer[len] = readchar_();
        while (iswspace(token_buffer[len]));
        while (token_buffer[len] && !iswspace(token_buffer[len]))
            token_buffer[++len] = readchar_();
        token_buffer[len] = '\0';
        return token_buffer;
    }

    inline void writestr_(char const *cstr, size_t len) {
        if (len == (size_t)-1)
            len = strlen(cstr);
        if (write_len_ + len > kBufferSize) {
            flush();
            if (write_len_ + len > kBufferSize) {
                fwrite(cstr, sizeof(char), len, stdout);
                return;
            }
        }
        memcpy(write_buffer_ + write_len_, cstr, len);
        write_len_ += len;
    }
}   fio;

void solve();
int main() {
    int t = 1;
    fio >> t;
    while (t--) { solve(); }
}

void solve() {
}
