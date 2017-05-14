//
//  Fox.hpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 14/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#ifndef Fox_h
#define Fox_h

#include <stdio.h>
#include "Piece.h"

class Fox : public Piece {
    
public:
    Fox( int row, int col );
    virtual bool legal_move( int dest_row, int dest_col );
    
    
private:
};

#endif /* Fox_h */
