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
