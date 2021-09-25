/* OUTLINE:
    2 files: 1 for the restaurant bill program, 1 for the number guessing game.
    Each file contains main functions inside to avoid confusion of using many files for one program


    RESTAURANT BILL
    4 float variables: mealCost, tax, tip, and total
    enum menu variable where each meal type is associated with a number
    mealPrices array with price for each meal (index of mealPrices matches enum menu numbers)

    Structure:
    1) Use pseudorandom number generator to pick the meal
    2) Accept user input of tax and tip
        Reject user input if the input is less than 0 or greater than 100 (tax/tips rates are never negative or more than 100%)
    3) Calculate bill total
    4) Display mealCost, tax, tip, and total


    NUMBER GUESSING GAME
    Global int variable, answer, for holding randomly generated number
    Global int variable, maxRandoNum, for holding max guessable number
    Global int variable, menuOption to track user's choice at menu

    1) printf different menu options
    2) Accept user input (1,2,3)
    If input = 1: start game
             = 2: Accept user input for new max number and save input to maxRandoNum UNLESS requested max num = negative or beyond max value an int can hold
             = 3: Print thank you message and end game and program

    3) Game:
        Only ONCE per game: Generate a number between 1 and number from maxNum
        If input = too low: Print message about low guess
                 = too high: Print message about high guess
                 = correct: print win message and return to menu
                 = q: quit game and return to menu (do NOT return menu)
                 = invalid: command user to retype guess
    

    For saving max number request on save_user_max_number branch:
    maxNum file holds max number for guessing game (10 by default)
    
    At game menu: if user input = 2, accept user input for a new max guessable number

    Save max number to a file, maxNum, and read file whenever program starts
        Overwrite saved number when a user wants to change max number
*/