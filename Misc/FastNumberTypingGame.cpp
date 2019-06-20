// This game ask user to type the number printed on the screen. It counts n correct entry and give the total play time in seconds. n can be changed in line 9 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int number=5;

void CompareAndShowAnswer(int answer, int guess, int &counter){

    if(answer==guess) {
        counter++;
    }
    else{
        cout<<"Incorrect! Try again!"<<endl;
    }
}

void SetRandomSeedNumberFromTime()
{
    int currentTime;
    currentTime=time(NULL);
    srand(currentTime);
}
int GenerateRandomNumber(void)
{
    int r;
    r=rand()%1000+1;
    return r;
}

int main(){

    int counter=0;
    int second;
    time_t start,end;
    int speed;
    cout<<"Fast Number Typing Game"<<endl;
    time(&start);
    while(counter<number){
        int number,randomNumber;
        SetRandomSeedNumberFromTime();
        randomNumber=GenerateRandomNumber();
        cout<<"Type "<<randomNumber<<" : ";
        scanf("%d",&number);
        CompareAndShowAnswer(number,randomNumber,counter);
    }
    time(&end);
    second=end-start;
    speed=second/number;
    printf("Elapsed: %d numbers is %d seconds.\n",number,second);
    printf("Speed %d second per entry.\n",speed);
    return 0;

}
