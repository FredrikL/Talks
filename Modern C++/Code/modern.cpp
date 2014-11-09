#include <iostream>

using namespace std;

//clang++  -std=c++1y  -stdlib=libc++ modern.cpp -o modern

class Gadget {
public:
	Gadget() {
		cout << "Gadget" << endl;
	}
	~Gadget() {
		cout << "~Gadget" << endl;
	}
};

class Widget {
public:
	Widget() {
		cout << "Widget" << endl;
	}
	~Widget() {
		cout << "~Widget" << endl;
	}
};

auto factory(){
	return make_unique<Widget>();
};

void use(Widget& w, Gadget& g) {
	cout << "use" << endl;
}

auto loop() {
	auto vec = {1,2,3,4,5};

	for(auto e : vec) {
		cout << e << endl;
	}
}

template <typename Type>
Type max(Type a, Type b) {
    return a > b ? a : b;
}

int main() {
	{
		auto w = factory();
		auto g = make_unique<Gadget>();
		use(*w, *g);
	}

	cout << ::max(2,10) << endl;

	auto a = [] { cout << "Hey" << endl;};
	([] () -> void { cout << "Hey" << endl;})();
	a();


	auto f = [](auto x, auto y) { return x + y; };

	cout << f(1,2) << endl;
	cout << f(4.5,2) << endl;
	cout << f(std::string("foo"), std::string("bar")) << endl;

	auto g = [&] {
		cout << f(2,3) << endl;
	};

	g();

	loop();

	return 0;
}
