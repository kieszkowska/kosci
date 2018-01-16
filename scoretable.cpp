#include "scoretable.h"

ScoreTable::ScoreTable(Player *player1, Player *player2, SDL_Renderer *ren, WriteText *writer, Dices *dices)
{
    this->player1 = player1;
    this->player2 = player2;
    this->ren = ren;
    this->writer = writer;
    this->dices = dices;

    this->counter = new CountScore(this->dices);

    for (int i = 0; i < 5; i++) {
        this->tab[i] = this->dices->getDicePointer(i);
    }
}

ScoreTable::~ScoreTable()
{
    delete this->counter;
}

void ScoreTable::write()
{
    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
    for (int i = 0; i < 14; i++) {
        if (i != 6) {
            pos.y = 55 + (i * 30);
            if (this->player1->getScoreTable(i) > -1) {
                pos.x = 110;
                this->writer->write(std::to_string(this->player1->getScoreTable(i)).c_str(), pos);
            } else {
                pos.x = 110;
                this->writer->writeSecondary(std::to_string(this->counter->countScore(i)).c_str(), pos);
            }

            pos.y = 55 + (i * 30);
            if (this->player2->getScoreTable(i) > -1) {
                pos.x = 200;
                this->writer->write(std::to_string(this->player2->getScoreTable(i)).c_str(), pos);
            } else {
                pos.x = 200;
                this->writer->writeSecondary(std::to_string(this->counter->countScore(i)).c_str(), pos);
            }
        }
    }

    int sumTop1 = 0, sumTop2 = 0, sum1 = 0, sum2 = 0;

    for (int i = 0; i < 7; i++) {
        if (this->player1->getScoreTable(i) > -1) {
            sumTop1 += this->player1->getScoreTable(i);
        }
        if (this->player2->getScoreTable(i) > -1) {
            sumTop2 += this->player2->getScoreTable(i);
        }
    }

    pos.y = 235;
    pos.x = 110;

    this->writer->write(std::to_string(sumTop1).c_str(), pos);

    pos.x = 200;

    this->writer->write(std::to_string(sumTop2).c_str(), pos);

    sum1 = sumTop1;
    sum2 = sumTop2;

    for (int i = 7; i < 14; i++) {
        if (this->player1->getScoreTable(i) > -1) {
            sum1 += this->player1->getScoreTable(i);
        }
        if (this->player2->getScoreTable(i) > -1) {
            sum2 += this->player2->getScoreTable(i);
        }
    }

    pos.y = 475;
    pos.x = 110;

    this->writer->write(std::to_string(sum1).c_str(), pos);

    pos.x = 200;

    this->writer->write(std::to_string(sum2).c_str(), pos);

    pos.x = 713;
    pos.y = 70;

    this->writer->write(std::to_string(this->player1->getScore()).c_str(), pos);

    pos.y = 122;

    this->writer->write(std::to_string(this->player2->getScore()).c_str(), pos);

}
