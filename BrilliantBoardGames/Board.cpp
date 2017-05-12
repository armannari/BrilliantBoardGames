//
//  Board.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Board.h"

// Fills new board with empty squares
Board::Board( int num_rows, int num_cols ) : num_rows_( num_rows ), num_cols_( num_cols ) {
    board = new char[ num_rows*num_cols ];
    
    for (int i = 0; i < num_rows_; i++) {
        for (int j = 0; j < num_cols_; j++) {
            board[index( i, j )] = '.';
        }
    }
}

Board::~Board() {
    delete [] board;
}

char& Board::operator()( const int& row, const int& col ) {
    return board[index( row, col )];
}
const char& Board::operator()( const int& row, const int& col ) const {
    return board[index( row, col )];
}

// Places a piece on the board
void Board::place_piece( Piece* piece ) {
    board[index(piece->get_row(), piece->get_col())] = piece->get_type();
}

// Moves a piece from the source point to the destination point
void Board::move_piece( int source_row, int source_col, int dest_row, int dest_col ) {
    std::cout << "Moving piece from (" << source_row << "," << source_col << ") to (" << dest_row << "," << dest_col << ")" << std::endl;
    
    board[index( get_num_rows() - dest_row, dest_col )] = board[index( get_num_rows() - source_row, source_col )];
    board[index( get_num_rows() - source_row, source_col )] = '.';
}


// Get position of the board
int Board::index( int row, int col ) const {
    return row * num_cols_ + col;
}

// Returns number of rows
int Board::get_num_rows() const {
    return num_rows_;
}

// Return number of cols
int Board::get_num_cols() const {
    return num_cols_;
}



std::ostream& operator <<( std::ostream& os, const Board& rhs ) {
    
    int counter = rhs.get_num_rows();
    
    for (int i = 0; i < rhs.get_num_rows(); i++) {
        os << counter;
        for (int j = 0; j < rhs.get_num_cols(); j++) {
            std::cout << ' ' << rhs(i, j);
        }
        os << std::endl;
        counter--;
    }
    
    char letters[9] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    
    std::cout << " ";
    
    for (int i = 0; i < rhs.get_num_cols(); i++) {
        std::cout << " " << letters[i];
    }
    
    return os;
}
