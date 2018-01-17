#include "scoretablecell.h"

ScoreTableCell::ScoreTableCell(int pos, int x, int y, Player *player1, Player* player2, Turn* turn, CountScore* count)
{
    this->position = pos;

    this->count = count;

    this->pos.x = x;
    this->pos.y = y;
    this->pos.w = 90;
    this->pos.h = 30;

    this->player1 = player1;
    this->player2 = player2;

    this->turn = turn;
}

void ScoreTableCell::click()
{

    if (this->turn->getTurnCount() % 2 == 1 && this->player1->getScoreTable(this->position) == -1) {
        int val = count->countScore(this->position);

        if (val > -1) {
            this->player1->setScoreTable(this->position, val);
        }

        this->turn->increaseTurnCount();
    }

    else if (this->turn->getTurnCount() % 2 == 0 && this->player2->getScoreTable(this->position) == -1) {
        int val = count->countScore(this->position);

        if (val > -1) {
            this->player2->setScoreTable(this->position, val);
        }

        this->turn->increaseTurnCount();
    }
}
