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
						Mammal(string name, int age); // Constructor
						virtual void speak() const; // 'virtual' for polymorphism
						virtual ~Mammal(); // Destructor
		};

		class Dog : public Mammal { // Inheritance
				public:
						Dog(string name, int age);
						void speak() const override;
						~Dog();
		};

		class Cat : public Mammal {
				private:
						string pattern;
				public:
						Cat(string name, int age);
						void speak() const override;
						void jump(int height) const;
						~Cat();
		};
}

#endif
