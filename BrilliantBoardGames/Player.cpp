//
//  Player.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 11/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Player.h"

// Initializes a new player with a fixed number of pieces and the players number
Player::Player( int player_num, int num_pieces ) : player_num_( player_num ), num_pieces_( num_pieces ) {
    
}

Player::~Player() {
    for (int i = 0; i < pieces.size(); i++) {
        delete pieces[i];
    }
}

// Pushes a piece into a vector of all pieces this player owns
void Player::fill_pieces(Piece* piece) {
    pieces.push_back(piece);
}

// Places this players pieces on the board
void Player::put_pieces_on_board(Board* board) {
    for ( int i = 0; i < get_num_pieces(); i++ ) {
        board->place_piece(pieces[i]);
    }
}

// Returns number of pieces the player owns
int Player::get_num_pieces() {
    return static_cast<int>(pieces.size());
}

// Moves a piece from its source point to destination point
void Player::move_piece( int source_row, int source_col, int dest_row, int dest_col ) {
    for (int i = 0; i < pieces.size(); i++) {
        if ( pieces[i]->get_row() == source_row && pieces[i]->get_col() == source_col ) {
            pieces[i]->set_pos(dest_row, dest_col);
        }
    }
}

int Player::get_player_num() {
    return player_num_;
}
