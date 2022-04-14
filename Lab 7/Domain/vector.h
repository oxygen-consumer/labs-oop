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

    /**
     * @brief Increase capacity of vector by 1024 elements
     */
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
    /**
     * @brief Default constructor
     */
    vector() {
        this->data = new T[_batch_size];
    }

    /**
     * @brief Copy constructor
     * @param rhs vector to copy
     */
    vector(vector const &rhs) {
        this->data = new T[rhs._capacity];
        this->_capacity = rhs._capacity;
        this->_size = rhs._size;
        for (int i = 0; i < rhs._size; i++) {
            this->data[i] = rhs.data[i];
        }
    }

    /**
     * @brief Overloaded assignment operator
     * @param rhs vector to copy
     * @return reference to this vector
     */
    vector<T> &operator=(vector<T> const &rhs) {
        if (this != &rhs) {
            delete[] this->data;
            this->data = new T[rhs._capacity];
            this->_capacity = rhs._capacity;
            this->_size = rhs._size;
            for (int i = 0; i < rhs._size; i++) {
                this->data[i] = rhs.data[i];
            }
        }
        return *this;
    }

    /**
     * @brief Destructor
     */
    ~vector() {
        delete[] this->data;
    }

    /**
     * @brief Add element to vector
     * @param value element to add
     */
    void push_back(T const &value) {
        if (this->_size == this->_capacity) {
            this->resize();
        }
        this->data[this->_size++] = value;
    }

    /**
     * @brief Remove element from vector
     * @param index index of element
     */
    void remove(unsigned int index) {
        if (index >= this->_size) {
            return;
        }
        for (unsigned int i = index; i < this->_size - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->_size--;
    }

    /**
     * @brief Insert element to vector
     * @param index the index to insert at
     * @param value the element to insert
     */
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

    /**
     * @brief Get the size of the vector
     * @return the size of the vector
     */
    [[nodiscard]] unsigned int size() const {
        return this->_size;
    }

    /**
     * @brief Overload [] operator to get element at index
     * @param index index of element
     * @return element at index
     */
    T &operator[](unsigned int index) {
        return this->data[index];
    }
};


#endif //LAB_7_VECTOR_H