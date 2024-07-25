// SBS_Study_BlackJack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "C_GAME.h"

int main()
{
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y')
    {
        C_GAME newGame{};
        newGame.initializeGame();
        newGame.playCurrentRound();

        std::cout << "게임을 다시 시작하시겠습니까? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "게임을 종료합니다." << std::endl;
    return 0;
}

