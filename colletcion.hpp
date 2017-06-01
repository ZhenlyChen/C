#ifndef COLLECTION_HPP_
#define COLLECTION_HPP_
class Collection{
public:
  typedef E int;
  virtual void add(E e) = 0;
  virtual void clear(void) = 0;
  virtual bool contain(E e) = 0;
  virtual bool isEmpty(void) = 0;
  virtual void remove(E e) = 0;
  virtual int size(void) = 0;
};
#endif


//Collection应支持的接口：add、clear、contain、isEmpty、remove、size
