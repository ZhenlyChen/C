#include "ArrayList.hpp"

ArrayList::ArrayList(){
	int _maxsize = 64;
	int _size = 0;
	storage = new E[_maxsize];
}

ArrayList::~ArrayList(){
	delete[] storage;
}

void ArrayList::extend(void){
	E* temp = new E[_maxsize * extend_factor];
	for (int i = 0; i < _maxsize; ++i){
		temp[i] = storage[i];
	}
	delete[] storage;
	storage = temp;
	_maxsize *= extend_factor;
}

void ArrayList::add(E e){
	if(_size == _maxsize)extend();
	storage[_size] = e;
	_size++;
}

void ArrayList::clear(void){
	_size = 0;
}

bool ArrayList::contain(E e){
	for (int i = 0; i < _size; ++i){
		if(storage[i] == e) return true;
	}
	return false;
}

bool ArrayList::isEmpty(void){
	return !_size;
}

void ArrayList::remove(E e){
	for (int i = 0; i < _size; ++i){
		if(storage[i] == e){
			for (int j = i; j < _size - 1; ++j){
				storage[j] = storage[j + 1];
			}
			i--;
			_size--;
		}
	}
}

E& ArrayList::operator[](int index){
	return storage[index];
}
E& ArrayList::get(int index){
	return storage[index];
}
int ArrayList::indexOf(E element){
	for (int i = 0; i < _size; ++i){
		if(storage[i] == element) return i;
	}
	return -1;
}
void ArrayList::sort(void){
	quicksort(storage, 0, _size - 1);
}

int ArrayList::size(void){return _size;}

void quicksort(int* A,int lo,int hi){
	if (lo < hi){
		p = partition(A, lo, hi);
        quicksort(A, lo, p - 1);
        quicksort(A, p + 1, hi);
	}
}

int partition(int* A,int lo,int hi){
	int pivot = A[hi]
    int i = lo     
    for (int j = lo; j < hi - 1; ++j){
     	if (A[j] ≤ pivot){
     		int tmp = A[i];
     		A[i] = A[j];
     		A[j] = tmp;
     	}
     	i++;
    } 
    int tmp = A[hi];
    A[i] = A[hi];
    A[hi] = tmp;
    return i 
}
