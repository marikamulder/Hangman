// all necessary includes
#include <emscripten.h>


// declare all used functions
char* getAnswer();
char getGuess();
int checkAnswer(char, char[], int);
int answerRevealed();
int noMoreGuesses();
void win();
void lose();


// defines:
#define MAX_LENGTH 100 // as of yet does not allow for 100+ letter words
#define MAX_LETTERS 26 // max size prevGuesses can be (assumes english)

// main
int main(){

    int playing = true;

    // get answer
    char* answer = getAnswer();
    char prevGuesses[MAX_LETTERS];

    int answerLength = 0; // if 0, error case

    // dynamically check the length of the string
    for (int i = 0; i < MAX_LENGTH; i++){
        if (answer[i] == NULL){ // end of string
            answerLength = i;
            break;
        }
    }

    while (playing == true){


        // get input
        char guess = getGuess();
        if (guess == NULL){ 
            // error, try again
            continue;
        }


        // check guess against answer
        checkAnswer(guess, answer, answerLength);
        /* IF guess IN answer, reveal letters
         * ELSE, increment body hanged
         * FINALLY, cross out/list guessed letters
         */

        // if all letters in answer revealed, player wins
        if (answerRevealed()){
            win();
            playing = false;
        } else if (noMoreGuesses()){ // if out of guesses, player loses
            lose();
            playing = false;
        }
        // otherwise, continue playing
    }

    return 0;
}

// NOTE:  LATER FUNCTIONS MUST BE DECLARED AS THEY WERE USED IN MAIN

char* getAnswer(){
    // get the answer
    char answer[MAX_LENGTH]; // TODO: grab the answer

    return answer;
}

char getGuess(){
    // get the guess
    char guess; // TODO: implement I/O for the site

    int alreadyGuessed = false; //TODO:  check if they already guessed the letter

    if (alreadyGuessed){ // error
        return 0; // return the null char 
    }

    return guess;
}


// check guess (and reveal letters if correct)
int checkAnswer(char guess, char answer[], int answerLength){

    int correctGuess = false; // assume false


    for (int i = 0; i < answerLength; i++){
        if (guess == answer[i]){
            correctGuess = true; // found in answer
            //revealLetters()  -- GUI for the answer needs to be implemented beforehand 
        }
    }

    if (correctGuess == false){ // not found in answer
        // incrementHangman() -- GUI for the hangman needs to be implemented beforehand
    }

    return correctGuess;
}

int answerRevealed(){
    // check if the answer is fully revealed
    int fullyRevealed;
    if (fullyRevealed){
        // player found all letters, the answer is fully revealed
        return true;
    } else return false; // answer not yet revealed
}

int noMoreGuesses(){
    // get the number of guesses
    int guesses;
    if (guesses == 0){
        // no more guesses, player lost
        return true; 
    } else return false;
}

void win(){
    // player won!
    return;
}

void lose(){
    // player lost!
    return;
}
