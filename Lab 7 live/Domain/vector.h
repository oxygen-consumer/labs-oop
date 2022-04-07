//
// Created by zaha on 4/7/22.
//

#ifndef LAB_7_LIVE_VECTOR_H
#define LAB_7_LIVE_VECTOR_H


template<class T>
class vector {
private:
    T *data;
    int _size;
    int _capacity;

    const int _batch_size = 1024;

    void resize() {
        T *new_data = new T[_capacity + _batch_size];
        for (int i = 0; i < _size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

public:
    vector() {
        _size = 0;
        _capacity = _batch_size;
        data = new T[_capacity];
    }

    vector(vector<T> const &rhs) {
        _size = rhs._size;
        _capacity = rhs._capacity;
        data = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            data[i] = rhs.data[i];
        }
    }

    ~vector() {
        delete[] data;
    }

    vector<T> &operator=(vector<T> const &rhs) {
        if (this != &rhs) {
            _size = rhs._size;
            _capacity = rhs._capacity;
            delete[] data;
            data = new T[_capacity];
            for (int i = 0; i < _size; ++i) {
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }

    void push_back(T const &value) {
        if (_size == _capacity) {
            resize();
        }
        data[_size++] = value;
    }

    T &operator[](int index) {
        return data[index];
    }

    void remove(int index) {
        for (int i = index; i < _size - 1; ++i) {
            data[i] = data[i + 1];
        }
        _size--;
    }

    int size() {
        return _size;
    }

    void update(int index, T const &value) {
        data[index] = value;
    }

    void clear() {
        _size = 0;
    }
};


#endif //LAB_7_LIVE_VECTOR_H
