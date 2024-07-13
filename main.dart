import "dart:io";
import "dart:core";

class Scanner {
  var _words = List.empty(growable: true);
  var _idx = 0;

  Scanner() {
    String buffer = "";
    while (true) {
      String? ln = stdin.readLineSync();
      if (ln == null) { break; }
      buffer += ln!;
    }
    _words = buffer.split(" ");
    _words.removeWhere((item) => item.isEmpty);
  }
  String? _nextItem() {
    if (_idx < _words.length) {
      return _words[_idx++];
    }
    return null;
  }
  T? next<T extends Object>() {
    if (T == String) {
      return _nextItem()! as T;
    } else if (T == int) {
      return int.parse(_nextItem()!) as T;
    } else if (T == double) {
      return double.parse(_nextItem()!) as T;
    } else if (T == bool) {
      return bool.parse(_nextItem()!) as T;
    }
    return null;
  }
}

var sc = Scanner();

void main() {
  var t = 1;
  t = sc.next<int>()!;
  while (t-- > 0) { solve(); }
}

void solve() {
  print("hello world!");
}
