#pragma once
//////////////////////////////////////////////////////////////////////////////
//File:        string.h
//       
//Version:     1.1
//Date:        Fall 2022
//Author:      Dr. J. Maletic
//Revised by:  Dr. Y. Chae
//
//Description: Interface definition of String class.
//             For use with Mandatory Assignment.
//
// You must also have all of these methods and functions defined for your string 
// class.
//
// You need to implement all of the methods and funcitons declared here.
//
#ifndef CS23001_STRING_INTERFACE_H
#define CS23001_STRING_INTERFACE_H
#include <iostream>
////////////////////////////////////////////////////
// CLASS INV: str[length()] == 0             &&
//            length()      == capacity()    &&
//            capacity()    == stringSize - 1
//
class String {
public:
            String();                               //Empty string
            String(char);                           //String('x')
            String(const char[]);                   //String("abc")
            String(const String&);                  //Copy Constructor
            ~String();                              //Destructor
    void    swap(String&);                          //Constant time swap
    String& operator=   (String);                   //Assignment Copy
    int     capacity()                      const;  //Max chars that can be stored
    int     length()                        const;  //Actual number of chars in string
    char&   operator[]  (int);                      //Accessor/Modifier
    char    operator[]  (int)               const;  //Accessor

    String& operator+=    (const String&);
    bool    operator==    (const String&)   const;
    bool    operator<     (const String&)   const;
    String  substr(int, int)                const;  //Sub from staring to ending position
    int     findch(int, char)               const;  //Location of charater starting at position
    int     findstr(int, const String&)     const;  //Location of string starting at a position

    friend  std::ostream& operator<<(std::ostream&, const String&);
    friend  std::istream& operator>>(std::istream&, String&);
private:
    char* str;                                       //Pointer to char[]
       int     stringSize;                           //Size includes NULL terminator
};

String  operator+       (String, const String&);
bool    operator==      (const char[], const String&);
bool    operator==      (char, const String&);
bool    operator<       (const char[], const String&);
bool    operator<       (char, const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);
#endif