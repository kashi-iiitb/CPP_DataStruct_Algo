#include <iostream>
#include <vector>
#include "IntCell.h"

using namespace std;

int main()
{
	vector<int> squares(100);
	for(int i=0; i<100; i++) {
		squares[i] = i*i;
	}
	for(int i=0; i<100; i++) {
		cout << "square of " << i << "= " << squares[i];
		cout << endl;
	}
}
