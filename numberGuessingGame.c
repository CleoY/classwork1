#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int maxRandoNum = 10; //default value of max guessable number
int answer;

int menuOption;

int displayMenu();
int redirectUser();
int startGame();
int generateRandomNumber();
int changeMaxNumber();


int main(){
    printf("Welcome to the Number Guessing Game!\n");
    displayMenu();
    
    if(menuOption == 3)
        goto quit;
    
    quit:
    printf("Thank you for playing!");
    return 0;
}

int displayMenu(){
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");
    scanf("%d", &menuOption);
    redirectUser();
    return 0;
}

int redirectUser(){
    if(menuOption == 1){
        startGame();
    } else if (menuOption == 2){
        changeMaxNumber();
    } else if (menuOption != 3){
        printf("Not a valid menu option! Please input one of the following choices: \n");
        displayMenu();
    }
    return 0;
}

int startGame(){
    generateRandomNumber();
    int guess;
    char userInput[5];
    
    printf("Guess the random number! Or, type 'q' to quit the game.\n");
    printf("Your guess: ");
    scanf("%s", userInput);
    guess = atoi(userInput); //converts userInput to int (meant to account for a numeric guess and the 'q' command)
    /* atoi() returns 0 if there is no number in the given string, userInput.
        BUT 0 is a valid user guess.
        THEREFORE, we need to check WHY guess might be 0. 
        If guess is 0 because the user entered 'q', then quit the game.
        Else if guess is 0 because the user entered any non-number input (i.e. a random string), the input is INVALID.
    */

    while(guess > answer || guess < answer){
        if(guess == 0 && (strcmp(userInput, "q")==0)){ //if condition checks whether guess = 0 because the user inputted "q"
            printf("Now quitting guessing game.\n\n");
            goto quitGame;
        } else if (guess == 0 && (strcmp(userInput, "0") != 0)){ 
            /*else-if condition checks whether guess = 0 because the user inputted an invalid string (i.e. random characters).
                Otherwise, user simply inputted "0" as a (valid) guess and program continues to next if-else block.
            */
            printf("%s is not a valid input! Please guess a number or type 'q' to quit.\n", userInput);
            goto retypeInput;
        }
        if (guess > answer){
            printf("Your guess is too high! Please guess again: ");
        } else if (guess < answer){
            printf("Your guess is too low! Please guess again: ");
        }
        retypeInput:
        scanf("%s", userInput);
        guess = atoi(userInput);
    }
    
    printf("Congratulations, you guessed correctly! You will now return to the main menu.\n\n");
    
    quitGame:
    displayMenu();

    return 0;
}

int generateRandomNumber(){
    time_t t;
    srand((unsigned) time(&t));
    answer = (rand() % (maxRandoNum)) + 1; //lower bound of 1
    return 0;
}

int changeMaxNumber(){
    printf("Current maximum guessable number: %d\n", maxRandoNum);
    printf("Please enter a new maximum guessable number: ");
    scanf("%d", &maxRandoNum);
    while(maxRandoNum < 0 || maxRandoNum > RAND_MAX){
        printf("Error: not a valid input. New maximum number can not be negative or greater than %d\n", RAND_MAX);
        scanf("%d", &maxRandoNum);
    }
    menuOption = 0;
    displayMenu();
    return 0;
}