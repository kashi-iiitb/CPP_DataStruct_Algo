/*This program demonstrates the use of vector 
and to sort and search for an element. 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sort(vector<int> & arr) {

	int maxIndex=0;
	int temp=0;
	int i=0,j=0;
	for(i=0; i<arr.size(); i++) {
		maxIndex=0;
		for(j=0; j<arr.size()-i; j++) {
			if(arr[j]>arr[maxIndex])
				maxIndex = j;
		}
		if(j>0) {
			temp = arr[j-1];
			arr[j-1] = arr[maxIndex];
			arr[maxIndex]=temp;
		}
	}
	return 0;
}

int main() {
	vector<int> vect;

	for(int i=0; i<100; i++) {
		vect.push_back(rand()%100);
	}

	vect.push_back(1500);
	sort(vect);

	for(int i=0; i<vect.size(); i++) {
		cout << vect[i] << " ";
	}

	cout << endl;
	for(int var: vect) {
		cout << var << " ";
	}
	cout << endl;
	if((find(vect.begin(),vect.end(),55)) == vect.end())
		cout << "55 not present in vector" << endl;
	else
		cout << "55 is present in vector" << endl;

	return 0;
}
