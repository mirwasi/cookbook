template<class T> vector< Point<T> > convexHull(const set< Point<T> >& P) {
	int n = P.size(), k = 0;
	vector < Point<T> > H(2 * n);
	DIM(lit, P.begin());
	for (int i = 0; i < n; i++, lit++) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], *lit) <= 0) k--;
		H[k++] = *lit;
	}
	DIM(uit, P.end());
	uit -= 2;
	for (int i = n - 2, t = k + 1; i >= 0; i--, uit--) {
		while (k >= t && cross(H[k - 2], H[k - 1], *uit) <= 0) k--;
		H[k++] = *uit;
	}
	H.resize(k);
	return H;
}