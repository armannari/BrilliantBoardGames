//
//  Player.hpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 11/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include "Board.h"

class Player {
    
public:
    Player( int player_num, int num_pieces );
    int get_num_pieces();
    void fill_pieces( Piece* piece );
    void put_pieces_on_board( Board* board );
    void move_piece( int source_row, int source_col, int dest_row, int dest_col );
    int get_player_num();
    std::vector<Piece*> pieces;
    
    //~Player();
    
private:
    int player_num_;
    int num_pieces_;
    
};

#endif /* Player_h */
