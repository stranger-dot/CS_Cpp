#include <iostream>

using namespace std;

int main() {
		int A, B, m;

		cin >> A >> B >> m;

		int re = A % m;

		// Always has values between 0 ~ m
		if (re < 0)
				re += m;

		cout << (A + B) % m << " " << ((A % m) + (B % m)) % m;
		cout << (A - B) % m << " " << ((A % m) - (B % m)) % m;
		cout << (A * B) % m << " " << ((A % m) * (B % m)) % m;

		return 0;
}
