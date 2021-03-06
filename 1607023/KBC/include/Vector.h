#ifndef VECTOR_H
#define VECTOR_H
#include<math.h>

template<class T>
class Vector
{
public:
    typedef T* Iterator;
    //Constructors
    Vector();
    Vector(unsigned int sz);
    Vector(unsigned int sz,const T&init);
    Vector(const Vector& other);
    //Destructor
    ~Vector();
    //Functions
    void assign(unsigned int sz,const T& init);
    unsigned int capacity()const;
    unsigned int size()const;
    bool empty()const;
    Iterator begin();
    Iterator end();
    T& front();
    T& back();
    void push_back(const T& value);
    void pop_back();
    void reserve(unsigned int capacity);
    void resize(unsigned int sz);
    void clear();
    //Operators
    T & operator[](unsigned int index);
    Vector<T> & operator=(const Vector<T>&);
private:
    unsigned int _size;
    unsigned int _capacity;
    unsigned int Log;
    T* buffer;
};
template<class T>
Vector<T>::Vector()
{
    _capacity=0;
    _size=0;
    buffer=0;
    Log=0;
}
template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    _size = v._size;
    Log = v.Log;
    _capacity = v._capacity;
    buffer = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        buffer[i] = v.buffer[i];
}
template<class T>
Vector<T>::Vector(unsigned int sz)
{
    _size=sz;
    Log=ceil(log((double)sz)/log(2.0));
    _capacity=(1<<Log);//powl(2,log);
    buffer=new T[_capacity];
}
template<class T>
Vector<T>::Vector(unsigned int sz,const T& init)//vector<int>(10,8)
{
    _size=sz;
    Log=ceil(log((double)sz)/log(2.0));
    _capacity=(1<<Log);
    buffer=new T[_capacity];
    for(unsigned int i=0; i<sz; i++)
        buffer[i]=init;
}
template<class T>
Vector<T>::~Vector()
{
    if(_size>1)
        delete[] buffer;
    delete buffer;
}
template<class T>
inline bool Vector<T>::empty()const
{
    return _size==0;
}
template<class T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return buffer;
}
template<class T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return buffer+size();//last element
}
template<class T>
void Vector<T>::assign(unsigned int sz,const T& init)
{
    _size=sz;
    Log=ceil(log((double)sz)/log(2.0));
    _capacity=(1<<Log);
    buffer=new T[_capacity];
    for(unsigned int i=0; i<sz; i++)
        buffer[i]=init;
}
template<class T>
T& Vector<T>::front()
{
    return buffer[0];
}
template<class T>
T& Vector<T>::back()
{
    return buffer[_size-1];
}

template<class T>
void Vector<T>::push_back(const T&v)
{
    if(_size>=_capacity)
    {
        reserve(1<<Log);
        Log++;
    }
    buffer[_size++]=v;
}
template<class T>
void Vector<T>::pop_back()
{
    (reinterpret_cast<T*>(buffer)[_size-1].~T());//last elemebnt delete korar jonno
    --_size;
}
template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
    T* newbuffer=new T[capacity];
    for(unsigned int i=0; i<_size; i++)
        newbuffer[i]=buffer[i];
    _capacity=capacity;
    if(_size>1)
        delete[] buffer;
    delete buffer;
    buffer=newbuffer;
}
template<class T>
unsigned int Vector<T>::size()const
{
    return _size;
}
template<class T>
void Vector<T>::resize(unsigned int sz)
{
    Log=ceil(log((double)sz)/log(2.0));
    reserve(1<<Log);
    _size=sz;
}
template<class T>
unsigned int Vector<T>::capacity()const
{
    return _capacity;
}
template<class T>
void Vector<T>::clear()
{
    _capacity=0;
    buffer=0;
    _size=0;
    Log=0;
}
template<class T>
Vector<T>&Vector<T>::operator=(const Vector<T>&v)
{
    if(_size>1)
        delete[] buffer;
    delete buffer;
    _size=v._size;
    Log=v.Log;
    _capacity=v._capacity;
    buffer= new T[_capacity];
    for(unsigned int i=0; i<_size; i++)
        buffer[i]=v.buffer[i];
    return *this;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}
#endif // VECTOR_H
