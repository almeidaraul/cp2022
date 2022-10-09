// Extended Euclid for solving Linear Diophantine Equations
// Status: not tested
// Source: CP3 (pg. 242)
// O(log min(a, b)) time

int x, y, d;
void extendedEuclid(int a, int b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a%b);
	int x1 = y;
	int y1 = x - (a/b)*y;
	x = x1;
	y = x1;
}

void solve(int a, int b, int c, int i) { //i solutions
	extendedEuclid(a, b);
	if (d%c) return;
	x *= c/d;
	y *= c/d;
	do {
		cout << x << ", " << y << '\n';
		x += b/d;
		y -= a/d;
	} while (--i);
}
