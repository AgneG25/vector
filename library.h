#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

template<typename T>
class vector {
private:
    size_t vsize;
    size_t maxsize;
    T* array;

public:
    typedef T *iterator;
    typedef T *const_iterator;
    typedef T &reference;
    typedef T &const_reference;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    vector() : vsize{ 0 }, array{ new T[vsize] }, maxsize{ 0 } {};
    vector(size_t sz) : vsize{ sz }, array{ new T[vsize] }, maxsize{ sz } {};
   
    vector(size_t sz, T value) : vsize{ sz }, array{ new T[vsize] }, maxsize{ sz } { fill_n(array, sz, value); }

    ~vector(){ delete [] array; }


    vector& operator=(const vector& v) {
        if (&v == this) return *this; // Savęs priskyrimo aptikimas

        T* p = new T[v.vsize];
        for (int i = 0; i != v.vsize; i++)
            p[i] = v.array[i];
        delete[] array; // atlaisviname seną atmintį!
        array = p;
        vsize = v.vsize;     // atnaujiname size
        maxsize=v.capacity();
        return *this;  // grąžiname objektą
    }

    T& operator[](size_t i) { return array[i]; }
    const T& operator[](size_t i) const { return array[i]; }

    void push_back(T i) {
        if(vsize + 1 > maxsize)
            resize(vsize + 10);
        array[vsize] = i;
        vsize++;
    }
    
        
    /*void reserve(size_t n) 
        {
            if (maxsize < n) 
            {
                T *temp = new T[n];
                for (auto i = 0; i < vsize; i++) {
                    temp[i] = array[i];
                }
                delete[] array;
                array = temp;
                maxsize = n;
                temp = nullptr;
		    }
	    }
    vector(vector&& v) : vsize{ v.vsize }, array{ v.array }, maxsize{ v.maxsize } {
        v.array = nullptr;
        v.vsize = 0;
        v.maxsize = 0;
    }*/

    void pop_back () {
        if(vsize != 0)
            vsize--;
    }

    void erase(size_t i) {
        if (i < 0 || i >= vsize)
            return;
        vsize--;
        std::move(&array[i + 1], &array[vsize], &array[i]);
    }

    void erase(iterator first, iterator last){
        if ((first > array + vsize)||(last > array + vsize)) {
            std::cout << "Error: you are out of array" << std::endl;
            return;
        }
        std::move(last + 1, last + vsize, first);
        vsize--;
        while(first!=last){
            vsize--;
            first++;
        }
    }

    void clear() { vsize = 0; delete[] array; array = new T[maxsize]; }
    bool empty() { return vsize == 0; }

    size_t size() const { return vsize; }
    size_t capacity() const { return maxsize; }

    vector(std::initializer_list<T> li) : vsize{static_cast<int>(li.size())}, maxsize{vsize}, array{new T[li.size()]} {
        std::copy(li.begin(), li.end(), array);
    }

    iterator begin() {
        if (vsize == 0) throw std::out_of_range("Tuscias vektorius!");
        return array;
    }
    iterator end() {
        if (vsize == 0) throw std::out_of_range("Tuscias vektorius!");
        return array + vsize;
    }
    void resize(size_t n) 
        {
            size_t end;
            if (n == maxsize) return;

            T *temp = new T[n];

            if (n < vsize) {
                vsize = n;
                end = n;
            }
            else end = vsize;

            std::move(&array[0], &array[end], temp);
            maxsize = n;
            delete[] array;
            array = temp;
        }
};

#endif //VECTOR_H
