#ifndef PAIRS_HPP
#define PAIRS_HPP
#include <iostream>
#include <string>

using namespace std;

// TODO: implement the templated pairs class

//template<typename T1, typename T2> class pairs;


/****************************************** Declears ******************************************/
template <typename T1, typename T2>
class pairs
{
  public:
    pairs(){                                        // Defaule Constructor
      first_ = static_cast<T1>(0);
      second_ = static_cast<T2>(0);
    }
    pairs(T1 const& x, T2 const& y){                 // Pair input construce
      first_ = x;
      second_ = y;
    }

    pairs(pairs<T1,T2> const& pairsA){                     // Copy Constructor 

      first_ = pairsA.first_;
      second_ = pairsA.second_;
    }

    ~pairs(){}                                        // Destructor

    T1 get_first() const{                           // Get functions
     return first_;
    }  
    T2 get_second() const{
     return second_;
    }  

    void set_first(T1 const& x){                    // Set functions
      first_ = x;
    }
    void set_second(T2 const& y){
      second_ = y;
    }

    void print(){                                   // Print function 
      cout << *this << endl;
      }

  
    friend bool operator==(const pairs<T1,T2>& pairsA, const pairs<T1,T2>& pairsB){    // == overload for returning true/false
      if ((pairsA.get_first() == pairsB.get_first()) && (pairsA.get_second() == pairsB.get_second())){
        return true;
      }else{
        return false;
      }
    }
    friend bool operator!=(const pairs<T1,T2>& pairsA, const pairs<T1,T2>& pairsB){    // != overload for returning true/faule
      if ((pairsA.get_first() != pairsB.get_first()) && (pairsA.get_second() != pairsB.get_second())){
       return true;
      }else{
       return false;
      }
    }
    // output stream overload
    friend ostream& operator<<(ostream& os, const pairs<T1, T2>& pairsA){
      os << '(' << pairsA.get_first()<< ", " << pairsA.get_second() << ')';
      return os;
    }

  private:
    T1 first_;
    T2 second_;
};

/****************************************** Contents ******************************************/
// template <typename T1, typename T2>
// pairs<T1,T2>::pairs(const T1& x,const T2& y){       // Pair input construce
//   first_ = x;
//   second_ = y;
// }

// template <typename T1, typename T2>
// pairs<T1,T2>::pairs(const pairs& parisA){           // Copy Constructor 
//   first_ = parisA.first_;
//   second_ = parisA.second_;
// }

// template <typename T1, typename T2>
// T1 pairs<T1,T2>::get_first() const {                // Get functions
//   return first_;
// }  

// template <typename T1, typename T2>
// T2 pairs<T1,T2>::get_second() const {
//   return second_;
// }

// template <typename T1, typename T2>
// void pairs<T1,T2>::set_first(T1 const& x){           // Set functions
//   first_ = x;
// }     

// template <typename T1, typename T2>
// void pairs<T1,T2>::set_second(T2 const& y){
//   second_ = y;
// }

// template <typename T1, typename T2>                  // Print function
// void pairs<T1,T2>::print(){
//   cout << *this << endl;
// }


// // == overload for returning true/false
// template <typename T1, typename T2>
// bool pairs<T1,T2>::operator==(const pairs<T1,T2>& pairsA, const pairs<T1,T2>& pairsB){
//   if ((pairsA.get_first() == pairsB.get_first()) && (pairsA.get_second() == pairsB.get_second())){
//     return true;
//   }else{
//     return false;
//   }
// }
// // != overload for returning true/faule
// template <typename T1, typename T2>
// bool pairs<T1,T2>::operator!=(const pairs<T1,T2>& pairsA, const pairs<T1,T2>& pairsB){
//   if ((pairsA.get_first() != pairsB.get_first()) && (pairsA.get_second() != pairsB.get_second())){
//     return true;
//   }else{
//     return false;
//   }
// }
// // output stream overload
// template <typename T1, typename T2>
// ostream& operator<<(ostream& os, const pairs<T1, T2>& pairsA){
//   os << pairsA.get_first()<< ' ' << pairsA.get_second() << endl;
//   return os;
// }


#endif //PAIRS_HPP
