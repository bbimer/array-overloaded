#pragma once

#include <iostream>
#include <ctime>

template<typename T>
class Array {
private:
    size_t size;
    T* array;

public:
    Array(size_t n = 0);
    Array(size_t n, T min, T max);
    Array(const Array<T>& other);
    ~Array();

    T min() const;
    T max() const;
    void sorted();

    void print() const;
};


template<typename T>
Array<T>::Array(size_t n) : size(n) {
    array = (size > 0) ? new T[size]() : nullptr;
}

template<typename T>
Array<T>::Array(size_t n, T min, T max) : size(n) {
    array = (size > 0) ? new T[size] : nullptr;
    srand(static_cast<unsigned>(time(nullptr)));

    for (size_t i = 0; i < size; ++i) {
        array[i] = min + rand() % (max - min + 1);
    }
}

template<typename T>
Array<T>::Array(const Array<T>& other) : size(other.size) {
    array = (size > 0) ? new T[size] : nullptr;
    for (size_t i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

template<typename T>
T Array<T>::min() const {
    if (size != 0) {
        T min_value = array[0];
        for (size_t i = 1; i < size; ++i) {
            if (array[i] < min_value) {
                min_value = array[i];
            }
        }
        return min_value;
    }
}

template<typename T>
T Array<T>::max() const {
    if (size != 0) {
        T max_value = array[0];
        for (size_t i = 1; i < size; ++i) {
            if (array[i] > max_value) {
                max_value = array[i];
            }
        }
        return max_value;
    }
}

template<typename T>
void Array<T>::sorted() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void Array<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
Array<T>::~Array() {
    if (array) {
        delete[] array;
    }
}
