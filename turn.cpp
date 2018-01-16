#include "turn.h"

Turn::Turn()
{

}

void Turn::increaseTurnCount()
{
    this->turnCount++;
}

void Turn::increaseRollCount()
{
    this->rollCount++;
}

void Turn::resetTurnCount()
{
    this->turnCount = 1;
}

void Turn::resetRollCount()
{
    this->rollCount = 1;
}

int Turn::getTurnCount()
{
    return this->turnCount;
}

int Turn::getRollCount()
{
    return this->rollCount;
}

