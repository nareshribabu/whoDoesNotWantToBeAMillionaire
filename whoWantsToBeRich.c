/*****************************************************************************
    Compiling the program
******************************************************************************
The program should be compiled using the following flags:
-std=c99
-Wall
compiling: gcc assn1.c -std=c99 -Wall -o assn1

******************************************************************************
    Running the Program
******************************************************************************
Running: ./assn1
******************************************************************************

Course name: CIS 1500
Student Name: Nareshri Babu
Username: nbabu
File name: babuNareshriA2.c
Last modified date: November 7, 2018

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle;
3)I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any
and all material (data, images, ideas or words) that I have used, whether
directly quoted or paraphrased. Furthermore, I certify that this assignment
was prepared by me specifically for this course.
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 7

//function prototypes

void promptPlayerForName (char [50]);
void printWelcomeMessage (char [50]);
int calculateCurrentAward (int, int);
void popUpCurrentQuestion4choices (int);
char askPlayerForLifeLine (void);
void popUpCurrentQuestion2choices (int);
char acceptPlayersFinalAnswer (void);
bool isCorrectFinalAnswer (char, int, char [MAX_QUESTIONS]);
void generateRandomGreeting (char [20]);
int calculateReducedAward (int, int);

int main() {

    char allCorrectAnswers [MAX_QUESTIONS + 1] = "CBCBACA"; //for my set of questions
    char greet [20];
    char nameForGame[50];
    int lifeLineUsed = 0;
    int questionNumber = 1;
    char playersResponseLifeLine;
    char finalAnswer;
    int currentAwardAmount;
    int reducedAmount;

    promptPlayerForName (nameForGame);

    printWelcomeMessage (nameForGame);

    while (questionNumber <= MAX_QUESTIONS) {

        currentAwardAmount = calculateCurrentAward (questionNumber, currentAwardAmount);

        popUpCurrentQuestion4choices (currentAwardAmount);

        if (lifeLineUsed == 0) {

            playersResponseLifeLine = askPlayerForLifeLine();

            if (playersResponseLifeLine == 'Y' || playersResponseLifeLine == 'y') {

                popUpCurrentQuestion2choices (currentAwardAmount);
                lifeLineUsed ++;
                printf("\nReminder - You get only 1 50-50 lifeline - and you are using it now \n\n");
            }
        }

        finalAnswer = acceptPlayersFinalAnswer ();

        if (isCorrectFinalAnswer (finalAnswer, questionNumber, allCorrectAnswers)) {

            generateRandomGreeting (greet);
            printf("%s - You just won $ %d\n", greet, currentAwardAmount);

            if (questionNumber < MAX_QUESTIONS) {

                printf("Let us play the next question now\n\n");

            }
        }

        else {

            printf("Oops - that was incorrect. ");

            reducedAmount = calculateReducedAward (questionNumber, currentAwardAmount);

            printf("You still won $ %d. Well done.\n\n", reducedAmount);

            questionNumber = MAX_QUESTIONS;

        }

        questionNumber ++;

    }

    printf("It was fun playing with you \n\n");

    return 0;

}


void promptPlayerForName (char fullName[50]) {

    //declare variable
    char name[50];

    //Ask for first name and last name
    printf("Enter your first name: ");
    scanf("%s", fullName);

    printf("Enter your last name: ");
    scanf("%s", name);

    //Put space in the middle
    strcat(fullName, " ");
    strcat(fullName, name);

    return;

}

void printWelcomeMessage (char fullName [50]) {

    //print first set of stars
    for(int i = 1; i <= 3; i++) {

        for(int j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    //print line of stars
    for(int i = 0; i <= strlen(fullName) + 8; i++) {
        printf("*");
    }

    //prints welcome message
    printf("\n");
    printf("Welcome %s \n", fullName);
    printf("Let us play WDWM!\n");

    //print line of stars
    for(int i= 0; i <= strlen(fullName) + 8; i++) {
        printf("*");
    }

    printf("\n");

    //prints last set of stars
    for(int i = 1; i <= 3; i++) {

        for(int j = 3; j >= i; j--) {
            printf("*");
        }

        printf("\n");
    }

    printf("\n");

    return;
}


int calculateCurrentAward (int questionNumber, int awardPreviousQuestion) {

    //declare variable
    int currentAward = 0;

    // calculate award based on question number
    if (questionNumber == 1) {
        currentAward = 100;
    }
    else if (questionNumber % 2 == 0){
        currentAward = awardPreviousQuestion * 5;
    }
    else {
        currentAward = awardPreviousQuestion * 2;
    }

    return currentAward;
}


void popUpCurrentQuestion4choices (int currentAwardAmount) {

    //create a switch statement based on the award amount (eg. 100 is Q1, 500 is Q2, etc)
    switch(currentAwardAmount) {
        case 100:
            printf("Here is the $ %d question: \n\n", currentAwardAmount);
            printf("Which of the following programming language is taught in CIS1500 at the University of Guelph?\n\n");
            printf("A. Python \t\t B. Cobra \nC. C \t\t\t D. Java\n\n");
            break;

        case 500:
            printf("Here is the $ %d question: \n\n", currentAwardAmount);
            printf("Which Canadian chain first opened in Hamilton in 1964?\n\n");
            printf("A. McDonalds \t\t B. Tim Hortons \nC. Wendys \t\t D. Mr. Sub\n\n");
            break;

        case 1000:
            printf("Here is the $ %d question: \n\n", currentAwardAmount);
            printf("What is Canada's national sport?\n\n");
            printf("A. Hockey \t\t B. Lacrosse \nC. Hockey and Lacrosse \t D. Baseball\n\n");
            break;

        case 5000:
            printf("Here is the $ %d question: \n\n", currentAwardAmount);
            printf("Which Canadian city ranks as the most educated in the country?\n\n");
            printf("A. Montreal \t\t B. Ottawa \nC. Vancouver \t\t D. Toronto\n\n");
            break;

        case 10000:
            printf("Here is the $ %d question: \n\n", currentAwardAmount);
            printf("What is Canada's highest mountain?\n\n");
            printf("A. Mount Logan, Yukon \t\t B. Whistler Mountain, BC \nC. Mont Tremblant, Quebec \t D. Tip Top Mountain, Ontario\n\n");
            break;

        case 50000:
            printf("Here is the $ %d question: \n\n", currentAwardAmount);
            printf("What is the easternmost province of Canada?\n\n");
            printf("A. Ontario \t\t B. Prince Edward Island \nC. Newfoundland \t D. Nova Scotia\n\n");
            break;

        case 100000:
            printf("Here is the $ %d question: \n\n", currentAwardAmount);
            printf("The southernmost point of mainland Canada is called Point Pelee. What province is it in?\n\n");
            printf("A. Ontario \t\t B. Quebec \nC. Newfoundland \t D. Nova Scotia\n\n");
            break;
    }

    return;
}


char askPlayerForLifeLine(void) {

    //declare variable
    char userAnswer;

    //Ask user if they want to use the lifeline
    printf("Would you like to use a lifeline (50-50)? \n");
    printf("Enter Y or y, N or n: ");
    scanf(" %c", &userAnswer);

    //loop if an invalid answer is entered
    while ((userAnswer != 'Y') && (userAnswer != 'y') && (userAnswer != 'N') && (userAnswer != 'n')) {

        printf("\nInvalid option entered\n\n");
        printf("Enter Y or y, N or n: ");
        scanf(" %c", &userAnswer);
    }

    return userAnswer;
}


void popUpCurrentQuestion2choices (int currentAwardAmount) {

    //create a switch statement based on the award amount subtracting 2 options
    switch(currentAwardAmount) {

        case 100:
            printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");
            printf("A. Python\nC. C\n");
            break;

        case 500:
            printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");
            printf("B. Tim Hortons\nC. Wendys\n");
            break;

        case 1000:
            printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");
            printf("A. Hockey\nC. Hockey and Lacrosse\n");
            break;

        case 5000:
            printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");
            printf("B. Ottawa\nD. Toronto\n");
            break;

        case 10000:
            printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");
            printf("A. Mount Logan, Yukon\nB. Whistler Mountain, BC\n");
            break;

        case 50000:
            printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");
            printf("C. Newfoundland\nD. Nova Scotia\n");
            break;

        case 100000:
            printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");
            printf("A. Ontario\nD. Nova Scotia\n");
            break;
    }

    return;

}


char acceptPlayersFinalAnswer (void) {

    //declare variable
    char finalAnswer;

    //Ask user to enter answer
    printf("Enter your FINAL ANSWER ('A', 'B', 'C', OR 'D') here: ");
    scanf(" %c", &finalAnswer);

    //Prompt user again if the answer entered is not A,B, C or D
    while ((finalAnswer != 'A') && (finalAnswer != 'B') && (finalAnswer != 'C') && (finalAnswer != 'D')) {
        printf("Enter your FINAL ANSWER ('A', 'B', 'C', OR 'D') here: ");
        scanf(" %c", &finalAnswer);
    }

    return finalAnswer;
}


bool isCorrectFinalAnswer (char finalAnswer, int questionNumber, char allCorrectAnswers[MAX_QUESTIONS]) {

    //declare variable
    bool returnVariable;

    //return true or false depending on if answer is true
    if (finalAnswer == allCorrectAnswers[questionNumber - 1]) {
        returnVariable = true;
    }
    else {
        returnVariable =  false;
    }

    return returnVariable;
}


void generateRandomGreeting (char greet[20]) {

    //declare variable
    int num;

    //seed using time
    srand((int)time(0));

    //rand function
    num = rand() % 5 + 1;

    //randomize greeting based on the random number between 1 and 5
    if (num == 1) {
        strcpy(greet, "\nBravo");
    }
    else if (num == 2) {
        strcpy(greet, "\nCongrats");
    }
    else if (num == 3) {
        strcpy(greet, "\nWell done");
    }
    else if (num == 4) {
        strcpy(greet, "\nVery nice");
    }
    else {
        strcpy(greet,"\nProud of you");
    }

    return;
}


int calculateReducedAward (int questionNumber, int currentAwardAmount) {

    //declare variable
    int reducedAward;
    reducedAward = 0;

    //calculate the reduced award when wrong answer is entered based on question number
    if (questionNumber == 1) {
        reducedAward = 0;
    }
    else if (questionNumber % 2 == 0) {
        reducedAward = currentAwardAmount / 5;
    }
    else {
        reducedAward = currentAwardAmount / 2;
    }

    return reducedAward;
}
