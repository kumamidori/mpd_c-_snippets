#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

// 図6.5 実装と構造を再利用し、振る舞いを再利用しないカプセル化

// T型を格納できるSetクラス
template <class T>
class Set
{ 
public:
    void add(const T&);
    T empty() const;
    void remove(const T&);
    bool exists(const T&) const;
    int size() const;
    // ・・・
private:
    list<T> theList;
};

// p.130あたりから。
// Set が List の振る舞いをそのまま再利用するのは、
// size() 演算だけ。そのほかに関しては、実装と構造のみを再利用。
// リストはソートできるので、ソートのできないSetの基底にはなりえない
// （Set には順序づけの概念がない）。
template <class T>
int Set<T>::size() const {
    return theList.size();
}

template <class T>
void Set<T>::add(T const& elem) {
  //      if(!exists(elem)) 
      theList.push_front(elem);
}



int main() 
{ 
    try {
        Set<int>    intSet;
	cout << intSet.size() <<endl; 
	intSet.add(7); 
	cout << intSet.size() <<endl; 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}
