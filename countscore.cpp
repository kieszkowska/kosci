#include "countscore.h"


CountScore::CountScore(Dices *dices)
{
    this->dices = dices;
}

int CountScore::countScore(int cell)
{
    for (int i = 0; i < 5; i++) {
        this->tab[i] = dices->getDicePointer(i);
        this->valTab[i] = this->tab[i]->getValue();
    }
    std::sort(this->valTab, this->valTab + 5);

    this->valTabUnique[0] = this->valTab[0];
    for (int i = 1; i < 5; i++) {
        if (this->valTab[i] != this->valTabUnique[i - 1]) {
            this->valTabUnique[i] = this->valTab[i];
        }
        else {
            this->valTabUnique[i] = 0;
        }
    }
    std::sort(this->valTabUnique, this->valTabUnique + 5);


    int sum = 0;
    switch (cell) {
    case 0:
        for (int i = 0; i < 5; i++) {
            if (this->valTab[i] == 1) {
                sum += 1;
            }
        }
        return sum;

    case 1:
        for (int i = 0; i < 5; i++) {
            if (this->valTab[i] == 2) {
                sum += 2;
            }
        }
        return sum;

    case 2:
        for (int i = 0; i < 5; i++) {
            if (this->valTab[i] == 3) {
                sum += 3;
            }
        }
        return sum;

    case 3:
        for (int i = 0; i < 5; i++) {
            if (this->valTab[i] == 4) {
                sum += 4;
            }
        }
        return sum;

    case 4:
        for (int i = 0; i < 5; i++) {
            if (this->valTab[i] == 5) {
                sum += 5;
            }
        }
        return sum;

    case 5:
        for (int i = 0; i < 5; i++) {
            if (this->valTab[i] == 6) {
                sum += 6;
            }
        }
        return sum;

    case 7:
        for (int i = 0; i < 3; i++) {
            if (this->valTab[i] == this->valTab[i + 1] && this->valTab[i] == this->valTab[i + 2]) {
                for (int j = 0; j < 5; j++) {
                    sum += valTab[j];
                }
                return sum;
            }
        }
        return 0;

    case 8:
        for (int i = 0; i < 2; i++) {
            if (this->valTab[i] == this->valTab[i + 1] && this->valTab[i] == this->valTab[i + 2] && this->valTab[i] == this->valTab[i + 3]) {
                for (int j = 0; j < 5; j++) {
                    sum += valTab[j];
                }
                return sum;
            }
        }
        return 0;

    case 9:
        if (this->valTab[0] == this->valTab[1] && this->valTab[2] == this->valTab[3] && this->valTab[2] == this->valTab[4]) {
            return 25;
        }
        if (this->valTab[0] == this->valTab[1] && this->valTab[0] == this->valTab[3] && this->valTab[3] == this->valTab[4]) {
            return 25;
        }
        return 0;

    case 10:
        for (int i = 0; i < 2; i++) {
            if (this->valTabUnique[i] != 0 &&
                    this->valTabUnique[i] == valTabUnique[i + 1] - 1 &&
                    this->valTabUnique[i] == valTabUnique[i + 2] - 2 &&
                    this->valTabUnique[i] == valTabUnique[i + 3] - 3) {
                return 30;
            }
        }
        return 0;

    case 11:
        if (this->valTabUnique[0] != 0 &&
                this->valTabUnique[0] == this->valTabUnique[1] - 1 &&
                this->valTabUnique[0] == this->valTabUnique[2] - 2 &&
                this->valTabUnique[0] == this->valTabUnique[3] - 3  &&
                this->valTabUnique[0] == this->valTabUnique[4] - 4) {
            return 40;
        }
        return 0;

    case 12:
        if (this->valTab[0] == this->valTab[1] &&
                this->valTab[0] == this->valTab[2] &&
                this->valTab[0] == this->valTab[3] &&
                this->valTab[0] == this->valTab[4]) {
            return 50;
        }
        return 0;

    case 13:
        for (int i = 0; i < 5; i++) {
            sum += this->valTab[i];
        }
        return sum;
    }

    return -1;
}
