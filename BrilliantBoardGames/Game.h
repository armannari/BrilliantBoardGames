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
    Game();
    Game( int num_rows, int num_cols, int player1_pieces, int player2_pieces );
    void print_board();
    void move_piece( std::string source, std::string destination );
    void retract();
    //virtual void end();
    virtual void fill_player1_pieces( Player* player, std::vector<Piece*> v );
    virtual void fill_player2_pieces( Player* player, std::vector<Piece*> v );
    virtual bool legal( Player* player, int source_row, int source_col, int dest_row, int dest_col );
    void toggle_debug_mode();
    virtual void get_all_legal_moves();
    virtual bool end_state();
    int get_curr_player();
    virtual ~Game();
    
protected:
    Player* player1;
    Player* player2;
    Board* board;
    int num_rows_;
    int num_cols_;
    int player1_pieces;
    int player2_pieces;
    std::vector<Player*> players;
    Player* curr_player;
    bool debug_mode_;
};

#endif /* Game_h */
