#include "concept.hpp"

using namespace std;

namespace Animal {
		Mammal::Mammal(string name, int age) : name(name), age(age) {}

		void Mammal::speak() const {
				cout << "Name : " << name << "\n";
				cout << "Age : " << age << "\n";
		}

		Mammal::~Mammal() {
				cout << "Destroyed " << name << "(" << age << ")\n";
		}

		Dog::Dog(string name, int age) : Mammal(name, age) {
				this->name = name;
				this->age = age;
		}

		void Dog::speak() const {
				cout << name << "(" << age << ")" << " : dogdog!\n";
		}

		Dog::~Dog() {
				cout << "Destroyed the dog : " << name << "(" << age << ")\n";
		}

		Cat::Cat(string name, int age) : Mammal(name, age) {
				Cat::name = name;
				Cat::age = age;
		}

		void Cat::speak() const {
				cout << name << "(" << age << ")" << " : catcat!\n";
		}

		void Cat::jump(int height) const {
				cout << "high : " << height << "\n";
		}

		Cat::~Cat() {
				cout << "Destroyed the cat : " << name << "(" << age << ")\n";
		}
}
