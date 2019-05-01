# BullCow Planning

1. How much planning?
2. Define emotional problem the game solves
3. Choose concept, rules and requirements
4. Start to think about architecture
5. Copy planning into code
6. Document now what may change later


## 2. Emotional Problems
- I want a mental challenge
- I want to feel smart
- I miss word puzzles
- I want to prove myself
- I want to challenge someone
- Etc


## 3. Concept and Rules
- This is a "guess the isogram" game.
- An isogram is a word with no repeating letters.
- The user has  limited number of guesses
- After each guess the computer outputs
    - Bull: A right letter in the right place
    - Cow: A right letter in the wrong place
- You win by guessing the word within the max amount of guesses

### Requirements
- What will the inputs be? in what format?
    - The user would input word guesses, they will be in a string format, words typed into the keyboard
- what will the outputs be?
    - A number of Bulls and Cows that depending on the letter placements of the word provided
- What tasks will the user be asked to do?
    - word guessing and adjusting
    - typing
- Any performance limits worth mentioning?
    - none that i can think of
- What assets do we need?
    - just code as far as I can tell
    - the ascii art as well

Tutorial specified requirements
- Plain text instructions for all interactions
- Code that helps the character make a valid guess
    - eg(All lowercase, isogram, right length)
- Code to check the number of bulls and cows in the guess, compared to hidden word.
- Code to keep track of the number of valid guesses.


### Possible Future Ideas - (The NO list)
This is useful for placing the bigger picture ideas that plan on being implemented in the future, but are out of scope for this version.
I need this in my planning life

Examples:
- Provide validation feedback on each keypress (eg. is the inout word still a valid isogram)
- Have a large dictionary of hidden words
- User selectable word length/difficulty
- Checking the user's guess is an actual word
- Providing a time limit for the guesses
- A hint system, spend a turn for a hint