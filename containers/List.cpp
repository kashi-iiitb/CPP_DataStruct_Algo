/*
This program will demonstrate the use of lists using
a problem to merge 2 sorted lists into 1 list
*/

#include <iostream>
#include <list>
//#include <>
using namespace std;

int merge_lists(list<int> & l1, list<int> & l2, list<int> & new_list) {
	list<int>::iterator itr1 = l1.begin();
	list<int>::iterator itr2 = l2.begin();
	while(itr1 != l1.end() && itr2 != l2.end()) {
		if(*itr1 < *itr2) {
			new_list.push_back(*itr1);
			itr1++;
		}
		else {
			new_list.push_back(*itr2);
			itr2++;
		}
	}
	while(itr1 != l1.end()) {
		new_list.push_back(*itr1);
		itr1++;
	}
	while(itr2 != l2.end()) {
		new_list.push_back(*itr2);
		itr2++;
	}
	return 0;
}

int main() {
	list<int> new_list;

	list<int> l1 = {10,20,30,40,45};
	list<int> l2 = {15, 17, 25, 28,50};

	merge_lists(l1,l2,new_list);

	for(int & itr: new_list)
		cout << itr << " " ;
}
