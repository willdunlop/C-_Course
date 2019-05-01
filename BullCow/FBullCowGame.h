#pragma once        //  Ensures this file is only imported once
#include <string>

using FString = std::string;
using int32 = int;

/**
 * struct is essentially a key=>value paired object type that can be
 * applied to a function or variable. A mini class but all members are 
 * public
 */ 
struct FBullCowCount 
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame(); //  constructor
    void Reset();
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    bool CheckGuesValidity(FString);

    FBullCowCount SubmitGuess(FString);


private:
    /** These can be reffered to as member variable */
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;

};

