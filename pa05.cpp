/* Sample tester
 * We've included std::list below to show you how your types should behave.
 * You can use that for debugging.
 * Add the -g flag if you want to use GDB like we learned in lab this week.
 */

// Use this to test, but not for your actual program.
#include <list>

// This is yours 
#include "MyList.h"

int main()
{
    MyList<int> l;
    //std::list<int> l;
    
    // Make your hpp file with empty definitions other than your constructor
    // Build one function at a time, and only add one "test" line at a time to this file.
    // Uncomment and add lines below here 1 at a time.
    // This file is just an example, and may not behave as expected!
    // Test all your MyList functions here or in multiple mains (I suggest one function test per file)

    /*
    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    cout << l.front() << endl;
    l.front() = 33;
    cout << l.front() << endl;
    cout << l.back() << endl;

        cout << l.size() << endl;
    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    cout << l.front() << endl;
    cout << l.back() << endl;
    
    l.push_front(423);

    cout << l.front() << endl;
    
    MyList<int> sink;
    sink = l;
    cout << sink.front() << endl;
    cout << sink.back() << endl;
    
    l.insert(l.begin(), 3);
    l.insert(l.end(), 20);
    l.pop_front();
    l.reverse();

    int j = 0;
    for(auto i = 0; i < l.size(); i++)
    {
        cout << l.back() << endl;
        l.pop_back();
        j++;
    }
    */
    
    return 0;
}

