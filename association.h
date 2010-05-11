#include <iostream>
#include <string>
#include <vector>

using namespace std;

// pre-processor directive
// #define DEBUG

/* *****
** TYPES
*  *****/

/*
** Association Class
** =================
** Association is mapping between a 'key' and 'value' pair for example
** in an Opposites dictionary:  'hot' -> 'cold', 'push' -> 'pull' etc.
** or in Partners dictionary: 'Tony' -> 'Cherie', 'Bill' -> 'Hilary' etc.
** or DaysInMonth dictionary 'February' -> 28
**
** Access is via the 'key' which returns the associated 'value'
** So key='Tony' returns value='Cherie'
** or key=28 returns 'February'
**
*/


/* Association class uses C++ Template class for key (as a generical type)
** e.g Integer or String, and Standard Template Library (STL) string as value
*/
template <class K> class Association { // template class Association using K
  /*
  ** member data items
  */
  K _key ;
  string _value ;
 public:
  /*
  ** build Association, with default constructor
  */
  Association() { 
#ifdef DEBUG
  cerr << "Association::Association()" << endl;
#endif
  }
  /*
  ** build Association, by providing both key and value
  */
  Association(K k, string v) { //
    key(k) ; value(v) ;
#ifdef DEBUG
  cerr << "Association::Association( " << k << "," << v << ")" << endl;
#endif
  }
  /*
  ** class destructor
  */
  ~Association() {
#ifdef DEBUG
  cerr << "Association::~Association()" << endl;
#endif
  }

  /*
  ** overload operator for output
  */
  friend ostream& operator<<(ostream& s,Association& a) {
    return s << "Association(" << a.key() << "," << a.value() << ")" << endl;
  }
  /*
  ** access functions - to set
  */
  void key(K key) { // set key, using 
    _key = key ; 
  }
  void value(string s) { // set value
    _value = s ; 
  }
  /*
  ** access functions - to get...(using constant functions)
  */
  string value() const { // get key
    return _value ; 
  }
  K key() const { 
    return _key ; // get value
  }
};


/*
** NotFoundException Class
** =======================
** A class used to flag a problem when a key is not in the dictionary
*/
class NotFoundException {
 public:
  NotFoundException(string t) { // constructor
    _data = t;
  }
  ~NotFoundException() {  } // empty destructor
  string data() const { return _data ; }
  friend ostream& operator<<(ostream& ost,NotFoundException& nfe){
    return ost << "NotFoundException(KEY: " << nfe.data() << " )" << endl;
  }
 private:
  string _data; 
};


/* make a new type, pointer to function, with no (void) return
** using Association<string> vector& parameter
*/
typedef void (*PTR_FUNC) (vector< Association <string> >&);



/* *******************
** Function Prototypes
** *******************/

/* fill vector of Association<int> pointers using dynamic memory */
void addMonths( vector<Association <int> *>& months);

/* cleanup dynamic vector data */
void cleanup( vector<Association <int> *>& months);

/* fill vector of Association<string> */
void addMimeTypes(vector< Association <string> >& dict);

/* find value, given key using Association Dictionary provide */
int atKey(vector< Association <string> >& dict, string k="doc") ;
