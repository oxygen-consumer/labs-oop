//
// Created by zaha on 3/17/22.
//

#ifndef LAB_4_COMPLEXNUMBER_H
#define LAB_4_COMPLEXNUMBER_H


class ComplexNumber {
private:
    double real, img;
public:
    /**
     * Default constructor. Sets the imaginary and the real part to 0
     */
    ComplexNumber();

    /**
     * Constructor with parameters
     * @param real the real part of the complex number
     * @param img the imaginary part of the complex number
     */
    ComplexNumber(double real, double img);

    /**
     * Constructor to transfer another ComplexNumber to current object
     * @param n a ComplexNumber object
     */
    ComplexNumber(ComplexNumber const &n);

    /**
     * Destructor
     */
    ~ComplexNumber();

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
};


#endif //LAB_4_COMPLEXNUMBER_H
