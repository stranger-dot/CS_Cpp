#ifndef CONCEPT_HPP
#define CONCEPT_HPP

#include <string>
#include <iostream>

using namespace std;

namespace Animal {
		class Mammal {
				protected:
						string name;
						int age;
				public:
						Mammal(string name, int age);
						virtual void speak() const; // virtual for polymorphism
						virtual ~Mammal();
		};

		class Dog : public Mammal {
				public:
						Dog(string name, int age);
						void speak() const override;
						~Dog();
		};
}

#endif
