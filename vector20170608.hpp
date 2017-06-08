#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "base.h"

template< typename T, typename Alloc = std::allocator<T> >
class myVector : public Base {
    public:
        // Constructor
        myVector(){
            _capacity = 0;
            _size = 0;
            _data = NULL;
        }

        myVector(const std::size_t & size, const T & val,
                 Alloc a = Alloc()){
            a.construct(_data,size);
            for (int i = 0; i < size; ++i){
                _data[i] = val;
            }
            _size = size;
            _capacity = size;
         }


        template<typename InputIterator>
        myVector(InputIterator begin, InputIterator end,
            Alloc a = Alloc()){

        }
        myVector(const myVector & other);
        ~myVector(){
            Alloc a = Alloc();
            a.destroy(_data);
        }
         // Copy Operator
        
        myVector & operator=(const myVector & other);
         // Iterator
        typedef T *         iterator;
        typedef const T *   const_iterator;
        inline iterator begin(){
            return _data;
        }
        inline const_iterator begin() const{
            return _data;
        }
        inline iterator end(){
            return _data[_size - 1];
        }
        inline const_iterator end(){
            return _data[_size - 1];
        }
        // Capacity
        inline std::size_t size(){
            return _size;
        }

        void resize(const std::size_t & newSize);
        void resize(const std::size_t & newSize, const T & val);
        inline std::size_t capacity() const{
            return _capacity;
        }
        inline bool empty() const{
            return !_size;
        }
        void reserve(const std::size_t & newCapacity){
            Alloc a = Alloc();
            T* tmp;
            a.construct(tmp, newCapacity);
            for (int i = 0; i < _capacity; ++i){
               tmp[i] = _data[i];
            }
            a.destroy(_data);
            _data = tmp;
            _capacity = newCapacity;
        }
         // Element Access
        inline T & operator[](const std::size_t & index){
            return _data[index];
        }
        inline const T & operator[](const std::size_t & index) const{
            return _data[index];
        }
        inline T & front(){
            return _data[0];
        }
        inline const T & front() const{
            return _data[0];
        }(){
            if(empty())return;
            _size--;
        }

        inline T & back(){return _data[_size - 1]}
        inline const T & back() const{return _data[_size - 1]}
        inline T * data(){return _data;}
        inline const T * data() const;{return _data;}
         // Modifiers
        template<typename InputIterator>
        void assign(InputIterator begin, InputIterator end);
        void assign(const std::size_t & newSize, const T & val);
        void push_back(const T & val){
            if(_size == _capacity){
                reserve(_capacity * 2);
            }
            _data[_size] = val;
            _size++;
        }
        void pop_back(){
            if(empty())return;
            _size--;
        }

        void clear(){
            _size = 0;
        }
     private:
        T * _data;
        std::size_t _size, _capacity;
};


#endif
