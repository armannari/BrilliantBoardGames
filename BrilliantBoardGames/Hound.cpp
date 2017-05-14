//
//  Hound.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 14/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Hound.h"

Hound::Hound( int row, int col ) : Piece(row, col, 'h') {
    
}

bool Hound::legal_move( int dest_row, int dest_col ) {
    if ( dest_row == row_+1 && dest_col == col_-1 ) {
        return true;
    }
    if ( dest_row == row_+1 && dest_col == col_+1 ) {
        return true;
    }
    
    return false;
}
