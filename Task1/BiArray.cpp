#include "BiArray.h"
#include <iostream>
using namespace std;

BiArray::BiArray() {
	size_ = 0;
	capacity_ = INITIALCAP;
	biArray_ = new int[capacity_];
	// Set start_ value to middle of capacity_
	start_ = INITIALCAP/2;
}

// value constructor
BiArray::BiArray(int arr[], int size)  {
	size_ = size;
	// set capacity to INITIALCAP if size gets too small
	if (LO_THRESHOLD*size > INITIALCAP) {
		capacity_ = LO_THRESHOLD*size;
	}
	else {
		capacity_ = INITIALCAP;
	}

	// create new array with its new capacity; therefore a new start position may be needed.
	biArray_ = new int[capacity_];
	start_ = capacity_/2;
	int ii = 0;
	for (int i = start_; i < (start_ + size_); i++) {
		biArray_[i] = arr[ii];
		ii++;
	}
}

BiArray::~BiArray() {
	size_ = 0;
	capacity_ = 0;
	start_ = 0;
	biArray_ = nullptr;
}

// copy constructor
BiArray::BiArray(const BiArray& other) {
	// Copy contents of other to new biArray_
	size_ = other.size_; 
	capacity_ = other.capacity_; 
	start_ = other.start_ ;
	biArray_ = new int[other.capacity_];
	for (int i = 0; i < capacity_; i++) {
		biArray_[i] = other.biArray_[i];
	}
}

// move constructor
BiArray::BiArray(BiArray&& other) {
	// move contents of other to new biArray_
	size_ = other.size_; 
	capacity_ = other.capacity_; 
	start_ = other.start_ ;
	biArray_ = new int[other.capacity_];
	for (int i = 0; i < capacity_; i++) {
		biArray_[i] = other.biArray_[i];
	}
	// this requires deleting other attributes as we no longer need them.
	other.size_ = 0;
	other.capacity_ = 0;
	other.start_ = 0;
	other.biArray_ = nullptr;
}

BiArray& BiArray::operator=(const BiArray& other) {
	// don't copy if already exists.
	if (this != &other) {
		// copy other attributes to new array declared below.
		size_ = other.size_;
		capacity_ = other.capacity_;
		start_ = other.start_;
		biArray_ = new int[other.capacity_];
		for(int i = 0; i < capacity_; i++) {
			biArray_[i] = other.biArray_[i];
		}

	}
	return *this;
}

BiArray& BiArray::operator=(BiArray&& other) {
	if (this != &other) {
		size_ = other.size_;
		capacity_ = other.capacity_;
		start_ = other.start_;
		biArray_ = new int[capacity_];
		for(int i = 0; i < capacity_; i++) {
			biArray_[i] = other.biArray_[i];
		}

		// delete other attributes as not needed
		other.size_ = 0;
		other.capacity_ = 0;
		other.start_ = 0;
		other.biArray_ = nullptr;
	}
	return *this;
}

bool BiArray::get(int i, int& v) const {
	// as biArray_ consists of a whole array of x's with the values in the middle, we must get
	// position i from the start point of the useful information
	int pos = start_ + i;
	// if position smaller than start (therefore i is negative), return false
	if (pos < start_) {
		return false;
	} 
	// if position is larger than the centered array, also return false
	else if (pos >= start_ + size_) {
		return false;
	}
	else {
		// as v is a reference, just set v value to array integer.
		v = biArray_[pos];
	}
	return true;
}

bool BiArray::set(int i, int v) {
	// explained in GET method above
	int pos = start_ + i;
	if (pos < start_) {
		return false;
	} 
	else if (pos >= start_ + size_) {
		return false;
	}
	else {
		// change biArray at set given position to v value
		biArray_[pos] = v;
	}
	return true;
}

int BiArray::operator[](int i) const {
	// set to start values position + whatever index we want from the start value
	return biArray_[i + start_];
}

int& BiArray::operator[](int i) {
	return biArray_[i + start_];
}

void BiArray::push_back(int v) {
	// if we fill the array to the capacity, we must resize.
	if (start_ + size_ >= capacity_ ) {
		// set tmp array to old array values to store data
		int* tmp = biArray_;
		// get new biArray attributes for size, capacity and start point.
		int newCapacity = (size_ * LO_THRESHOLD);
		int newStart = (newCapacity/2) - (size_/2);
		int setStart = newStart;
		biArray_ = new int[newCapacity];
		// move old array values to new array with new start point.
		for (int i = start_; i < (start_ + size_); i++) {
			biArray_[newStart] = tmp[i];
			newStart = newStart + 1;
		}
		// add to back of sub array (newStart has been incremented to final position)
		biArray_[newStart] = v;

		// delete tmp pointer to remove redudant memory.
		tmp = nullptr;
		size_ = size_ + 1;
		capacity_ = newCapacity;
		start_ = setStart;
	}
	else {
		biArray_[start_ + size_] = v;
		size_ = size_ + 1;
	}
}

bool BiArray::pop_back() {
	// check if array is empty 
	if (size_ == 0) {
		return false;
	}

	int newCapacity = 0;
	int newStart = 0;

	// if capacity needs resizing
	// Explained in POP_FRONT
	if (capacity_ > ((size_-1)*HI_THRESHOLD)) {
		if (LO_THRESHOLD*(size_-1) < INITIALCAP) {
			newCapacity = INITIALCAP;
			newStart = (newCapacity/2) - (size_/2) + 1;
		}
		else {
			newCapacity = LO_THRESHOLD*(size_-1);
			newStart = (newCapacity/2) - (size_/2) + 1;
		}	
	}
	else {
		newCapacity = capacity_;
		newStart = start_;
	}
	int setStart = newStart;
	int* tmp = biArray_;
	biArray_ = new int[newCapacity];
	// Loop through old contents and place into new array.
	for (int i = start_; i < start_ + size_-1; i++) {
		biArray_[newStart] = tmp[i];
		newStart = newStart + 1;
	} 

	// delete tmp pointer to remove redudant memory.
	tmp = nullptr;
	size_ = size_ -1;
	capacity_ = newCapacity;
	start_ = setStart;

	return true;
}

void BiArray::push_front(int v) {
	// if needing to make capacity bigger
	if (start_ + size_ >= capacity_ ) {
		// create tmp value to move old values to new array.
		int* tmp = biArray_;
		int newCapacity = (size_ * LO_THRESHOLD);
		int newStart = (newCapacity/2) - (size_/2);
		int setStart = newStart;
		biArray_ = new int[newCapacity];
		biArray_[newStart-1] = v;
		// loop through tmp elements (old array) and place values in new array with a possible new start
		// position and/or new capacity
		for (int i = start_; i < (start_ + size_); i++) {
			biArray_[newStart] = tmp[i];
			newStart = newStart + 1;
		}

		// delete tmp pointer to remove redudant memory.
		tmp = nullptr;
		size_ = size_ + 1;
		capacity_ = newCapacity;
		start_ = setStart;
	}
	// if resizing isn't needed, make start value -1 and set new value 'V' equal to start_ poisition.
	else {
		start_ = start_ -1;
		biArray_[start_] = v;
		size_ = size_ + 1;
	}
}

bool BiArray::pop_front() {
	// check if array is empty 
	if (size_ == 0) {
		return false;
	}
	int newCapacity = 0;
	int newStart = 0;
	// if capacity needs resizing
	if (capacity_ > ((size_-1)*HI_THRESHOLD)) {	
		// check if capacity needs to be set to default INITIALCAP depending on size of subset array.
		if (LO_THRESHOLD*(size_-1) < INITIALCAP) {
			newCapacity = INITIALCAP;
			newStart = (newCapacity/2) - (size_/2) + 1;
		}
		else {
			newCapacity = (LO_THRESHOLD*(size_-1));  
			newStart = (newCapacity/2) - (size_/2) +1;
		}	
	}
	// doesn't need resizing, only change start_.
	else {
		newCapacity = capacity_;
		newStart = start_+1;
	}

	// allows us to increment start variable
	int setStart = newStart;
	int* tmp = biArray_;
	biArray_ = new int[newCapacity];
	// Explained in PUSH_FRONT
	for (int i = start_+1; i < start_+1 + size_; i++) {
		biArray_[newStart] = tmp[i];
		newStart = newStart + 1;
	} 

	// remove tmp from memory
	tmp = nullptr;
	// Set attributes to new values
	size_ = size_ -1;
	capacity_ = newCapacity;
	start_ = setStart;
	return true;
}

int BiArray::getSize() const {
	return size_;
}

int BiArray::getCapacity() const {
	return capacity_;
}

int BiArray::getStart() const {
	return start_;
}

// Only print the main subset of the array e.g. [X,X,X,X,1,2,3,X,X] would only
// print [1,2,3]
string BiArray::print() const {
	string output;
	output = "[";
	for (int i = start_; i < (start_ + size_); i++) {
		// if first element, print number without space.
		if (output == "[") {
			output = output + std::to_string(biArray_[i]);
		}
		// add space to output and number.
		else {
			output = output + " " + std::to_string(biArray_[i]);
		}
	}
	output = output + "]";
	return output;
}

// Print whole array in format [X,X,X,X,1,2,3,X,X] where [1,2,3] is the subset.
string BiArray::printAll() const {
	string output;
	for (int ii = 0; ii < start_; ii++) {
		output = output + " " + "X";
	}
	for (int i = start_; i < size_ + start_; i++) {
		output = output + " " + std::to_string(biArray_[i]);
	}
	for (int iii = start_+size_; iii < capacity_; iii++) {
		output = output + " " + 'X';
	}
	return output;
}

bool operator==(const BiArray& lhs, const BiArray& rhs) {
	int largestStart = 0;
	int largestEnd = 0;
	int smallestStart = 0;
	// find largest array to loop through for comparison.
	if (rhs.size_ > lhs.size_) {
		largestStart = rhs.start_;
		largestEnd = rhs.start_ + rhs.size_;
		smallestStart = lhs.start_;
	}
	else {
		largestStart = lhs.start_;
		largestEnd = lhs.start_ + lhs.size_;
		smallestStart = rhs.start_;
	}
	// start_ is different dependant for each array dependant on the capacity of the arrays.
	// therefore must set smallestStart and largestStart to their respective starts.
	for (int i = largestStart; i < largestEnd; i++) {
		if (rhs.biArray_[smallestStart] != lhs.biArray_[i]) {
			return false;
		}
		smallestStart++;
	}
	return true;
}

bool operator!=(const BiArray& lhs, const BiArray& rhs) {
	int largestStart = 0;
	int largestEnd = 0;
	int smallestStart = 0;
	// find largest array to loop through for comparison.
	if (rhs.size_ > lhs.size_) {
		largestStart = rhs.start_;
		largestEnd = rhs.start_ + rhs.size_;
		smallestStart = lhs.start_;
	}
	else {
		largestStart = lhs.start_;
		largestEnd = lhs.start_ + lhs.size_;
		smallestStart = rhs.start_;
	}
	// start_ is different dependant for each array dependant on the capacity of the arrays.
	// therefore must set smallestStart and largestStart to their respective starts.
	for (int i = largestStart; i < largestEnd; i++) {
		if (rhs.biArray_[smallestStart] != lhs.biArray_[i]) {
			return true;
		}
		smallestStart++;
	}
	return false;
}

