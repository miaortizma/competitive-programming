#include<bits/stdc++.h>
#define ll long long
#define cmplx complex<double>
using namespace std;

typedef vector<int> VI;
typedef vector<cmplx> VC;
const double PI = acos(0) * 2;

//based and modified from http://web.mit.edu/~ecprice/acm/acm08/notebook.html#file12
class FFT
{
public:

    VC temp;
    VC roots;
	int s = 0, n;

    void setS(int ns){
        if(ns > s){
            n = 1 << ns;
            temp = VC (n);
            roots = VC (n+1);
            //n-th root of unity
            roots[0] = cmplx(1, 0);
            cmplx mult = cmplx(cos(2*PI/n), sin(2*PI/n));
            //1<<s last value that was calculated
            for (int i = 1<<s; i <= n; i++){
                roots[i] = roots[i-1] * mult;
            }
        }
        s = ns;
    }

    FFT(int ns){
        s = 0;
        setS(ns);
    }

    int reverse_bits(int x){
        int ans = 0;
        for(int i = 0; i < s; i++){
            if(x & (1<<i) != 0){
                ans += (1 << (s-i-1));
            }
        }
        return ans;
    }

    void permute(vector<cmplx> &data){
        int i;
        for (i = 0; i < n; i++){
            temp[i] = data[reverse_bits(i)];
        }
		for (i = 0; i < n; i++){
            data[i] = temp[i];
        }
    }

	void transform(VC &data, bool inverse){
        permute(data);
		int i, j, k;
		for (i = 1; 2*i <= s; i <<= 1) {
			cmplx u, v;
			for (k = 0; k < n; k += 2*i) {
				for (j = 0; j < i; j++) {
                    u = data[k + j];
                    v = roots[j] * data[i + k + j];
                    data[k+j] = u + v;
					data[i+k+j] = u - v;
				}
			}
		}
		if (inverse)
			for (i = 0; i < n; i++) {
				data[i] = cmplx(data[i].real()/n, data[i].imag()/n);
			}
	}

};

FFT fft(19);

VI convolution(VC &a, VC &b){
    int resn = a.size() + b.size() - 1;	// size of the resulting array
    int s = 0, i;
    while ((1 << s) < resn) s++;	// n = 2^s
    int n = 1 << s;	// round up the the nearest power of
    fft.setS(s);
    fft.transform(a, false);
    fft.transform(b, false);
    for (i = 0; i < n; i++)	a[i] = a[i] * b[i];
    fft.transform(a, true);	// inverse
    VI result = VI (resn);	// round to nearest integer
    for (i = 0; i < resn; i++)	result[i] = (int) (a[i].real() + 0.5);
    return result;
}

int k;
int lena, lenb;

int main(){
    int T, n, temp;
    cin >> T;
    while(T--){
        cin >> n;
        VC a(n+1), b(n+1);
        for(int i = 0; i < n; i++){
            cin >> temp;
            a[i] = cmplx(temp, 0);
        }
        for(int i = 0; i < n; i++){
            cin >> temp;
            b[i] = cmplx(temp, 0);
        }
        VI ans = convolution(a, b);
        for(int i = 0; i < 2*n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
