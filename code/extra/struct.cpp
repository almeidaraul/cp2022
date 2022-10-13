// C++ structs
struct example {
  vector<int> a;
  vector<bool> b = vector<bool>(5); // default value
  int i;
  example(int _i) : a(_i), i(_i) {};
  bool operator< (example& e) { return i < e.i; }
}

example e = example(3);
example f(3);
