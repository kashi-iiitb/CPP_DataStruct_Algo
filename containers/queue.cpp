#include <iostream>
#include <queue>
using namespace std;

int push(queue<int> &q1, queue<int> &q2, int data) {
	int temp=0;
	if(q1.empty()) {
		q1.push(data);
		while(!q2.empty()) {
			temp = q2.front();
			q2.pop();
			q1.push(temp);
		}
	}
	else {
		q2.push(data);
		while(!q1.empty()) {
			temp = q1.front();
			q1.pop();
			q2.push(temp);
		}
	}
	return 0;
}

int pop(queue<int> &q1, queue<int> &q2, int &data) {
	if(!q1.empty()) {
		data = q1.front();
		q1.pop();
	}
	else if(!q2.empty()) {
		data = q2.front();
		q2.pop();
		}
		else {
			cout << "stack is empty" << endl;
			return -1;
		}
	return 0;			
}

/*int display(queue<int> &q1, queue<int> &q2) {
	
	if(q1.empty()) {
		while(!q2.empty()) {
			temp = q2.front();
			q2.pop();
		}
	}
	else {
}*/

int main() {

	queue<int> q1;
	queue<int> q2;
	int data=0;

	push(q1,q2,10);
	push(q1,q2,20);
	push(q1,q2,30);
	push(q1,q2,40);
//	display(q1,q2);
	while(!pop(q1,q2,data)) { 
		cout << data << endl;
	}
}
