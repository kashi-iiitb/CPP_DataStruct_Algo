/*
This program demonstrates the implementation of "vector"
container for 'int' data type.
*/

#include <iostream>

using namespace std;

class vector{
	int sz;
	int *elem;
public:

	//single argument constructor (n)
	vector(int s) {
		elem = new int[s];
		sz = s;
	}
	//constructor with {2,3,4,5} initializer list
	vector(initializer_list<int> lst) {
		sz = lst.size();
		elem = new int[list.size()];
		copy(lst.begin(),lst.end(),elem);
	}
	//copy constructor
	vector & vector(vector &s) {
		elem = new int[s.size()];
		for(int i=0; i<s.size(); i++) {		//may be we can replace this with
			elem[i] = s.elem[i];			//copy(s.elem,s.elem.sz,elem);
		}
		sz = s.size();
	}
	//assignment operator =
	vector & operator=(vector &s) {
		int *temp;
		temp = new int[s.size()];
		for(int i=0; i<s.size(); i++) {		//may be we can replace this with
			temp[i] = s.elem[i];			//copy(s.elem,s.elem.sz,elem);
		}
		delete[] elem;
		sz = 0;
		elem = temp;
		sz = s.size();
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
		
}
