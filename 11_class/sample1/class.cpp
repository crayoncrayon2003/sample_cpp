#include <iostream>
using namespace std;

class Poppy {
	public:
		int public_var;		//Private variable.
		Poppy(int i);
		~Poppy();
	private:
		int private_var;	//Private variable.
	protected:
		int protected_var;	//protected variable.

};
Poppy::Poppy(int i) {
	private_var = i;
	cout << "this is Constructor" << endl;
}
Poppy::~Poppy() {
	cout << "this is Destructor" << endl;
}

class Kitty {
	public:
		Kitty(int i){
			private_var = i;
			cout << "this is Constructor" << endl;
    	}
		~Kitty(){
			cout << "this is Destructor" << endl;
		}
		int public_var;		//Private variable.
	private:
		int private_var;	//Private variable.
	protected:
		int protected_var;	//protected variable.

};

int main() {
	Kitty kitty(0);
	kitty.public_var++;

	Poppy poppy(0);
	poppy.public_var++;
	return 0;
}