//
// Created by zaha on 3/17/22.
//

#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

#ifndef LAB_4_COMPLEX_NUM_H
#define LAB_4_COMPLEX_NUM_H

class complex_num {
private:
    double real, img;
public:
    /**
     * Default constructor. Sets the imaginary and the real part to 0
     */
    complex_num();

    /**
     * Constructor with parameters
     * @param real the real part of the complex_num number
     * @param img the imaginary part of the complex_num number
     */
    complex_num(double real, double img);

    /**
     * Constructor to transfer another complex_num to current object
     * @param n a complex_num object
     */
    complex_num(complex_num const &n);

    /**
     * Destructor
     */
    ~complex_num();

    /**
     * Sets the real part to a given number
     * @param n the number
     */
    void set_real(double n);

    /**
     * Sets the imaginary part to a given number
     * @param n the number
     */
    void set_img(double n);

    /**
     * Returns the real part of the number
     * @return the real part of the number
     */
    double get_real() const;

    /**
     * Returns the imaginary part of the number
     * @return the imaginary part of the number
     */
    double get_img() const;

    /**
     * Check if two complex numbers are equal
     * @param x first complex number
     * @param y second complex number
     * @return true if they are equal, false otherwise
     */
    friend bool operator==(const complex_num &x, const complex_num &y);

    /**
     * Converts a complex number to string and returns it
     * @return a string representing the complex number
     */
    std::string to_str() const;

    /**
     * Asks user for the real and imaginary parts and saves them
     */
    void read_from_stdin();

    /**
     * Calculate distance from origin (0, 0)
     * @return distance from origin
     */
    double distance_from_orig();
};

#endif //LAB_4_COMPLEX_NUM_H
