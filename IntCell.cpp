#include <iostream>
using namespace std;

class IntCell {
	public:
	IntCell() {
		storedValue = 0;
	}
	IntCell(int initialValue) :storedValue(initialValue) { }
	int read() const {
		return storedValue;
	}
	int write(int x) {
		storedValue = x;
	}

	private:
		int storedValue;
};

