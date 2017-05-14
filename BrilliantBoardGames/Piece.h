//
//  Piece.hpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#ifndef Piece_h
#define Piece_h

#include <stdio.h>
#include <iostream>

class Piece {
    
public:
    Piece();
    Piece( int row, int col, char type );
    std::pair<int, int> get_piece_pos();
    char get_type( );
    int get_row( );
    int get_col( );
    void set_pos( int dest_row, int dest_col );
    virtual bool legal_move( int dest_row, int dest_col );
    
protected:
    int row_;
    int col_;
    char type_;
};

#endif /* Piece_h */
