/*
This program demonstrates the implementation of "vector"
container for 'int' data type.
*/

#include <iostream>

using namespace std;

class vector{
private:
	int sz;
	int *elem;
	int space;
public:

	//Default constructor
	vector() :sz{0},elem{nullptr},space{0}{}

	//single argument constructor (n)
	vector(int s) {
		elem = new int[s];
		sz = s;
	}
	//constructor with {2,3,4,5} initializer list
	vector(initializer_list<int> lst) {
		sz = lst.size();
		elem = new int[lst.size()];
		copy(lst.begin(),lst.end(),elem);
	}
	//copy constructor
	vector(vector &s) {
		elem = new int[s.sz];
		for(int i=0; i<s.sz; i++) {		//may be we can replace this with
			elem[i] = s.elem[i];			//copy(s.elem,s.elem.sz,elem);
		}
		sz = s.sz;
	}
	//assignment operator =
	vector & operator=(vector &s) {
		if(this == &s) return *this;
	
		if(s.sz <= sz) {
			for(int i=0; i<s.sz; i++)
				elem[i] = s.elem[i];
			sz = s.sz;
			return *this;
		}
		int *temp;
		temp = new int[s.sz];
		for(int i=0; i<s.sz; i++) {		//may be we can replace this with
			temp[i] = s.elem[i];			//copy(s.elem,s.elem.sz,elem);
		}
		delete[] elem;
		sz = 0;
		elem = temp;
		space = sz = s.sz;
		return *this;
	}

	//access operator []
	int & operator[](int index) {
		return elem[index];
	}

	//the above implementation can't be called for 'const'
	//it is a const, so need to return by value and not reference
	int operator[](int index) const {
		return elem[index];
	}
		
	void reserve(int newalloc) {
		if(newalloc<=space) return;
		int *temp = new int[newalloc];
		for(int i=0; i<sz; i++)
			temp[i]=elem[i];
		delete[]elem;
		elem = temp;
		space = newalloc;
	}

	int capacity() { return space;}

	//given the implementation of reserve(), implementation of resize() becomes
	//fairly easy.
	void resize(int newsize) {
		reserve(newsize);
		for(int i=sz; i<newsize; i++)
			elem[i]=0;
		sz = newsize;
	}	
		
	void push_back(int data) {
		if(sz==0)
			reserve(8);
		else if(sz == capacity())
				reserve(2*space);
		elem[sz++] = data;
	}
	~vector() {
		delete[] elem;
	}
};

int main(){

	vector v(10);
	for(int i=0; i<10; i++)
		v[i] = i*10;
	for(int i=0; i<10; i++)
		cout << v[i] << endl;
	vector v2 = v;
	for(int i=0; i<10; i++)
		cout << v2[i] << endl;
	return 0;
}
