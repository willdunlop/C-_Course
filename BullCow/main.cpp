/**
 * Compile command
 *      g++  main.cpp FBullCowGame.cpp -std=c++11 -o main
 */

#include <iostream>     /** FN.1 */
#include <string>       /** FN.2 */
#include "FBullCowGame.h"


// using namespace std;    /** FN.3 */

/** These are aliases for the sake of looking like UE code*/
using FText = std::string;
using int32 = int;

/** These declerations can be plaice in a header file, main.h. Then simply include it */
void PrintIntro();      /** FN.5.1 */
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

/** The entry point of our application */
int main()
{
    PrintIntro();
    bool bPlayAgain = false;
    do { 
        PlayGame(); 
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);

    return 0;       //  Exit the application
}

/** Type is void because it returns nothing */
void PrintIntro()       /** FN.5.2 */
{
    std::cout << std::endl;
    std::cout << "\e[33m#################################\n";
    std::cout << "### Welcome to Bulls and Cows ###\n";  // You could also write `std::cout << "our FText" << std::endl`, std::endl being a method of std that quite literally ends the line
    std::cout << "#################################\e[0m\n";
    std::cout << std::endl;
    std::cout << "\e[37mCan you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\e[0m\n";
    std::cout << std::endl;

    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();

    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText UserGuess = GetValidGuess();

        // if (Status)
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(UserGuess);
        // std::cout << "Your guess was: " << "\'" << UserGuess << "\'" << std::endl;
        std::cout << "\e[37mBulls = " << BullCowCount.Bulls;
        std::cout << ", Cows = " << BullCowCount.Cows << "\e[0m" << std::endl;
    }
    std::cout << std::endl;
    PrintGameSummary();
    return;
}

FText GetValidGuess()
{
    EGuessValidity Status = EGuessValidity::Invalid_Status;
    FText Guess = "";
    int32 ValidGuessAttempts = 0;
    do 
    {
        int32 CurrentTry = BCGame.GetCurrentTry();
        int32 MaxTries = BCGame.GetMaxTries();
        std::cout << std::endl;
        std::cout << "\e[36mAttempt " << CurrentTry << "/" << MaxTries << ": " << "Enter your guess: \e[0m";
        std::getline(std::cin, Guess);
        Guess = BCGame.EnforceLowerCase(Guess);  //  Enforce lowercase character
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessValidity::Wrong_Length:
                std::cout << "\e[31mWRONG LENGTH!\e[37m Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\e[0m\n";
                break;
            case EGuessValidity::Not_Iso:
                std::cout << "\e[31mNOT AN ISOGRAM!\e[37m Please enter a word with no repeating letters\e[0m\n";
                break;
            default:
                break;
        }
        ValidGuessAttempts++;
        if (ValidGuessAttempts == 5) std::cout << "\e[35mCome on my guy, it's not that hard\e[0m\n";
        if (ValidGuessAttempts == 10) std::cout << "\e[35mYo wtf are you doing?\e[0m\n";
        if (ValidGuessAttempts == 15) std::cout << "\e[35mYou're on your own, I can't help you\e[0m\n";
    } while (Status != EGuessValidity::OK); // Keep looping until a valid guess is submitted

    return Guess; // Status is OK, returning Guess
}

bool AskToPlayAgain()
{
    std::cout << "Would you like to play again? [Y/N]";
    FText Response = "";
    std::getline(std::cin, Response);

        
    if ((Response[0] == 'y') || (Response[0] == 'Y'))
    {
        BCGame.Reset();
        return true;
    } else {
        return false;
    }
}

void PrintGameSummary()
{
    if (BCGame.IsGameWon()) std::cout << "\e[33mYou Won\e[37m Congratulations!!\n";
    else std::cout << "\e[31mGame Over\e[37m You ran out of guesses, better luck next time\n";
    return;
}

/**
 * #################################
 * ######     FOOT NOTES      ######
 * #################################
 * 
 * FN.1
 * '#' is known as a pre-processor directive, something that happens at build
 * '#include' is pretty much the same as ES6 'import' 
 * <iostream> is the file being included, in this case, the chevron brakets 
 * indicate a C++ standard library
 * 
 * FN.2
 * I did not require the <string> library fro the use of `>>` like the guide indicated
 * This is because my system has <string> within the std namespace of <iostream>.
 * Although this works for me, it will not be the case for everyone, so including is still
 * good practice
 * 
 * FN.3
 * std is a namespace that comes from iostream
 * a namepsace is quite literally a space for names.
 * the '::' allows access into this namespace to then select 
 * the method we need to use, in this case, cout. The '<<' 
 * takes the string on the right and pushes it into the module 
 * in order for cout to use it. thus we get 'std::cout'
 * 
 * Althoug the tutorial started out with this approach, he later decided it was best to
 * not really use it at all due to the complications it can cause. He believes its better
 * to just always be explicit and use the `std::method` syntax
 * 
 * By 'using' a namespace, we remove the need to prefix its functions with `std::`
 * this is much like in ES6 were we could relate it to the shorthand `const { cout } = std`
 * only cout does not need to be defined. More like {...std} maybe. This is good for writing 
 * tidy and verbose code, however, using another namespace alongside this could pose the risk
 * of conflicting methods if a `cout` method exist in both.
 * I imagine it is perhaps best to only 'use' one key namespace and any other namespaces will
 * remain un expanded and require the `::` syntax to access its methods
 * 
 * 
 * FN.4
 * It's type is integer {int},
 * it is specified as a constant expression {constexpr}[similar to const],
 * its defined as WORD_LENGTH,
 * its value is 5;
 * 
 * FN.5.1
 * Define the PrintIntro function at the start so it can be referenced in main
 * FN.5.2
 * We can write the logic for PrintIntro after main so as to keep the main function at the top
 * of the file. Clean layout
 */