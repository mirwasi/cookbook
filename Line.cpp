//Uses Point
struct Line {
	Double a, b, c;

	Line() {}
	Line(Point<Double> p, Point<Double> q) {
		a = p.y - q.y; b = q.x - p.x;
		c = -a * p.x - b * p.y; norm();
	}

	void norm() {
		Double z = sqrt(a * a + b * b);
		if (z) a = a/z, b = b/z, c = c/z;
	}

	Double dist(Point<Double> p) const {
		return a * p.x + b * p.y + c;
	}
};
