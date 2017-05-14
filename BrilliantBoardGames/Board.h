//
//  Board.hpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Piece.h"

class Board {
    
public:
    Board(int num_rows, int num_cols);
    
    int get_num_rows() const;
    int get_num_cols() const;
    
    char& operator()(const int& row, const int& col);
    const char& operator()(const int& row, const int& col) const;
    
    void place_piece (Piece* piece) ;
    void move_piece( int source_row, int source_col, int dest_row, int dest_col );
    void retract_move();
    bool is_empty(int row, int col);
    
    ~Board();
    
    friend std::ostream& operator <<(std::ostream& os, const Board& rhs);
    
private:
    char* board;
    int num_rows_;
    int num_cols_;
    
    int index(int row, int col ) const; 
};



#endif /* Board_h */
