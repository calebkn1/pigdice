
#include "Die.h"

#include <random> // Caleb Knickerbocker

Die::Die()
{
    m_dieValue=1;
    m_numOfSides=6;
}
int Die::getDieValue() const
{
    return m_dieValue;
}
int Die::getNumOfSides() const
{
    return m_numOfSides;
}
void Die::setNumOfSides(int numOfSides)
{
    if(numOfSides==4 || numOfSides==6 || numOfSides==8)
    {
        m_numOfSides=numOfSides;
    }
}
void Die::rollDie()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, m_numOfSides);
    m_dieValue=dis(gen);
}