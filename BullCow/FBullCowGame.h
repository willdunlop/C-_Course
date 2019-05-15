#pragma once        //  Ensures this file is only imported once
#include <iostream>
#include <string>
#include <map>

#define TMap std::map


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

enum class EGuessValidity
{
    OK,
    Not_Iso,
    Wrong_Length,
    Invalid_Status,
};


class FBullCowGame {
public:
    FBullCowGame(); //  constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;

    // bool IsIsogram(FString) const;
    // bool IsLowerCase(FString) const;

    FString EnforceLowerCase(FString) const;

    EGuessValidity CheckGuessValidity(FString) const;

    FBullCowCount SubmitValidGuess(FString);

    void Reset();


private:
    /** These can be reffered to as member variable */
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool IsIsogram(FString) const;
    bool bIsGameWon;
};