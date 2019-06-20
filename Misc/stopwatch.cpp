
// This program is a basic timer which measures the time between to enter key strokes


#include <iostream>
#include <time.h>

using namespace std;

int main(){

    int second;  
    time_t start, end; // A special type coming from time.h.
    // Number of seconds elapsed since Jan 1, 1980
    
    
    cout<<"Stopwatch"<<endl;
    cout<<"Press enter to start"<<endl;
    getchar();
    time(&start);// Get the time value
    cout<<"Press enter to stop"<<endl;
    getchar();
    time(&end); // get the time value at the moment
    second=end-start;
    cout<<"Time elapsed: "<<second<<" seconds "<<endl;
    // cout<<"Time finish: "<<end<<" seconds "<<endl;
    
        return 0;
}
