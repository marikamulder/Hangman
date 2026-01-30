// declare all used functions
char[] getAnswer();
char getGuess();
int checkAnswer(char, char[]);
int answerRevealed();
int noMoreGuesses();
void win();
void lose();


// main
int main(){

    int playing = true;

    // get answer
    char[] answer = getAnswer();

    while (playing == true){


        // get input
        char guess = getGuess();
        
        // check guess against answer
        checkAnswer(guess, answer);
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

    return;
}

// NOTE:  LATER FUNCTIONS MUST BE DECLARED AS THEY WERE USED IN MAIN

char[] getAnswer(){
    // get the answer
    char[] answer;
    return answer
}

char getGuess(){
    // get the guess
    char guess;
    return guess;
}


// check guess (and reveal letters if correct)
void checkAnswer(char guess, char[] answer){

    int correctGuess = false; // assume false

    // find the length of the string
    int answerLength = ((sizeof(answer) / sizeof(answer[0])) - 1); // -1 for ending null character
    

    for (int i = 0; i < answerLength; i++){
        if (guess == answer[i]){
            correctGuess = true // found in answer
            //revealLetters()  -- GUI for the answer needs to be implemented beforehand 
        }
    }

    if (correctGuess == false){ // not found in answer
        // incrementHangman() -- GUI for the hangman needs to be implemented beforehand
    }

    // finally, keep track of which letters were used
    char[] prevGuesses = " ";
    prevGuesses[0] = guess;

    return;
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
