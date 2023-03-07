#include "CuaStatica.h"
#include <iostream>
using namespace std;





CuaStatica::CuaStatica()
{
    _rear = 0;
    _size = 0;
}
CuaStatica::CuaStatica(const CuaStatica &origen)
{

    for (int i = 0; i < origen.sizeCua(); i++)
    {
        this->_data[i] = origen._data[i];
    }
    this->_rear = origen._rear;
    this->_size = origen._size;
}
CuaStatica::~CuaStatica() {}
void CuaStatica::enqueue(const int key)
{

    if ( !isFull()){
        
        this->_data[_rear] = key;
        this-_rear ++;
        this->_size ++;
    }
    else{
        throw string("Cua plena");
    }
}
void CuaStatica::dequeue() {

    if ( !isEmpty()){
        for ( int i = 1; i < _size; i++)
        {
            _data[i-1] = _data[i];
        }
        _rear --;
        _size --;
        
    }else{
        throw string("narices");
    }
}
bool CuaStatica::isFull() const
{
    return _size == DEFAULT_MAX_SIZE;
}
bool CuaStatica::isEmpty() const
{
    return _size == 0;
}
void CuaStatica::print() const
{

    for (int i = 0; i < sizeCua(); i++)
    {
        cout << " " << _data[i] << " Rear: " << _rear << " size: " << _size << endl;
    }
}
const int CuaStatica::getFront() const
{
    if ( !isEmpty()){
        return _data[0];
    }
    else{
        throw string ("cua buïda");
    }
}
int CuaStatica::sizeCua() const
{
    return _size;
}
