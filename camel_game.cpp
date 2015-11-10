//Name: Coleman Johnston
//Name: Lesley Amezcua
//Date: Novermber 6, 2015
//Description: Camel Game

#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<ctime>


using namespace std;

void showMenu();

//******************************************************************************
void takeDrink(int& canteen, int& thirstyness);
//Summary: Changes the value of canteen and thirst when the user decides to take
//a drink.
//Precondition: Two type int arguments initialized to a value.
//postcondition: The first int will be decremented by one and the second will be
//set to zero.
//
//******************************************************************************
//

//******************************************************************************
void aheadModerateSpeed(int& miles, int& nativeMiles, int& thirstyness);
//Summary: Advances the values of the first, second, and third arguments.
//Precondition: Three type int arguments initialized to a value.
//Postcondition: The values of the arguments are changed. miles is advanced a 
//random amount between 7-12 inclusive. nativeMiles is advanced a random amount 
//between 7-14 inclusive. thirstyness is advanced by one.
//
//***********************************************************************
//
//******************************************************************************
void showstatus(int miles,int drinks, int nativeMiles);
//Summary: Shows the user their status in the game.
//Precondition: Takes in miles traveled by the user, drinks drank, and miles the 
//native travels all in ints.
//Postcondition: Returns the number of miles the user traveled, the drinks the
//user has drank and the miles the natives have traveled. 
//
//***********************************************************************
//
//******************************************************************************
void stopForTheNight(int& camel, int& nativeMiles);
//Summary: User stops for the night and camel's tireness gets recalculated to 
//zero.
//Precondition: Takes in two arguments that are of type int and are 
//pass by reference.
//Postcondition: Returns to the screen that the camel is happy and resets the  
//camel tiredness to zero.
//
//***********************************************************************
//
//******************************************************************************
void aheadFullSpeed(int& camel, int& miles,int& nativeMiles, int& thirstyness);
//Summary: Advances the values of the all the arguments.
//Precondition: Four arguments of type int initialized to values.
//Postcondition: The values of the arguments are advanced. Camel is advanced by
//a random amount between 1-3 inclusive. miles is advanced a random amount
//between 10-20 inclusive. nativeMiles is advanced a random amount between 7-14
//inclusive. thirstyness is advanced by one.
//
//***********************************************************************
//
//******************************************************************************
void oasis(int& camel, int& thirstyness, int& canteen);
//Summary: Has a random chance of resetting all arguments to the same as they 
//were in the beginning of the game.
//Precondition: Takes in three arguments of type int.
//Postcondition: Randomly (1 in twenty chance) sets camel, and thirstyness to 
//0, and canteen to 3.
//
//***********************************************************************
//
//******************************************************************************
void specialEvent(int& nativeMiles, bool& isStillGoing);
//Summary: Based on a random number a tragic event happens to try to make the 
//user lose the game.
//Precondition: Takes in two arguments, one is of type int and the other is
//bool, both are pass by reference.
//Postcondition: Returns to the screen the tragic event that happens while the 
//user is playing the game.
//
//***********************************************************************

int main()
{
    srand(time(0));
    char action;//takes in user input
    bool isplaying = true;//bool to run the loop
    int milesTraveled = 0;//miles traveled by the user's character
    int thirst = 0;//variable to keep track of thirst
    int camelTiredness = 0;
    int nativesTraveled = -20;//start the natives 20 miles behind the user
    int drinksInCanteen = 3;//start drinks in canteen at 3
    int fullSpdCount = 0;//count the number of times the user selects full speed to judge if a special event should happen        
    cout << "Welcome to Camel!" << endl
         << "You have stolen a camel to make your way across the great Mobi desert." << endl
         << "The natives want their camel back and are chasing you down! Survive your" << endl
         << "desert trek and outrun the natives." << endl << endl;
    
    while(isplaying)//start of while loop
    {
        showMenu();
        cin >> action;
        action = toupper(action);
    
        switch(action)//start switch
        {
            case 'A':
                takeDrink(drinksInCanteen,thirst);
                break;
            case 'B':
                aheadModerateSpeed(milesTraveled, nativesTraveled, thirst);
                oasis(camelTiredness, thirst, drinksInCanteen);//calls oasis function
                break;
            case 'C':
                aheadFullSpeed(camelTiredness, milesTraveled,nativesTraveled, thirst);
                fullSpdCount++;
                oasis(camelTiredness, thirst, drinksInCanteen);//calls oasis function
                break;
            case 'D':
                stopForTheNight(camelTiredness, nativesTraveled);
                break;
            case 'E':
                showstatus(milesTraveled,drinksInCanteen,nativesTraveled);
                break;
            case 'Q':
                isplaying = false;//quits game
                break;
            default:
                cout << "Invalid input please try again.\n";
                continue;
        }//end switch
        
        if(milesTraveled > 199)
        {
            cout << "You have made your way to safety!\n";
            cout << "You win!!!\n";
            isplaying = false;
            break;
        }
        
        if (fullSpdCount == 3)
        {
            specialEvent(nativesTraveled,isplaying);
            fullSpdCount = 0;
            if (isplaying == false)
            {
                break;
            }
        }
        
        if(thirst > 6)
        {
            cout << "You died of thirst.\n";
            isplaying = false;
        }
        else if(thirst > 4)
        {
            cout << "You are thirsty.\n";
        }
        
        
        if(camelTiredness > 8)
        {
            cout << "Your camel is dead.\n";
            cout << "You lose\n";
            isplaying = false;
        }
        else if(camelTiredness > 6)
        {
            cout << "Your camel is getting tired.\n";
        }
        
        if(nativesTraveled >= milesTraveled)
        {
            cout << "The natives have caught you. You, my friend, have died.\n";
            isplaying = false;
        }
        else if(milesTraveled - nativesTraveled < 15)
        {
            cout << "Watch out! The natives are getting close.\n";
        }
        
    }//end while  
    cout << "Thank you for playing!!!\n";
    return 0;
}//end main

void showMenu()
{
    cout << "Please Choose one:" << endl << endl
         << "A. Drink from your canteen." << endl
         << "B. Ahead moderate speed." << endl
         << "C. Ahead full speed." << endl
         << "D. Stop for the night." << endl
         << "E. Status check." << endl
         << "Q. Quit." << endl;
    return;
}

void takeDrink(int& canteen, int& thirstyness)
{
    if(canteen > 0)
    {
    canteen--;    
    thirstyness = 0;
    cout << "ahhh, very refreshing.\n";
    }
    else
    {
        cout << "You have nothing but sand left inside your canteen.\n";
    }
    return;
}

void aheadModerateSpeed(int& miles, int& nativeMiles, int& thirstyness)
{
    miles += rand() % 6 + 7;
    cout << "Miles Traveled: " << miles << endl;
    nativeMiles += rand() % 8 + 7;
    thirstyness++;
    return;
}

void aheadFullSpeed(int& camel, int& miles, int& nativeMiles, int& thirstyness)
{
    miles += rand() % 11 + 10;
    cout << "Miles Traveled: " << miles << endl;
    nativeMiles += rand() % 8 + 7;
    camel += rand() % 3 + 1;
    thirstyness++;
    return;
}

void stopForTheNight(int& camel, int& nativeMiles)
{
    camel = 0;
    nativeMiles += rand() % 8 + 7;
    cout << "Your camel is happy 8-D\n";
    return;
}

void showstatus(int miles,int drinks, int nativeMiles)
{
    cout << "Miles traveled: " << miles << endl;
    cout << "Drinks in canteen: " << drinks << endl;
    cout << "The natives are " << (miles - nativeMiles) << " miles behind you.\n"; 
    return;   
}

void oasis(int& camel, int& thirstyness, int& canteen)
{
    if((rand() % 20) == 0)
    {
        camel = 0;
        thirstyness = 0;
        canteen = 3;
        cout << "Congatulations, you found an oasis.\n" 
             << "You are no longer thirsty, your canteen is full,\n"
             << "and your camel got to eat a snack!\n";
    }
    return;
}
void specialEvent(int& nativeMiles, bool& isStillGoing)
{
    int randNum = rand() % 4 + 1; 
    
    if(randNum == 1)
    {
        cout << "Oh no! you've been caught in a sandstorm!\n";
        nativeMiles += rand() % 6 + 5;
    }
    if(randNum == 2)
    {
        cout << "Your camel just got stung by a scorpion! Stop and rest.\n";
        nativeMiles += rand() % 6 + 5;
    }
    if(randNum == 3)
    {
        cout << "Quick just like quicksand! Try to get out before the natives get you!\n";
        nativeMiles += rand() % 6 + 5;
    }
    if(randNum == 4)
    {
        cout << "You've been attacked by mummies and they ate your brain!\n";
        isStillGoing = false;
        
    }
    return;
}