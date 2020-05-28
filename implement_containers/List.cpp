/**
In this sample program we have explicitly use 'this' pointer.
This is to demonstrate the utiility of 'this'.
To access a member, we can drop use of 'this'.
e.g. if(this->prev) is equal to if(prev) 
**/

#include <iostream>
#include <string>

using namespace std;

class Link{
private:
public:
	Link * prev;
	Link * succ;
	string value;
	Link(const string & value, Link *p=nullptr, Link *s=nullptr):
	value(value),prev(p),succ(s) {
	}

	Link * insert(Link* n) { //add before 'this' Link 
		if(n==nullptr) return nullptr;
		n->succ = this;
		if(this->prev) {
			n->prev = this->prev;
			n->prev->succ = n;
		}
		this->prev = n;
		return n;
	}

	Link * add(Link* n) { //add after 'this' Link
		if(n==nullptr) 
			return nullptr;
		if(this) { 
			n->succ = this->succ;
			if(this->succ)
				this->succ->prev = n;
			this->succ = n;
		}
		n->prev = this;
		return n;
	}

	Link * find(const string & value) { //Find the Link with given value
		Link *temp = this;
		while(temp) {
			if(temp->value == value) return temp;
			temp = temp->succ;
		}
		if(temp == nullptr)
			return nullptr;
	}

	Link * erase() {	//delete the current Link
		if(!this->prev) return this->succ;
		if(!this->succ) return this->prev;
		this->prev->succ = this->succ;
		this->succ->prev = this->prev;
		return this->succ;
	}

	Link * advance(int n) { //advance the poiter by n positions
		Link *temp = this;
		if(n>0) 	
			while(temp) {
				n--;
				temp = temp->succ;
			}
		else if(n<0)
				while(temp) {
					n++;
					temp = temp->prev;
				}
		if(temp) 
			return temp;
		else
			return nullptr;
	
	}
};

	int print_all(Link *p) {
		while(p) {
			cout << p->value << "," ;
			p = p->succ;
		}
		cout << endl;
		return 0;
	}
int main() {
	cout << "List " << endl;
	Link * norse_gods = new Link{"Thor"};
	norse_gods = norse_gods->insert(new Link{"Odin"});	
	norse_gods = norse_gods->insert(new Link{"Zeus"});	
	norse_gods = norse_gods->insert(new Link{"Freia"});

	Link * greek_gods = new Link{"Hera"};
	greek_gods = greek_gods->insert(new Link{"Athena"});	
	greek_gods = greek_gods->insert(new Link{"Mars"});
	greek_gods = greek_gods->insert(new Link{"Poseidon"});	

	print_all(norse_gods);
	print_all(greek_gods);

	Link *p1 = greek_gods->find("Mars");
	if(p1)
		p1->value = "Ares";

	Link *p = norse_gods->find("Zeus");
	if(p) {
		if(p == norse_gods) norse_gods = p->succ;
		p->erase();
		greek_gods = greek_gods->insert(p);
	}
	
	print_all(norse_gods);
	print_all(greek_gods);
	return 0;
}
