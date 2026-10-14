#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die
{
private:
    int m_dieValue;
    int m_numOfSides;

public:
    Die();
    int getDieValue() const;
    int getNumOfSides() const;
    void setNumOfSides(int numOfSides);
    void rollDie();
};

#endif