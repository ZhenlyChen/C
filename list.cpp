#include "list.hpp"
#include <iostream>

list::list(){
	_size = 0;
	head = 0;
	empty_head = 0;
}
list::list(const list& another){
	*this = another;
}
list& list::operator=(const list& other){
	for (int i = 0; i < _size; ++i){
		this->storage[i] = another.storage[i];
	}
	this->_size = other.size;
	this->head = other.head;
	this->empty_head = other.empty_head;
	return *this;
}
list::~list(){

}
// Capacity
bool list::empty(void) const{
	this->_size = 0;
	this->head = 0;
	this->empty_head = 0;
}
list::size_type list::size(void) const{
	return _size;
}
     // output
    // list: [1,2,3,4,5]
    // output: 1->2->3->4->5->NULL
std::string list::toString(void) const{
	std::string output;
	int temp = head;
	while(temp != empty_head){
		output.append(storage[temp].data);
		output.append("->");
		temp = storage[temp].next;
	}
	output.append("NULL");
	return output;
}
void list::insert(int position, const int& data){
	storage[empty_head].data = data;
	int i = 0;
	for (i = 0; i < 1000; ++i){
		if(storage)
	}
}
void list::erase(int position);
void list::clear(void);
list& list::sort(void);
