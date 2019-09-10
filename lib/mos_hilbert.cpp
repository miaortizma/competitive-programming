// Even faster when number of queries is smaller to N
constexpr int logn = 20;
constexpr int maxn = 1 << logn;

long long hilbertOrder(int x, int y)
{
	long long d = 0;
	for (int s = 1 << (logn - 1); s; s >>= 1)
	{
		bool rx = x & s, ry = y & s;
		d = d << 2 | rx * 3 ^ static_cast<int>(ry);
		if (!ry)
		{
			if (rx)
			{
				x = maxn - x;
				y = maxn - y;
			}
			swap(x, y);
		}
	}
	return d;
}

struct Query {
	int l, r, idx;
	int64_t ord;

	inline void calcOrder() {
		ord = hilbertOrder(l, r);
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}
