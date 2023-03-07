#ifndef CUASTATICA_H
#define CUASTATICA_H

#pragma once

class CuaStatica
{
public:
    CuaStatica();
    CuaStatica(const CuaStatica &origen);
    ~CuaStatica();
    void enqueue(const int key);
    void dequeue();
    bool isFull() const;
    bool isEmpty() const;
    void print() const;
    const int getFront() const;
    int sizeCua() const;

private:

    enum {DEFAULT_MAX_SIZE = 30};
    int _rear;
    int _size;
    int _data[DEFAULT_MAX_SIZE];

  

};

#endif