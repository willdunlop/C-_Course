#include "FBullCowGame.h"

/** Constructor */
FBullCowGame::FBullCowGame()
{
   Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

void FBullCowGame::Reset() 
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;

    return;
}

bool FBullCowGame::CheckGuesValidity(FString) 
{
    return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    //incriment the turn number
    MyCurrentTry++;
    // setup a return variable
    FBullCowCount BullCowCount;

    // loop through all letters in guess
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 i = 0; i < HiddenWordLength; i++) 
    {
        if(Guess[i] == MyHiddenWord[i]) BullCowCount.Bulls++;
        for (int32 j = 0; j < HiddenWordLength; j++)
        {
            if(Guess[i] == MyHiddenWord[j]) BullCowCount.Cows++;
        }
    }
    // compare letters against the hidden word

    return BullCowCount;
}