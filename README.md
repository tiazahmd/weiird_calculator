### Weird Calculator

While I was trying to learn how to play around with C++ Class, constructors, destructors, pointers and functions, I decided that the best way to do that is to create a calculator that does the right things in weird ways, or it has weird ways of taking input or calls that gives the right answers. Here's the documentation on each function and how they work:

### Functionality:

**Initializing the Object**: The way we initialize the object is by telling the class how many numbers (double) we will be working with and what are those numbers. Example:
```C++
/* If we want to work with 5 numbers 
Make sure to use decimal points since they are doubles */

Calculator calc {5, 20.0, 12.3, 30.2, 14.8, 15.3}

/* This will generate an object calc, and will enter
the 5 numbers into an array. */
```

**Simple Addition**: This is pretty straight forward using the `add_all()` function. It adds all the numbers we provided earlier. Usage:
```C++
// Adds all the numbers provided earlier
calc.add_all();
```

**Simple Multiplication**: This is pretty straight forward using the `multiply_all()` function. It multiplies all the numbers we provided earlier. Usage:
```C++
// Multiplies all the numbers provided earlier
calc.multiply_all();
```

**Weird Subtraction**: This is where the calculator gets interesting. You have a data set of 5 numbers, but you want to subtract the first 3 numbers from the last 2. All you have to do is mention the first `x` numbers you want to subtract the rest of the numbers from. Usage:
```C++
// Subtract the last 2 numbers from the first 3 numbers
calc.weird_subtract(3);
```

**Weird Division**: This is somewhat similar to weird subtract - you tell the calculator to divide the sum of first `x` numbers with the sum of the rest of the numbers. Usage:
```C++
// Divide the first 3 numbers with the last 2 numbers
calc.weird_divide(3);
```

**Hybrid Mult Add**: The formula for this function is (for 5 numbers) `(a * b * c) + (d * e)` - so it adds the multiplied result of the first `x` numbers to the multiplied result of the rest of the numbers. Usage:
```C++
/* Multiply the firs 3 numbers and 
the last 2 numbers separately, then
add them together. */

calc.hybrid_mult_add(3);
```

**Hybrid Mult Sub**: This does something similar to Hybrid Mult Add, but instead, it subtracts the remaining miltipled numbers from the first `x` multiplied numbers. Usage:
```C++
/* Multiply the first 3 numbers and
the last 2 numbers separately, then
subtract from one another. */

calc.hybrid_mult_sub(3);
```

**Hybrid Mult Div**: This does something similar to Hybrid Mult Add and Sub, but instead, it divides the first `x` multiplied numbers with the remaining multiplied numbers. Usage:
```C++
/* Multiply the first 3 numbers and
the last 2 numbers separately, then
divide by one another. */

calc.hybrid_mult_div(3);
```

**Hybrid Add Mult**: This is kind of the opposite of Hybrid Mult Add. It adds the first `x` numbers and the remaining numbers and then multiplies them together. So for 5 numbers, the formula is: `(a + b + c) * (d + e)`.
```C++
/* Add the first 3 numbers and
then add the last two numbers. Now
Multiply the the two results. */

calc.hybrid_add_mult(3);
```

### Result

```bash
$ g++ main.cpp -o main
$ ./main

Examples: 
The regular added result is: 92.6
The regular multiplied result is: 1.68227e+06
The weird subtraction result is: 32.4
The weird division result is: 2.07641
The hybrid mult add result is: 7655.64
The hybrid mult sub result is: 7202.76
The hybrid mult div result is: 32.8087
The hybrid add mult result is: 1881.25
```