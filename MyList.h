/* Clean and simple version of the doubly linked std::list
 * This is your h file. Do not edit it!
 * If you want to know what the functions do,
 * Read the links in the assignment description from en.cppreference.
 * Make sure to test your list with multiple types: (e.g., int, char, long, etc.)
 * Check both books to see which one has a similar implementation you can use as your guide!
 */ 

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

/* 
* Same username function!
*/
void get_identity(std::string &my_id);


template <typename T>
class Node
{
    public:
        T m_element;

        Node<T> *m_prev;
        Node<T> *m_next;

        // Helps you make a dummy node
        Node(Node<T> *in_prev, Node<T> *in_next): 
            m_prev(in_prev), m_next(in_next){}

        Node(const T &x, Node<T> *in_prev, Node<T> *in_next): 
            m_element(x), m_prev(in_prev), m_next(in_next){}
};


template <typename T>
class MyList
{
    private:
        Node<T> *m_sentinel = nullptr;

        int m_size;

    public:
        // Here is where you make your sentinel/dummy/junk node (just one!).
        // A list size of 0 will have 1 sentinel node.
        MyList();

        // Use removall from the class code as your guide!
        ~MyList();

        MyList<T> & operator=(const MyList<T> &source);

        MyList(const MyList<T> &source);

        T & front();

        T & back();

        void assign(int count, const T &value);

        // Default list size of 0, with one sentinel node, as above in constructor
        void clear();

        void push_front(const T &x);

        void push_back(const T &x);

        void pop_back();

        void pop_front();

        // Simplified version that only takes one int position.
        // Inserts before element at position i.
        // Not exactly like std::
        // You do NOT need a special case for 0-big lists (i.e., no if size == 0).
        void insert(int i, const T &x);

        // Removes all elements in list that are equal to value. 
        // You do NOT need a special case for 0-big lists (i.e., no if size == 0).
        void remove(T value);
        
        // Removes element at position i.
        void erase(int i);

        void reverse();

        bool empty();

        int size();

        // Mimicking C++ iterator trickery from here down. 
        // You don't need to edit these two.
        int begin()
        {
            return 0;
        }

        int end()
        {
            return size();
        }
};

#include "MyList.hpp"

#endif

