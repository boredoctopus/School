#include <iostream>
#include <functional>

using namespace std;

int main()
{
  // boolean logic#1
  bool tuesday, raining, daytime ;
  tuesday = true ; // it is tuesday
  raining = true ; // it is raining
  daytime = true ; // it is during daytime

  if( tuesday && daytime && raining ) {
    std::cout << "It's Tuesday, daytime and raining\n";
  }

  raining = false ; // it has stopped raining

  if ( ! raining ) { 
    std::cout << "It's not raining\n";
  }else {
    std::cout << "It's raining\n";
  }

  if( tuesday || raining ) {
    std::cout << "It's either tuesday or it is raining\n";
  }
  // boolean logic#2
  int daysInWeek, monthsInYear, weeksInYear;
  daysInWeek = 7;
  monthsInYear = 12 ;
  weeksInYear = 52;
  
  if ( daysInWeek  == 7 ) {
    std::cout << "There are exactly " << daysInWeek << " days in a week\n"; 
  }

  if ( daysInWeek < monthsInYear ) {
    std::cout << "There are less days in a week than months in a year\n"; 
  }

  if ( weeksInYear > daysInWeek ) {
    std::cout << "There are more weeks in year, than days in a week\n"; 
  }
  
  
}
