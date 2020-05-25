#include <iostream>
#include <stack>

using namespace std;


int enqueue(stack<int> &s1, stack<int> &s2, int data) {
	int temp=0;
	while(!s1.empty()) {
		temp = s1.top();
		s1.pop();
		s2.push(temp);
	}
	s1.push(data);
	while(!s2.empty()) {
		temp = s2.top();
		s2.pop();
		s1.push(temp);
	}
	return 0;
}

int dequeue(stack<int> &s1, stack<int> &s2, int &num) {
	if(!s1.empty()) {
		num = s1.top();
		s1.pop();
		return 0;
	}
	else {
		cout << "queue is empty" << endl;
		return -1;
	}
}

int main()
{
	stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);

	cout << "Contents of the stack are" << endl;
	while(!s1.empty()) {
		cout << s1.top() << endl; 
		s1.pop();
	}

	stack<int> s2,s3;
	int num=0;
	enqueue(s2,s3,10);
	enqueue(s2,s3,20);
	enqueue(s2,s3,30);
	enqueue(s2,s3,40);
	enqueue(s2,s3,50);
	cout << dequeue(s2,s3,num) << num <<endl;
	cout << dequeue(s2,s3,num) << num <<endl;
	cout << dequeue(s2,s3,num) << num <<endl;
	cout << dequeue(s2,s3,num) << num <<endl;
	cout << dequeue(s2,s3,num) << num <<endl;
	cout << dequeue(s2,s3,num) << num <<endl;
	return 0;
}
