//
//  main.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Board.h"
#include "Game.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    Game game(8, 8, 16, 16);
    
    game.move_piece("A2", "A3");
    game.move_piece("B2", "B3");

    
    return 0;
}
