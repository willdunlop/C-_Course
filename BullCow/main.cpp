/**
 * 
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
FText GetGuess();
bool AskToPlayAgain();
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
    int32 constexpr WORD_LENGTH = 5;          /** FN.4 */
    std::cout << std::endl;
    std::cout << "#################################\n";
    std::cout << "### Welcome to Bulls and Cows ###\n";  // You could also write `std::cout << "our FText" << std::endl`, std::endl being a method of std that quite literally ends the line
    std::cout << "#################################\n";
    std::cout << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;

    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();

    for (int32 count = 0; count < MaxTries; count++)
    {
        FText UserGuess = GetGuess();
        FBullCowCount BullCowCount = BCGame.SubmitGuess(UserGuess);
        // std::cout << "Your guess was: " << "\'" << UserGuess << "\'" << std::endl;
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ", Cows = " << BullCowCount.Cows << std::endl;

    }

    return;
}

FText GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << std::endl;
    std::cout << "Attempt " << CurrentTry << ": " << "Enter your guess: ";
    FText Guess = "";
    std::getline(std::cin, Guess);

    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Would you like to play again? [Y/n]";
    FText Response = "";
    std::getline(std::cin, Response);

        
    return (Response[0] == 'y') || (Response[0] == 'Y');
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