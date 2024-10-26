#include <iostream>
using namespace std;

class Animal {
	public:
		int public_var;		//Private variable.
		Animal(int i);
		~Animal();
	private:
		int private_var;	//Private variable.
	protected:
		int protected_var;	//protected variable.

};
Animal::Animal(int i) {
	private_var = i;
	cout << "this is Constructor" << endl;
}
Animal::~Animal() {
	cout << "this is Destructor" << endl;
}

class Poppy : public Animal{
	public:
		Poppy(int i);
};
Poppy::Poppy(int i)  : Animal(i) {
	//private_var = i;
	cout << "bow-wow" << endl;
}

int main() {
	Poppy poppy(0);
	return 0;
}