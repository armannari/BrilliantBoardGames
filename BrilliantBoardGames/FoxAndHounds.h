//
//  FoxAndHounds.hpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 14/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#ifndef FoxAndHounds_h
#define FoxAndHounds_h

#include <stdio.h>
#include "Game.h"

class FoxAndHounds : public Game {
    
public:
    FoxAndHounds();
    virtual void fill_player1_pieces( Player* player, std::vector<Piece*> v );
    virtual void fill_player2_pieces( Player* player, std::vector<Piece*> v );
    virtual bool legal( Player* player, int source_row, int source_col, int dest_row, int dest_col );
    virtual bool end_state();
};

#endif /* FoxAndHounds_h */
