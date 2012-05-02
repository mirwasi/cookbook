//Uses Point, Line
#define det(a,b,c,d)  (a*d-b*c)

inline bool betw(Double l, Double r, Double x) {
	return in(min(l, r), x, max(l, r));
}

inline bool intersect_1d(Double a, Double b, Double c, Double d) {
	if (a > b) swap(a, b); if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}

bool seg_seg_intersect(Point<Double> a, Point<Double> b, Point<Double> c,
		Point<Double> d, Point<Double> & left, Point<Double> & right) {
	if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
		return false;
	Line m(a, b); Line n(c, d);
	Double zn = det ( m. a , m. b , n. a , n. b );
	if (abs ( zn ) == Double(0)) {
		if (abs(m.dist(c)) || abs(n.dist(a))) return false;
		if (b < a) swap(a, b); if (d < c) swap(c, d);
		left = max(a, c); right = min(b, d);
		return true;
	} else {
		left.x = right.x = -det ( m. c , m. b , n. c , n. b ) / zn;
		left.y = right.y = -det ( m. a , m. c , n. a , n. c ) / zn;
		return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y)
				&& betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
	}
}
