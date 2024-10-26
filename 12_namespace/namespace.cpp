#include<iostream>
using namespace std;

namespace {
	// They are not accessible from outside this file
	string staticVar ="test";

    void staticFunction() {
        std::cout << "Hello static Function!" << std::endl;
    }
}

namespace Poppy {
	string cry = "bow-wow";

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
}


int main() {
	cout << staticVar << endl;
	staticFunction();

	cout << Poppy::cry << endl;
	Poppy::Poppy poppy(0);

	return 0;
}