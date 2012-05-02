struct UnionFind
{
	#define MAXUF 100000 + 10
	int p[MAXUF], rank[MAXUF];

	int set_find(int x)
	{
		if(p[x] != x) p[x] = set_find(p[x]);
		return p[x];
	}

	void set_union(int x, int y)
	{
		int rx = set_find(x), ry = set_find(y);
		if(rx == ry) return;
		if(rank[rx] > rank[ry]) { p[ry] = rx; rank[rx] += rank[ry]; }
		if(rank[rx] <= rank[ry]) { p[rx] = ry; rank[ry] += rank[rx]; }
	}
};

int main()
{
}
