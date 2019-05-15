#include "FBullCowGame.h"

/** Constructor */
FBullCowGame::FBullCowGame()
{
   Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }


int32 FBullCowGame::GetMaxTries() const 
{ 
    TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16} };
    return WordLengthToMaxTries[MyHiddenWord.length()]; 
}

// bool FBullCowGame::IsIsogram(FString Guess) const 
// {
//     for (int32 i=0; i < Guess.length(); i++)
//     {   
//         for (int32 j=0; j < Guess.length(); j++) 
//         {
//             // if the letters are the same character, but not the same position
//             if (Guess[i] == Guess[j] && i != j) return false;
//         }
//     }
//     return true;
// };

bool FBullCowGame::IsIsogram(FString Guess) const
{
    TMap<char, bool> LetterSeen;
    for (auto Letter : Guess)   //  auto type instead of char. Lets the compiler decide what type it is
    {
        if (!LetterSeen[Letter]) { LetterSeen[Letter]=true; }
        else { return false; }
    }
    return true;
}

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    bIsGameWon = false;

    return;
}

EGuessValidity FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (Guess.length() != GetHiddenWordLength()) 
        return EGuessValidity::Wrong_Length;
    else if (!IsIsogram(Guess)) return EGuessValidity::Not_Iso;
    // else if (!IsLowerCase(Guess)) return EGuessValidity::Not_Lowercase;
    else return EGuessValidity::OK; //    TODO: Complet this function
}

FString FBullCowGame::EnforceLowerCase(FString Guess) const
{
    for (int32 i=0; i < Guess.length(); i++)
        if (!std::islower(Guess[i])) Guess[i] = std::tolower(Guess[i]);

    return Guess;
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 HiddenWordLength = FBullCowGame::GetHiddenWordLength();
    // loop through all letters in guess
    for (int32 i = 0; i < HiddenWordLength; i++)
    {
        if(Guess[i] == MyHiddenWord[i]) BullCowCount.Bulls++;
        else {
            for (int32 j = 0; j < HiddenWordLength; j++)
                if(Guess[i] == MyHiddenWord[j]) BullCowCount.Cows++;
        }
    }

    if (BullCowCount.Bulls == HiddenWordLength) bIsGameWon = true;
    else bIsGameWon = false;
    return BullCowCount;
}

