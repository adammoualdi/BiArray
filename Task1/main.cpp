#include <iostream>
#include "BiArray.h"
using namespace std;

int main() {

	BiArray a; // zero con
	cout << a.printAll() << endl;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_front(5);
	// a.push_front(6);
	// a.push_front(7);
	// a.push_front(8);
	// a.push_front(9);
	// a.push_front(10);
	// cout << a[3] << endl;
	// cout << a.print() << endl;
	// int v=-1;
	// a.get(3,v);
	// cout << v << endl;
	cout << a.printAll() << endl;
	int arr[10]{10,9,8,7,6,5,1,2,3,4};
	BiArray b{arr,10}; // value con
	string output = b.printAll();
	cout << "output: " << output << endl;
	// b.push_front(10);
	// int ar[7]{0,1 ,2, 3, 4, 5,6};
	// BiArray z{ar,7};
	BiArray z;
	z.push_back(0);
	z.push_back(1);
	z.push_back(2);
	cout << z.printAll() << endl;
	z.push_back(3);
	z.push_back(4);
	cout << z.printAll() << endl;
	z.push_back(5);
	z.push_back(6);
	cout << z.printAll() << endl;
	z.pop_back();
		cout << z.printAll() << endl;
	z.pop_back();
		cout << z.printAll() << endl;
	z.pop_back();
	cout << z.printAll() << endl;
	z.pop_back();
	cout << z.printAll() << endl;
	z.pop_back();
	cout << z.printAll() << endl;
	z.pop_back();
	cout << z.printAll() <<endl;
	// cout << "GET START BEFORE POP " << b.getStart() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b.pop_front();
	// cout << b.printAll() << endl;
	// cout << "pop front " << b.printAll() << endl;
	// b.push_back(5);
	// b.push_back(6);
	// b.push_back(7);
	// b.push_back(8);
	// b.push_back(9);
	// b.push_back(100);
	// b.push_back(4);
	// b.push_back(6);
	// cout << "b pushed back" << endl;
	// cout << b.print() << endl;
	// cout << b.printAll() << endl;

	// b.pop_front();
	// cout << b.printAll() << endl;
	// cout << b.getStart() << endl;
	// // cout << "a==b? " << (a==b) << endl;
	// b.push_back(2);
	// b.push_back(9);
	// b.push_back(10);
	// cout << b.printAll() << endl;
	// BiArray bb = b; // copy con
	// cout << bb.print() << endl;
	// b.pop_front();
	// b.pop_front();
	// b.pop_front();
	// b.pop_front();
	// cout << b.printAll() << endl;
	// b[3] = 77;
	// b.set(4,66);
	// cout << b.print() << endl;
	// cout << "a==b? " << (a==b) << endl;
	// a.pop_front();
	// a.pop_front();
	// a.pop_front();
	// a.pop_front();
	// cout << "a" <<a.printAll() << endl;
	// BiArray c;
	// c = std::move(b); // move asg
	// cout << c.print() << endl;

	// a.pop_back();
	// cout << a.print() << endl;
	// a.pop_front();
	// cout << a.print() << endl;
	// cout << a.getSize() << endl;
	// cout << a.getCapacity() << endl;

}
