// Binary Search (but beautiful)
// binary steps
//
// Time: O(log N)
// Status: not tested
// Source: CPHB

// std
int l = 0, r = n-1;
while (l <= r) {
	int m = l+(r-l)/2;
	if (array[m] == x)
		// found
	if (array[m] > x) r = m-1;
	else l = m+1;
}

// nice
int k = 0;
for (int b = n/2; b > 0; b /= 2)
	while (k+b < n && array[k+b] <= x)
		k += b;
if (array[k] == x)
	// found
