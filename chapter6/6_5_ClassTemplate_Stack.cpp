#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

// http://www.tutorialspoint.com/cplusplus/cpp_templates.htm
// より転載。
// http://qiita.com/narumi888/items/f656678c78d50c40bc1c
// の用語をコメントで追記。

// 「クラステンプレート」：要素Tの型を格納できる一般的なスタッククラス
// 「テンプレートパラメータ」：templateキーワードの後に記載される名前。
// Tはこのスタックの例で指定されたテンプレートパラメータ
template <class T>
class Stack { 
  private: 
    vector<T> elems;     // elements 

  public: 
    void push(T const&);  // push element 
    void pop();               // pop element 
    T top() const;            // return top element 
    bool empty() const{       // return true if empty.
        return elems.empty(); 
    } 
}; 

template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // append copy of passed element 
    elems.push_back(elem);    
} 

template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // remove last element 
    elems.pop_back();         
} 

template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
	// return copy of last element 
    return elems.back();      
} 

int main() 
{ 
    try {
        // インスタンス化
        // 「テンプレート引数」：特殊化の過程でテンプレートパラメータと置き換わる実体。
        // Stack の場合、intがテンプレート引数。
        Stack<int>    intStack;      // stack of ints 
        Stack<string> stringStack;   // stack of strings 

        // manipulate int stack 
        intStack.push(7); 
        cout << intStack.top() <<endl; 

        // manipulate string stack 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}
