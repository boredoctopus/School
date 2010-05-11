#include <iostream>
/*
** Week: 1 / 2
** File: conversion.cpp
**       convert between inches and centimetres
**       input number, followed by 'i' for inch (to cent. conversion)
**       or by 'c' for centimetre (to inch conversion)
** based on Stroustrup (C++ Prog Language, 2nd Ed.) 
*/
using std::cout;
using std::cin;
int main(int argc, char* argv[])
{
  const float fac = 2.54 ;
  bool doExit = false;
  while( ! doExit ) {
    cout << "Number followed by i for inch input, c for centimetres input\n";
    cout << "Enter length: ";
    float x;
    cin >> x ; // read floating point number
    char ch = 0; 
    cin >> ch; // read input suffix
    cin.get(); // read off newline

    float in, cm;
    if( ch == 'i' ) { // inch, convert to centimetres
      in = x ;
      cm = x * fac ;
    }else if ( ch == 'c' ) { // centimetres, convert to inch
      in = x / fac ;
      cm = x ;
    }else{
      in = cm = 0;
    }// inch/cm if
    
    ( ch == 'c' // print out input unit first, using conditional operator
      ? cout << cm << " cm = " << in << " in\n"
      : cout << in << " in = " << cm << " cm\n" );

    cout << "Return to continue or 'x' to exit : " ; 
    ch = cin.get() ;
    if( ch == 'x' || ch == 'X' ) {
      doExit = true;
    }// if x
  }// while
}
