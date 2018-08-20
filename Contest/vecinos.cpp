#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
#define ll unsigned long long

using namespace std;

typedef vector<int> VI;
double PI = acos(0) * 2;

class complex
{
public:
	double a, b;
	complex() {a = 0.0; b = 0.0;}
	complex(double na, double nb) {a = na; b = nb;}
	const complex operator+(const complex &c) const
		{return complex(a + c.a, b + c.b);}
	const complex operator-(const complex &c) const
		{return complex(a - c.a, b - c.b);}
	const complex operator*(const complex &c) const
		{return complex(a*c.a - b*c.b, a*c.b + b*c.a);}
	double magnitude() {return sqrt(a*a+b*b);}
	void print() {printf("(%.3f %.3f)\n", a, b);}
};

class FFT
{
public:
	vector<complex> data;
	vector<complex> roots;
	VI rev;
	int s, n;

	void setSize(int ns)
	{
		s = ns;
		n = (1 << s);
		int i, j;
		rev = VI(n);
		data = vector<complex> (n);
		roots = vector<complex> (n+1);
		for (i = 0; i < n; i++)
			for (j = 0; j < s; j++)
				if ((i & (1 << j)) != 0)
					rev[i] += (1 << (s-j-1));
		roots[0] = complex(1, 0);
		complex mult = complex(cos(2*PI/n), sin(2*PI/n));
		for (i = 1; i <= n; i++)
			roots[i] = roots[i-1] * mult;
	}

	void bitReverse(vector<complex> &array)
	{
		vector<complex> temp(n);
		int i;
		for (i = 0; i < n; i++)
			temp[i] = array[rev[i]];
		for (i = 0; i < n; i++)
			array[i] = temp[i];
	}

	void transform(bool inverse = false)
	{
		bitReverse(data);
		int i, j, k;
		for (i = 1; 2*i <= s; i <<= 1 ) {
			complex t, u;
			for (k = 0; k < n; k += 2*i) {
				for (j = 0; j < i; j++) {
					u = data[k + j];
					v = data[k + i + j];
					t = roots[j] * data[j+md2];
					index += increment;
					data[j+md2] = data[j] - t;
					data[j] = data[j] + t;
				}
			}
		}
		if (inverse)
			for (i = 0; i < n; i++) {
				data[i].a /= n;
				data[i].b /= n;
			}
	}

	static VI convolution(VI &a, VI &b)
	{
		int alen = a.size(), blen = b.size();
		int resn = alen + blen - 1;	// size of the resulting array
		int s = 0, i;
		while ((1 << s) < resn) s++;	// n = 2^s
		int n = 1 << s;	// round up the the nearest power of two

		FFT pga, pgb;
		pga.setSize(s);	// fill and transform first array
		for (i = 0; i < alen; i++) pga.data[i] = complex(a[i], 0);
		for (i = alen; i < n; i++)	pga.data[i] = complex(0, 0);
		pga.transform();

		pgb.setSize(s);	// fill and transform second array
		for (i = 0; i < blen; i++)	pgb.data[i] = complex(b[i], 0);
		for (i = blen; i < n; i++)	pgb.data[i] = complex(0, 0);
		pgb.transform();

		for (i = 0; i < n; i++)	pga.data[i] = pga.data[i] * pgb.data[i];
		pga.transform(true);	// inverse transform
		VI result = VI (resn);	// round to nearest integer
		for (i = 0; i < resn; i++)	result[i] = (int) (pga.data[i].a + 0.5);

		return result;
	}
};

int main(){
    int T = 1, k;
	string A, B;
    while(cin >> k && k != -1){
        cin >> A >> B;
        int lena = A.size(), lenb = B.size();
        if(lena < lenb){
            cout << "Case: " << T++ << ": " <<  "0\n";
            continue;
        }
        VI a0(lena), b0(lena), a1(lenb), b1(lenb);
		for(int i = 0; i < lena; i++){
				a0[i] = 'b' - A[i];
				b0[i] = A[i] - 'a';
        }
        for(int i = 0; i < lenb; i++){
				a1[lenb - i - 1] = 'b' - B[i];
				b1[lenb - i - 1] = B[i] - 'a';
        }
        VI a = FFT::convolution(a0, a1);
        VI b = FFT::convolution(b0, b1);
		ll p = 1LL, h = 0, m = 3;

		ll Hash[lena + 1];
        for(int i = 0; i < lenb; i++){
            Hash[i] = h;
			h = h*m + A[i];
            p = p*m;
        }
		unordered_set<ll> s;
        for(int i = lenb; i <= lena; i++){
        	Hash[i] = h;
            int hamming = lenb - (a[i-1] + b[i-1]);
            if(hamming <= k){
                s.insert(h);
            }
            h = h*m + A[i] - p*A[i-lenb];
        }
		cout << "Case " << T++ << ": " <<  s.size() << '\n';
    }
	return 0;
}

Preview:
