#include "MultiPlayer.h"
#include "PigDiceGame.h"
#include <iostream>
#include <string> // Caleb Knickerbocker

// Default constructor
MultiPlayer::MultiPlayer()
{
    m_gameOver=false;
}

// Runs the multiplayer game
void MultiPlayer::mPlayGame()
{
    int numberOfPlayers=0;
    int anonymousCount=0;

    std::cout<<"How many people are playing? ";
    std::cin>>numberOfPlayers;
    std::cin.ignore();

    if(numberOfPlayers<1)
    {
        std::cout<<"Invalid number of players."<<std::endl;
        return;
    }

    // Single-player game
    if(numberOfPlayers==1)
    {
        PigDiceGame singlePlayer;
        singlePlayer.playSinglePlayerGame();
        return;
    }

    // Gets each player's name
    for(int i=0; i<numberOfPlayers; i++)
    {
        std::string playerName;

        std::cout<<"Enter player "<<i+1<<"'s name: ";
        std::getline(std::cin,playerName);

        // Checks for a blank name
        bool blankName=true;

        for(int j=0; j<playerName.length(); j++)
        {
            if(playerName[j]!=' ' && playerName[j]!='\t')
            {
                blankName=false;
            }
        }

        if(blankName)
        {
            anonymousCount++;
            playerName="Anonymous Player " + std::to_string(anonymousCount);
        }

        m_players.push_back(PigDiceGameV2(playerName));
    }

    // Resets each player's parent game
    for(int i=0; i<numberOfPlayers; i++)
    {
        m_players[i].resetParentGame();
    }

    std::cout<<std::endl;
    m_players[0].displayRules();

    // Plays until a winner is found
    while(!m_gameOver)
    {
        for(int i=0; i<numberOfPlayers; i++)
        {
            m_players[i].playGame();

            std::cout<<std::endl;
            displayScoreBoard();
        }

        checkForWinner();
    }
}

// Displays each player's score
void MultiPlayer::displayScoreBoard()
{
    int numberOfPlayers=m_players.size();

    for(int i=0; i<numberOfPlayers; i++)
    {
        std::cout<<m_players[i].getPlayerName();
        std::cout<<" (Score:"<<m_players[i].getGameScore()<<") | ";
    }

    std::cout<<std::endl;
}

// Checks for a winner
void MultiPlayer::checkForWinner()
{
    int numberOfPlayers=m_players.size();
    int winner=-1;

    for(int i=0; i<numberOfPlayers; i++)
    {
        if(m_players[i].getGameScore()>=50)
        {
            if(winner==-1)
            {
                winner=i;
            }
            else if(m_players[i].getGameScore()>m_players[winner].getGameScore())
            {
                winner=i;
            }
        }
    }

    if(winner!=-1)
    {
        std::cout<<"\nCongratulations! "<<m_players[winner].getPlayerName();
        std::cout<<" you win with a score of "<<m_players[winner].getGameScore()<<std::endl;

        m_gameOver=true;
    }
}