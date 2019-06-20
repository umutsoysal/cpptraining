// This program is a learning tool for elementary multiplication from 1x1 to 12x12.


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

void CompareAndShowAnswer(int answer,int guess,int &CorrectAnswer)
{
    if (answer==guess){
        printf("You've got the right answer!\n");
        CorrectAnswer++;
    }
    else{
        printf("Wrong. The answer is %d\n", answer);
    }
}
void SetRandomSeedNumberFromTime(){

    int currentTime;
    currentTime=time(NULL);
    srand(currentTime);
}
int GenerateRandomNumber(void){
    int r;
    r=rand()%100+1;
    return r;
}
int main(){
    int counter,guess,answer,second;
    int row,column,MaxNumber,randomNumber,i,CorrectAnswer;
    int percentage;
    time_t start,end;
    printf("Flash Cards!");
    printf("How many cards you want to play with?");
    scanf("%d",&MaxNumber);

    while (MaxNumber<1 || MaxNumber >144){
        printf("The number of cards must be between 1 and 144\n");
        printf("How many cards you want to play with?:");
        scanf("%d",MaxNumber);
    }
    time(&start);
    CorrectAnswer=0;
    for (i=1;i<=MaxNumber;i++){
        SetRandomSeedNumberFromTime();
        randomNumber=GenerateRandomNumber();
        column=randomNumber/12+1;
        row=randomNumber%12+1;
        answer=row*column;
        printf("%d x %d:",row,column);
        scanf("%d",&guess);
        CompareAndShowAnswer(answer,guess,CorrectAnswer);
    }
    time(&end);
    second=end-start;
    percentage=(CorrectAnswer*100)/MaxNumber;
    printf("You answered %d questions in %d seconds",MaxNumber,second);
    printf("You answered %d problems correctly.(%d %%)\n",CorrectAnswer,percentage);
    return 0;   
}
