//
// Created by zaha on 3/17/22.
//

#ifndef LAB_4_COMPLEXNUMBER_H
#define LAB_4_COMPLEXNUMBER_H


class ComplexNumber {
private:
    double real, img;
public:
    ComplexNumber();
    ComplexNumber(double real, double img);
    ComplexNumber(ComplexNumber const &n);
    ~ComplexNumber();

    void set_real(double n);
    void set_img(double n);

    double get_real() const;
    double get_img() const;
};


#endif //LAB_4_COMPLEXNUMBER_H
