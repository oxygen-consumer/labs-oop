//
// Created by zaha on 4/3/22.
//

#ifndef LAB_7_VECTOR_H
#define LAB_7_VECTOR_H


template<class T>
class vector {
private:
    T *data;
    unsigned int _size = 0;
    unsigned int _capacity = 1024;

    static const unsigned int _batch_size = 1024;

    void resize() {
        T *temp = new T[this->_capacity + _batch_size];
        for (int i = 0; i < this->_size; i++) {
            temp[i] = this->data[i];
        }
        delete[] this->data;
        this->data = temp;
        this->_capacity += _batch_size;
    }

public:
    vector() {
        this->data = new T[_batch_size];
    }

    vector(vector const &rhs) {
        this->data = new T[rhs._capacity];
        this->_capacity = rhs._capacity;
        this->_size = rhs._size;
        for (int i = 0; i < rhs._size; i++) {
            this->data[i] = rhs.data[i];
        }
    }

    ~vector() {
        delete[] this->data;
    }

    void push_back(T const &value) {
        if (this->_size == this->_capacity) {
            this->resize();
        }
        this->data[this->_size++] = value;
    }

    void remove(unsigned int index) {
        if (index >= this->_size) {
            return;
        }
        for (unsigned int i = index; i < this->_size - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->_size--;
    }

    void insert(unsigned int index, T const &value) {
        if (index >= this->_size) {
            return;
        }
        if (this->_size == this->_capacity) {
            this->resize();
        }
        for (int i = this->_size; i > index; i--) {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = value;
        this->_size++;
    }

    [[nodiscard]] unsigned int size() const {
        return this->_size;
    }

    T &operator[](unsigned int index) {
        return this->data[index];
    }
};


#endif //LAB_7_VECTOR_H