struct Double {
        double d;
        Double() {}
        Double(double d) : d(d) {}
        operator double() const { return d; }
 
        friend bool operator==(Double a, Double b) { return abs(a-b) <= EPS; }
        friend bool operator==(Double a, double b) { return a == Double(b); }
        friend bool operator<(Double a, Double b) { return a.d + EPS < b.d; }
    	friend bool operator<=(Double a, Double b) { return (a == b) || (a < b); }
    	friend bool operator>=(Double a, Double b) { return (a == b) || (a > b); }
 
        //All the following functions are helpers, all are optional. You can omit them if you like.
        Double floor() { double inpart; modf(d, &inpart); return inpart; }
        Double ceil() { double inpart; Double fpart = modf(d, &inpart); if(fpart == 0.0) inpart++; return inpart; }
        Double round() { return Double(d+0.5).floor(); } //round needs floor function
 
        friend Double max(Double a, double b) { return max(a, Double(b)); }
        friend Double min(Double a, double b) { return max(a, Double(b)); }

        //input functions
        int scan() { return scanf("%lf", &d); }
        int print() { return printf("%lf", d); }
 
        friend ostream& operator<<(ostream& out, Double& d) { return out << d.d; }
        friend istream& operator>>(istream&  in, Double& d) { return  in >> d.d; }
};
