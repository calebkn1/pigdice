#ifndef PIGDICE_PIGDICEGAMEV2_H
#define PIGDICE_PIGDICEGAMEV2_H

// Caleb Knickerbocker

#include "PigDiceGame.h"
#include <string>

class PigDiceGameV2 : public PigDiceGame
{
private:
    std::string m_playerName;

public:
    // Constructor
    PigDiceGameV2(std::string playerName);

    std::string getPlayerName() const;
    void displayRules();
    void playGame();
    void resetParentGame();
};

#endif