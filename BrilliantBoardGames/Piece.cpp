//
//  Piece.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Piece.h"

// Initializes a new piece with no position and no type
Piece::Piece() {
    
}

// Initializes a new piece with a fixed position and type
Piece::Piece( int row, int col, char type ) : row_( row ), col_( col ), type_( type ) {
}

// returns the position of the piece
std::pair<int, int> Piece::get_piece_pos() {
    return std::make_pair( row_, col_ );
}

// Returns the type of the piece
char Piece::get_type() {
    return type_;
}

// Returns which row the piece is in on the board
int Piece::get_row( ) {
    return row_;
}

// Return which column the piece is in on the board
int Piece::get_col( ) {
    return col_;
}

// Changes position of the piece
void Piece::set_pos( int dest_row, int dest_col ) {
    row_ = dest_row;
    col_ = dest_col;
}

bool Piece::legal_move( int dest_row, int dest_col ) {
    return true;
}
