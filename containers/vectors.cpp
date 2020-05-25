#include <iostream>
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
	vector<int> vect(100);

	for(int i=0; i<100; i++) {
		vect[i] = rand()%100;
	}

	sort(vect);

	for(int i=0; i<100; i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
	return 0;
}
