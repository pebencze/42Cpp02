# Overview
Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form.

## Key Concepts

### Orthodox Canonical Form
The canonical form is kind of a norm in C++ and it is a template for the syntax of a class. A class should have:</b>
- a default constructor </b>
- a copy constructor (to create a new instance) </b>
- an assignment operator (to update the instance) </b>
- a destructor </b>

Syntax of a copy constructor:
```c++
Fixed::Fixed( Fixed const & src) {
    *this = src;
}
```

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

### Fixed Point Numbers
- *fixing* the binary point to be at some position of a numeral </b>
- two parameters: </b>
    - width of the number representation </b>
    - binary point position within the number </b>
- e.g: **fixed<8,3>** denotes a 8-bit fixed point number, of which 3 right most bits are fractional. </b>
- fixed point numbers are indeed a close relative to integer representatio; the two only differs in the position of binary point. In fact, you might even consider integer representation as a "special case" of fixed point numbers, where the binary point is at position</b>
    
 $$
    0.00010.110
    
    = 1 * 21 + 1 * 2-1 + 1 * 2-1
    
    = 2 + 0.5 + 0.25
    
    = 2.75
 $$

 ### Bitwise Operations on Floats
 Bitwise operations work well on integers. However, applying a bitwise shift to a floating-point number (input << this->_digits) is not a valid operation in most programming languages, including C++. Therefore we shift one to the number of bits and then multiply our input by it (input * (1 << this->digits)). 

Here we first cast our int _fixed to a float, so that we can perform a division pon it without osing the fractional part:
```c++
 float Fixed::toFloat( void ) const {
    return (static_cast<float>(this->_fixed) / (1 << this->_fraction)); 
}
```
