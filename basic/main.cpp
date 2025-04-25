#include <iostream>
#include <string>
#include "concept.hpp"

using namespace std;
using namespace Animal;

void example1() {
		string name;
		int age;

		getline(cin, name);
		cin >> age;

		Dog *d = new Dog(name, age);
		d->speak();

		Mammal *m = d;
		m->speak();

		delete d;

		return ;
}

void example2() {
		Mammal *ms[3];

		ms[0] = new Dog("alpha", 5);
		ms[1] = new Dog("Beta", 3);
		ms[2] = new Dog("Chalie", 8);

		for (int i = 0; i < 3; i++) {
				ms[i]->speak();
				delete ms[i];
		}

		return ;
}

void example3() {
		string name;
		int age;

		getline(cin, name);
		cin >> age;

		Cat *c = new Cat(name, age);
		c->speak();

		try {
				int height;
				
				cin >> height;
				
				if (height > 100)
						throw "Write under 100";

				c->jump(height);
		} catch (const char *msg) {
				cerr << "Caught Exception : " << msg << "\n";
		}

		delete c;

		return ;
}

int main() {
		auto welcome = []() {
				cout << "Welcome! User!\n";
		};

		welcome();

		int num;

		cin >> num;
		cin.ignore(); // Clear input buffer

		switch (num) {
				case 1:
						example1();
						break;
				case 2:
						example2();
						break;
				case 3:
						example3();
						break;
				default:
						cout << "Wrong Number\n";
						break;
		}

		return 0;
}
