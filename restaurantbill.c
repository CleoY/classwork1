#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum menu{salad, soup, sandwich, pizza};
enum menu mealType;

float mealPrices[] = {9.95, 4.55, 13.25, 22.35};

float tax, tip, mealCost, total;

int calculateTotal();
int randomMealGenerator();

int main(){
    printf("Welcome to the restaurant bill calculator!\n");
    
    randomMealGenerator();
    mealCost = mealPrices[mealType];

    printf("Please enter the tax rate for the meal: ");
    scanf("%f", &tax);
    while(tax < 0 || tax > 100){
        printf("Error: not a valid tax value. Please reenter the tax rate.\n");
        scanf("%f", &tax);
    }
    tax /= 100.0000; //obtain decimal version of tax

    printf("Please enter the tip rate for the meal: ");
    scanf("%f", &tip);
    while(tip < 0 || tip > 100){
        printf("Error: not a valid tip value. Please reenter the tip rate.\n");
        scanf("%f", &tip);
    }
    tip /= 100.0000; //obtain decimal version of tip

    calculateTotal();

    printf("Bill:\n");
    printf("Cost of meal: $%f\n", mealCost);
    printf("Tax: %f%%\n", tax*100.0);
    printf("Tip: %f%%\n", tip*100.0);
    printf("Total: $%f\n", total);

    return 0;
}

int calculateTotal(){
    total = mealCost + (mealCost*tip) + (mealCost*tax);
    return 0;
}

int randomMealGenerator(){
    time_t t;
    srand((unsigned) time(&t));
    mealType = rand() % 4;
    return 0;
}