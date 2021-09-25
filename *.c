/* OUTLINE:
    2 files: 1 for the restaurant bill program, 1 for the number guessing game.
    Each file contains main functions inside to avoid confusion of using many files for one program


    RESTAURANT BILL
    4 float variables: mealCost, tax, tip, and total
    4 double variables: salad = 9.95, soup = 4.55, sandwich = 13.25, pizza = 22.35
    Possibly some local variables to store user input and for bill calculations

    Structure:
    1) Use pseudorandom number generator to pick the meal
    2) Accept user input of tax and tip
    3) Calculate bill total
    4) Display mealCost, tax, tip, and total


    NUMBER GUESSING GAME
    Global int variable, randoNum, for holding randomly generated number
    maxNum file holds max number for guessing game (10 by default)

    
    1) printf different menu options
    2) Accept user input (1,2,3)
    If input = 1: start game
             = 2: Accept user input for new max number and save input to maxNum file UNLESS requested max num = negative or beyond max value an int can hold
             = 3: Print thank you message and end game

    3) Game:
        Only ONCE per game: Generate a number between 1 and number from maxNum
        If input = too low: Print message about low guess
                 = too high: Print message about high guess
                 = q: quit game and return to menu
                 = correct: print win message and return to menu
    
    For saving max number request:
    Save max number to a file, maxNum, and read file whenever program starts
        Overwrite saved number when a user wants to change max number
*/