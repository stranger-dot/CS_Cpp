#include <iostream>
#include <string>
#include "concept.hpp"

using namespace std;
using namespace Animal;

int main() {
		string name;
		int age;

		getline(cin, name);
		cin >> age;

		Dog *d = new Dog(name, age);
		d->speak();

		Mammal *m = d;
		m->speak();

		delete d;

		Mammal *ms[3];

		ms[0] = new Dog("alpha", 5);
		ms[1] = new Dog("Beta", 3);
		ms[2] = new Dog("Chalie", 8);

		for (int i = 0; i < 3; i++) {
				ms[i]->speak();
				delete ms[i];
		}

		return 0;
}
