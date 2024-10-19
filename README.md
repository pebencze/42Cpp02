# Overview
Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form.

## Key Concepts

### Fixed Point Numbers
With a fractional part of 8 bits, the smallest positive value that can be represented is indeed 0.00390625.

Explanation
- Fractional Bits: With 8 fractional bits, the smallest step size is 1 / (1 << 8), which is 1 / 256. </b>
Calculation: 1 / 256 = 0.00390625. </b>

Example </b>
In the fixed-point representation with 8 fractional bits: </b>
- The value 1 is represented as 256 (since 1 << 8 = 256). </b>
- The value 0.00390625 is represented as 1 (since 0.00390625 * 256 = 1). </b>

- *fixing* the binary point to be at some position of a numeral </b>
- two parameters: </b>
    - width of the number representation </b>
    - binary point position within the number </b>
- e.g: **fixed<8,3>** denotes a 8-bit fixed point number, of which 3 right most bits are fractional. </b>
- fixed point numbers are indeed a close relative to integer representatio; the two only differs in the position of binary point. In fact, you might even consider integer representation as a "special case" of fixed point numbers

### Orthodox Canonical Form
The canonical form is kind of a norm in C++ and it is a template for the syntax of a class. A class should have:</b>
- a default constructor </b>
- a copy constructor (to create a new instance) </b>
- a copy assignment operator (to update the instance; is used in the copy constructor) </b>
- a destructor </b>

Syntax of a copy constructor:
```c++
Fixed::Fixed( Fixed const & src) {
    *this = src;
}
```

Passing by Value: If the copy constructor's parameter was passed by value, `Fixed::Fixed( Fixed const src)`, it would require creating a copy of the object to pass to the constructor.
Copy Constructor Call: Creating this copy would invoke the copy constructor again to create the copy of the object.
Infinite Recursion: This process would repeat indefinitely, leading to **infinite recursion** and eventually a stack overflow.

To avoid self-assignment problems, the check in the assignment operator functions is crucial in more complex programs e.g. double deletion, memory corruption, or other unexpected behavior:
```c++
Fixed & Fixed::operator=( Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) { //check
        this->_fixed = rhs.getRawBits();
    }
    return *this;
}
```

### Initializer list
A member initializer list is used in the constructor to initialize members before the constructor body gets executed.

### Operator / Function Overload
~ **"adhoc polymorphism"** </b>
C++ allows you to specify more than one definition for a function name or an operator in the same scope.
When you call an overloaded function or operator, the compiler determines the most appropriate definition to use, by comparing the argument types you have used to call the function or operator with the parameter types specified in the definitions
```c++
Fixed & Fixed::operator=( Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) { //check
        this->_fixed = rhs.getRawBits();
    }
    return *this;
}

Fixed::Fixed ( const int num ) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed ( const float num ) {
    std::cout << "Float constructor called" << std::endl;
}
```
!!! constructors DON´T have a return type, not even const.

#### Operator Overload ++ / --
	1.	Prefix Increment (++x):
	•	Signature: Fixed& operator++();
	•	Behavior: Increments the value of the object and returns a reference to the updated object.
	2.	Postfix Increment (x++):
	•	Signature: Fixed operator++(int);
	•	Behavior: Increments the value of the object but returns the value before the increment. The int parameter is a dummy parameter to distinguish it from the prefix increment operator.

 ### Bitwise Operations on Floats
 Bitwise operations work well on integers. However, applying a bitwise shift to a floating-point number (input << this->_digits) is not a valid operation in most programming languages, including C++. Therefore we shift one to the number of bits and then multiply our input by it (input * (1 << this->digits)).

Here we first cast our int _fixed to a float, so that we can perform a division pon it without osing the fractional part:
```c++
 float Fixed::toFloat( void ) const {
    return (static_cast<float>(this->_fixed) / (1 << this->_fraction));
}
```
The expression this->_fixed = roundf(num << this->_fraction); is incorrect because it attempts to use the bitwise left shift operator (<<) on a floating-point number, which is not valid. The left shift operator is intended for integer types, not floating-point types.

Correct Approach
You need to multiply the floating-point number by the scaling factor, then round it, and finally convert it to an integer. Here's the correct and simplified version:

this->_fixed = static_cast<int>(roundf(num * (1 << this->_fraction)));

### Precision Errors
Wy does *42.42f* become *42.4219*???
- Scaling: The float 42.42f is scaled by 256 (since _fraction is 8): [ 42.42 \times 256 = 10842.24 ]
- Rounding: The roundf function rounds 10842.24 to the nearest integer: [ \text{roundf}(10842.24) = 10842 ]
- Fixed-Point Representation: The integer 10842 is stored in _fixed.
- Conversion Back to Float: When converting back to float, the fixed-point value is divided by 256: [ \frac{10842}{256} = 42.421875 ]

### Destructors
1. Resource Management
Memory Deallocation: If your class allocates memory dynamically (e.g., using new or malloc), the destructor is responsible for freeing that memory (e.g., using delete or free).
Releasing Handles: If your class acquires handles to system resources (e.g., file handles, network sockets), the destructor ensures these handles are properly released.
2. Cleanup
Closing Files: If your class opens files, the destructor can ensure that these files are properly closed.
Flushing Buffers: If your class uses buffers for I/O operations, the destructor can ensure that these buffers are flushed.
3. Preventing Resource Leaks
Automatic Cleanup: When an object goes out of scope or is explicitly deleted, the destructor is automatically called, ensuring that resources are cleaned up even if the programmer forgets to do so manually.
4. Exception Safety
RAII (Resource Acquisition Is Initialization): Destructors are a key part of the RAII idiom, which ensures that resources are properly released even if an exception is thrown.

### << Operator Overload
The operator<< function is defined outside of your class because it is a non-member function. Here are the reasons why:
1. Symmetry and Consistency
Symmetry: The operator<< function typically takes an std::ostream object as its first parameter and the object to be printed as its second parameter. Defining it as a non-member function maintains symmetry with the std::ostream class, which is not part of your class.
Consistency: This approach is consistent with how the standard library defines stream insertion operators for built-in types.
2. Access to Private Members
Friend Function: If the operator<< needs access to private or protected members of your class, you can declare it as a friend function within your class. This allows the non-member function to access private members while keeping the function definition outside the class.
3. Separation of Concerns
Class Responsibilities: Keeping the operator<< function outside the class helps to separate the responsibilities of the class. The class focuses on its core functionality, while the operator<< function handles the specific task of formatting the output.

### Prefix and Postfix operators
- Postfix operators return a copy of the object before modification.
    Example usage: Fixed a; Fixed b = a--; (b gets the original value of a, a is decremented).
- Prefix operators return a reference to the modified object.
    Example usage: Fixed a; Fixed b = ++a; (a is incremented, b gets the incremented value of a).
