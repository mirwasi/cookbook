struct FlowDinic
{
    int n, m, s, t, head, tail, ne;
    #define data int // change int -> LL if needed
    data data_inf;
    int *to, *next, *last, *d, *q, *now, *flow;
    data *cap;
    FlowDinic() {}
    FlowDinic(int xn, int xm) // INITIALIZE WITH THIS
    {
        n = xn+10; m = xm+10; ne = 0;
        to = new int[m]; cap = new data[m]; next = new int[m], flow = new int[m];
        d = new int[n]; q = new int[n+n]; now = new int[n]; last = new int[n];
        fill(last, last+n, -1);
    }
    void clear() { ne = 0; fill(last, last+n, -1); }
    inline void add_edge(int u, int v, data uv, data vu = 0)
    {
        to[ne] = v; cap[ne] = uv; next[ne] = last[u]; flow[ne] = 0; last[u] = ne++;
        to[ne] = u; cap[ne] = uv; next[ne] = last[v]; flow[ne] = 0; last[v] = ne++;
    }
    inline bool bfs()
    {
        fill(d, d+n, -1);
        head = tail = 0;
        d[t] = 0;
        q[tail++] = t;
        int u, v, e;
        while (head < tail)
        {
            u = q[head++];
            
            for (e = last[u]; e != -1; e = next[e])
            {
                v = to[e];
                if (cap[e^1] > flow[e^1] && d[v] == -1)
                {
                    q[tail++] = v;
                    d[v] = d[u] + 1;
                }
            }

        }
        return d[s] != -1;
    }
    data dfs(int u, data f)
    {
        if (u == t) return f;
        int v;
        data ret;
        for (int &e = now[u]; e != -1; e = next[e])
        {
            v = to[e];
            if (cap[e] > flow[e] && d[u] == d[v] + 1)
            {
                ret = dfs(v, min(f, cap[e] - flow[e]));
                if (ret > 0)
                {
                    flow[e^1] -= ret;
                    flow[e] += ret;
                    return ret;
                }

            }
        }
        return 0;
    }
    data maxflow(int source, int sink)
    {
        s = source; t = sink;
        data f = 0, x;
        data_inf = numeric_limits<data>::max();
        ms(flow,0);
        while (bfs())
        {
            rep(i,n) now[i] = last[i];
            while (true)
            {
                x = dfs(s, data_inf);
                if (x == 0) break;
                f = f + x;
            }
        }
        return f;
    }
} G;

