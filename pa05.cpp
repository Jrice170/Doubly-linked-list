/* Sample tester
 * We've included std::list below to show you how your types should behave.
 * You can use that for debugging.
 * Add the -g flag if you want to use gdb or cgdb
 */

// Use this to test, but not for your actual program.
#include <list>

// This is yours
#include "MyList.h"

template <typename T>
void sort(MyList<T> & list_object); // will sort a dubly linked list




int main()
{



    MyList<string> String_List;
    String_List.insert(0,"hhhh");
    MyList<int> un_ordered;
    un_ordered.insert(0,2);
    un_ordered.insert(1,5);
    un_ordered.insert(2,4);
    un_ordered.insert(3,9);
    un_ordered.Display_all();
    sort(un_ordered);
    un_ordered.Display_all();




}

template<typename T>
void sort(MyList<T> & list_object)
{

    int give_num = list_object.size();
    T array[give_num];
    for(int i = 0; i < give_num;i++)
    {


        array[i] = list_object.front();
        list_object.pop_front();


    }
    T Key;
    int i =0 ;

    for(int j = 1; j < give_num; j++)
    {

        Key = array[j];

        i = (j-1);
        while((i >= 0) && (array[i] > Key))
        {

              array[i+1] = array[i];
              i = (i - 1);
              array[i+1] = Key;

        }


    }

  
    list_object.clear();
    for(int i=0;i < give_num; i++)
    {

        list_object.insert(i,array[i]);



    }

}
