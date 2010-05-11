/*
** week: 1 
** file: Main.cpp ( demonstrates features developed during the course )
** linux compile with: g++ Main.cpp -o main
** win32 compile with: cl Main.cpp
** demonstrates: Programming Constructions:-
**               Sequencing, Selection (if), Iterations (while/for) 
** demonstrates: Pre-processing directives
** demonstrates: Arrays
** demonstrates: Classes - (constructors,destructors) 
** demonstrates: Overloaded functions, friends
** demonstrates: Template classes, 
** demonstrates: STL vectors,strings
** demonstrates: STL Iterators
** demonstrates: Exceptions - classes; throwing and catching
** demonstrates: Functions, function parameters, references
** demonstrates: Function pointers
** demonstrates: Enumeration type definitions
** demonstrates: Typedefs
** demonstrates: Dynamic memory allocation/deletion (using new and delete)
*/
#include "association.h"

int main(int argc, char* argv[])
{
  /* *************************************************
  ** define base data types: vector of class templates
  ** *************************************************/
  vector<Association <int> *> daysInMonth;  // vector of pointers 
  vector<Association <string> > mimeDictionary(10); // fixed vector

  /* *****************************************************************
  ** populate class template vectors using two different function call
  ** methods - standard call, and pointer to function call.......
  ** ****************************************************************/
  PTR_FUNC fillDictionary = &addMimeTypes ; // assign function pointer
  (*fillDictionary)(mimeDictionary); 
  // populate mime dictionary invoking function via function pointer

  addMonths( daysInMonth ); // populate months using normal function
  
  
  /* **********************************************************
  ** using iterator to identify all element with KEY of 30 days
  ** **********************************************************/
  cerr << "Using Days In Month dictionary, identify months with 30 days" << endl;
  vector<Association <int> *>::iterator iter2 = daysInMonth.begin();
  while( iter2 != daysInMonth.end() ) {
    Association<int> *p = *iter2; // extract element from vector
    if( p->key() == 30 ) {
      cerr << *p ; // print, using output operator
    }
    iter2++;
  }

  /* ******************************************************************
  ** using function 'atKey' identify value elements with specified keys
  ** ******************************************************************/
  cerr << "\n\nUsing Mime Types dictionary, identify any with specified key" << endl;
  try{
    string not_found_key="abc"; // this is not in the mime-dictionary types
    int idx = atKey(mimeDictionary, not_found_key) ;
    cerr << "FOUND KEY: " <<  mimeDictionary[idx].key()  
	 <<  " AT VALUE: " << mimeDictionary[idx].value() << endl;
  }catch(NotFoundException E) {
    cerr << E << endl; // now do something sensible - like adding key/value pair
  }
  cerr << "...now identify any with key taken as default parameter" << endl;
  try{
    int idx = atKey(mimeDictionary) ; // use default parameter
    cerr << "FOUND KEY: " <<  mimeDictionary[idx].key()  
	 <<  " AT VALUE: " << mimeDictionary[idx].value() << endl;
  }catch(NotFoundException E) { 
    cerr << E << endl;
  }

  cleanup(daysInMonth); // cleanup heap memory
}

/*
** fill a vector with 10 elements 
*/
void addMimeTypes(vector< Association <string> >& dict)
{
  dict[0].key("doc")  ; dict[0].value("application/msword");
  dict[1].key("dot")  ; dict[1].value("application/msword");
  dict[2].key("bmp")  ; dict[2].value("image/bmp");
  dict[3].key("c")    ; dict[3].value("text/plain");
  dict[4].key("html") ; dict[4].value("text/html");
  dict[5].key("jpeg") ; dict[5].value("image/jpeg");
  dict[6].key("mov")  ; dict[6].value("video/quicktime");
  dict[7].key("pdf")  ; dict[7].value("application/pdf");
  dict[8].key("txt")  ; dict[8].value("text/plain");
  dict[9].key("xls")  ; dict[9].value("application/vnd.ms-excel");
}

/*
** fill dynamic vector using heap memory
*/
void addMonths( vector<Association <int> *>& months)
{
  // use enum type, with array for days in month data
  enum mon { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
  int days[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  months.push_back( new Association <int>(days[jan], "January") );
  months.push_back( new Association <int>(days[feb], "February") );
  months.push_back( new Association <int>(days[mar], "March") );
  months.push_back( new Association <int>(days[apr], "April") );
  months.push_back( new Association <int>(days[may], "May") );
  months.push_back( new Association <int>(days[jun], "June") );
  months.push_back( new Association <int>(days[jul], "July") );
  months.push_back( new Association <int>(days[aug], "August") );
  months.push_back( new Association <int>(days[sep], "September") );
  months.push_back( new Association <int>(days[oct], "October") );
  months.push_back( new Association <int>(days[nov], "November") );
  months.push_back( new Association <int>(days[dec], "December") );
}

// delete dynamic memory allocated in 'addMonths'
void cleanup( vector<Association <int> *>& months) 
{
  // cleanup heap
  for(int i = 0 ; i < months.size() ; ++i) {
    delete months[i];
  }
  months.clear();
}

/*
** using vector iterator search in dictionary for key, return
** index for found value,
** otherwise throw Exception
*/
int atKey(vector< Association <string> >& dict, string k)
{
  // create vector iterator
  vector<Association <string> >::iterator iter1 = dict.begin();
  int idx=0; // indexer
  while( iter1 != dict.end() ) {
    string the_key = (*iter1).key();
    if( the_key == k ) {
      return idx; //return index into vector for found key
    }
    idx++; // increase index
    iter1++; // next element
  }
  // if arrives here then key has not been found, return exception
  throw( NotFoundException(k) );
}
