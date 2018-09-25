//
// Created by Joshua Sutton
// 10/09/2018.
//

#include <iostream>

#include "../include/DefensiveMage.h"

using namespace std;

int main()
{
    DefensiveMage a1("Josh", 10, 0, false, 19);
    DefensiveMage a2;

    int freeGold = 0;

    bool loop = true;
    while(loop)
    {
        a1.closeAttack(a2);
        if(a2.getHealth() <= 0)
        {
            freeGold += a1.kill(a2);
            loop = false;
        }
        hour++;
    }

    return 0;
}
