//
//  Game.hpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>
#include "Player.h"
#include "Piece.h"
#include "Board.h"

class Game {
    
public:
    Game( int num_rows, int num_cols, int player1_pieces, int player2_pieces );
    void print_board();
    void move_piece( std::string source, std::string destination );
    void retract();
    //virtual void end();
    virtual ~Game();
    
private:
    Player* player1;
    Player* player2;
    Board* board;
    int num_rows_;
    int num_cols_;
    int player1_pieces;
    int player2_pieces;
    std::vector<Player*> players;
    Player* curr_player;
};

#endif /* Game_h */
