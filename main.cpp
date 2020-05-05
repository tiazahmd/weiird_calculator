#include <iostream>
#include <stdarg.h>

using namespace std;

class Calculator {
    int sz;
    double* elem;

public:
    Calculator(int s, ...) { 
        va_list ap;
        va_start(ap, s);

        sz = s;
        elem = new double[s];   
        
        for (int i = 0; i < s; i++) {
            elem[i] = va_arg(ap, double);
        }
        
        va_end(ap);
    }

    double add_all() {
        double sum = 0.0;

        for (int i = 0; i < sz; i++) {
            sum += elem[i];
        }

        return sum;
    }

    long double multiply_all() {
        double ans = 1.0;

        for (int i = 0; i < sz; i++) {
            ans *= elem[i];
        }

        return ans;
    }

    double weird_subtract(int nums) {       
        double nums_to_subtract_from = 0.0;
        double nums_to_subtract = 0.0;

        for (int i = 0; i < nums; i++) {
            nums_to_subtract_from += elem[i];
        }

        for (int j = nums; j < sz; j++) {
            nums_to_subtract += elem[j];
        }
        
        return (nums_to_subtract_from - nums_to_subtract);
    }

    double weird_divide(int nums) {
        double nums_to_divide = 0.0;
        double nums_to_divide_with = 0.0;

        for (int i = 0; i < nums; i++) {
            nums_to_divide += elem[i];
        }

        for (int j = nums; j < sz; j++) {
            nums_to_divide_with += elem[j];
        }

        return (nums_to_divide / nums_to_divide_with);
    }

    double hybrid_mult_add(int nums) {
        double nums_to_mult_1 = 1.0;
        double nums_to_mult_2 = 1.0;

        for (int i = 0; i < nums; i++) {
            nums_to_mult_1 *= elem[i];
        }

        for (int j = nums; j < sz; j++) {
            nums_to_mult_2 *= elem[j];
        }

        return (nums_to_mult_1 + nums_to_mult_2);
    }

    double hybrid_mult_sub(int nums) {
        double nums_to_mult_1 = 1.0;
        double nums_to_mult_2 = 1.0;

        for (int i = 0; i < nums; i++) {
            nums_to_mult_1 *= elem[i];
        }

        for (int j = nums; j < sz; j++) {
            nums_to_mult_2 *= elem[j];
        }

        return (nums_to_mult_1 - nums_to_mult_2);
    }

    double hybrid_mult_div(int nums) {
        double nums_to_mult_1 = 1.0;
        double nums_to_mult_2 = 1.0;

        for (int i = 0; i < nums; i++) {
            nums_to_mult_1 *= elem[i];
        }

        for (int j = nums; j < sz; j++) {
            nums_to_mult_2 *= elem[j];
        }

        return (nums_to_mult_1 / nums_to_mult_2);
    }

    double hybrid_add_mult (int nums) {
        double nums_to_add_1 = 0.0;
        double nums_to_add_2 = 0.0;

        for (int i = 0; i < nums; i++) {
            nums_to_add_1 += elem[i];
        }

        for (int i = nums; i < sz; i++) {
            nums_to_add_2 += elem[i];
        }

        return (nums_to_add_1 * nums_to_add_2);
    }
    
};


int main ()
{
    cout << "Examples: \n";

    Calculator calc {5, 20.0, 12.3, 30.2, 14.8, 15.3};
    cout << "The regular added result is: " << calc.add_all() << '\n';
    cout << "The regular multiplied result is: " << calc.multiply_all() << '\n';
    cout << "The weird subtraction result is: " << calc.weird_subtract(3) << '\n';
    cout << "The weird division result is: " << calc.weird_divide(3) << '\n';
    cout << "The hybrid mult add result is: " << calc.hybrid_mult_add(3) << '\n';
    cout << "The hybrid mult sub result is: " << calc.hybrid_mult_sub(3) << '\n';
    cout << "The hybrid mult div result is: " << calc.hybrid_mult_div(3) << '\n';
    cout << "The hybrid add mult result is: " << calc.hybrid_add_mult(3) << '\n';
}