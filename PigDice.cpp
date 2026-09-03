#include <iostream>
#include <cstdlib>
// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void display_rules() {
    std::cout <<"* Let's Play PIG Dice!" << std::endl;
    std::cout << std::endl;

    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score." << std::endl;
    std::cout << std::endl;

}

void roll (GameState & gs) {
    int die = rand() % 6+ 1;

    if (die ==1) {
        std::cout << "Die: 1" << std::endl;

        gs.score_this_turn = 0;
        gs.turn_over = true;

        std::cout << "Turn over. No score."<< std::endl;
    }
    else {
        gs.score_this_turn += die;

        std:: cout << "Die: " << die << " - Running score this turn: " << gs.score_this_turn << std::endl;
    }
}
void hold (GameState & gs) {
    gs.game_score += gs.score_this_turn;
    gs.turn_over = true;
}

void takeTurn (GameState & gs) {
    gs.turn_count += 1;
    gs.score_this_turn = 0;
    gs.turn_over = false;

    std::cout << "TURN" << gs.turn_count << " - Game Score: " << gs.game_score << std::endl;

    while (gs.turn_over == false) {

        std::cout << "roll or hold? (r/h): " ; std::cin >> gs.choice;
        if (gs.choice == 'r') {
            roll (gs);
        }
        else if (gs.choice == 'h') {
            hold (gs);
        }
    }
    std::cout << "Score Banked This Turn: " << gs.score_this_turn << std::endl;

    std::cout << std::endl;
}

void play_game (GameState & gs) {
    while (gs.game_over == false) {
        takeTurn (gs);
        if (gs.game_score >= 20) {
        gs.game_over = true;
        }
    }
    std::cout << "You finished with a final score of "<< gs.game_score << " in " << gs.turn_count << " turns!" << std::endl;
    std::cout << "Thanks for playing PIG Dice!" << std::endl;
}
int main() {
    GameState my_game; // instantiate a GameState object
     display_rules(); // call the display_rules function
     play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}