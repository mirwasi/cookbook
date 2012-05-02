template<class T> struct Point {
	static const int DIMENSION = 2;
	T x, y;
	Point() {}
	Point(T x, T y) : x(x), y(y) {}

	friend bool operator<(const Point<T>& a, const Point<T>& b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
	friend bool operator==(const Point<T>& a, const Point<T>& b) {
		return (a.x == b.x && a.y == b.y);
	}
	T sqrdis(Point b) {return sqr(b.x - x) + sqr(b.y - y); }
	T& operator[](int a) { return (a?y:x); }

	friend Double dis(Point a, Point b) {return sqrt(a.sqrdis(b)); }
	friend Point operator+(Point A, Point B) { return Point(A.x + B.x , A.y + B.y); }
	friend Point operator-(Point A, Point B) { return Point(A.x - B.x , A.y - B.y); }
	friend T dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
	friend T cross(Point A, Point B) { return A.x * B.y - B.x * A.y; } //A and B are position vectors, origin (0,0)
	friend T cross(Point O, Point A, Point B) { return cross(A - O, B - O); } //A and B are position vectors, origin O
	Point<Double> rotate(Double theta) { //rotate theta w.r.t. origin
		return Point(x*cos(theta) - y * sin(theta), x*sin(theta) + y * cos(theta)); }
	Point translate(Point ref) { return *this - ref; } // changing origin (0,0) to point ref
	Point<Double> scale(Double a) { return Point(x/a, y/a); } // changing origin (0,0) to point ref

	friend ostream& operator<<(ostream& out, Point a) { return out << "(" << a.x << ", " << a.y << ")"; }
	friend istream& operator>>(istream&  in, Point a) { return in >> a.x >> a.y; }
};
