#include "turn.h"

Turn::Turn(Dices *dices)
{
    this->dices = dices;
}

void Turn::increaseTurnCount()
{
    this->turnCount++;
    this->rollCount = 1;
    this->dices->reset();
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

