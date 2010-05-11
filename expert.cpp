#include <iostream>
#include <functional>
// for boolean keywords (and, or, xor etc)
// on linux

using namespace std;
// Expert Logic from 'Expert Systems'
// Giarratano and Riley, 2nd Ed.
// p.121

bool FAULT_trouble_changing_gear;
bool FAULT_cannot_select_reverse;
bool FAULT_poor_acceleration;
bool FAULT_engine_stalls_alot;

bool SOLUTION_replace_gearbox;
bool SOLUTION_replace_carburettor;

bool DECISION_repair_the_car;
bool DECISION_sell_the_car;


int main()
{
  // solution for diagnosed fault
  SOLUTION_replace_gearbox = false ;
  SOLUTION_replace_carburettor = false ;

  // transmission fault
  FAULT_trouble_changing_gear = true;
  FAULT_cannot_select_reverse = false;
  
  // bad carburetor
  FAULT_poor_acceleration = true ;
  FAULT_engine_stalls_alot = true ;

  //check for transmission fault
  if ( FAULT_trouble_changing_gear && FAULT_cannot_select_reverse ) {
    std::cout << "The transmission is broken\n";
    SOLUTION_replace_gearbox = true ;
  }
  
  if ( FAULT_trouble_changing_gear || FAULT_cannot_select_reverse ) {
    std::cout << "The transmission has an intermittent fault\n";
  }
  
  if ( ! FAULT_cannot_select_reverse ) {
    std::cout << "Car can drive forward\n";
  }

  //check for carburettor fault
  if ( FAULT_poor_acceleration && FAULT_engine_stalls_alot ) {
    std::cout << "The carburetta is broken\n";
    SOLUTION_replace_carburettor = true ;
  }
  
  if ( FAULT_poor_acceleration ^ FAULT_engine_stalls_alot  ) {
    std::cout << "(xor) The carburetta has an intermittent fault\n";
  }

  if ( FAULT_poor_acceleration || FAULT_engine_stalls_alot  ) {
    std::cout << "(or) The carburetta has an intermittent fault\n";
  }

  // use diagnosis for expert system advise
   if ( SOLUTION_replace_gearbox && SOLUTION_replace_carburettor ) { //
    std::cout << "Expert System advises SELL THE CAR\n";
  }

  if ( SOLUTION_replace_gearbox ^ SOLUTION_replace_carburettor ) { // XOR
    std::cout << "Expert System advises REPAIR THE CAR\n";
  }
  
}

