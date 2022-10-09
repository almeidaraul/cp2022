// Floyd's algorithm cycle-finding
// Status: not tested
// Source: CPHB (p. 156)

int findCycle(int x) {
	int a, b;
	a = succ(x);
	b = succ(succ(x));
	while (a != b) {
		a = succ(a);
		b = succ(succ(b));
	}
	a = x;
	while (a != b) {
		a = succ(a);
		b = succ(b);
	}
	int first = a; // first element in cycle
	b = succ(a);
	int length = 1;
	while (a != b) {
		b = succ(b);
		length++;
	}
}
