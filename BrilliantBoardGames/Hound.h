//
//  Hound.hpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 14/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#ifndef Hound_h
#define Hound_h

#include <stdio.h>
#include "Piece.h"

class Hound : public Piece {
    
public:
    Hound( int row, int col );
    virtual bool legal_move( int dest_row, int dest_col );
    
    
private:
};

#endif /* Hound_h */
