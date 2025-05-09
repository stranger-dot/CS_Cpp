#include <iostream>

#define MOD 1e9+7

using namespace std;

/* Modular Inverse
 * m must be a prime number
 * a % m != 0
 * 
 * a^(m - 1) ≡ 1 (mod m)
 * a^(m - 2) ≡ a^(-1) (mod m)
 * Inverse a = a^(m - 2) (mod m)
 */

long long modpow(long long a, long long b, int mod = MOD) {
		long long res = 1;
		
		a %= mod;

		while (b > 0) {
				if (b % 2 == 1) 
						res = (res * a) % mod;

				a = (a * a) % mod;
				b /= 2;
		}

		return res;
}

int main() {
		int A, B, m;

		cin >> A >> B >> m;

		int re = A % m;

		// Always has values between 0 ~ m
		if (re < 0)
				re += m;

		cout << (A + B) % m << " " << ((A % m) + (B % m)) % m << "\n";
		cout << (A - B) % m << " " << ((A % m) - (B % m)) % m << "\n";
		cout << (A * B) % m << " " << ((A % m) * (B % m)) % m << "\n";
		cout << "Mod Inverse " << modpow(A, MOD - 2, MOD) << "\n";

		return 0;
}
