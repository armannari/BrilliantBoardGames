//
//  Game.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Game.h"

Game::Game() {}

Game::Game( int num_rows, int num_cols, int player1_pieces, int player2_pieces ) : num_rows_( num_rows ), num_cols_( num_cols ) {}

Game::~Game() {
    delete player1;
    delete player2;
    delete board;
}

// Outputs the game board
void Game::print_board() {
    std::cout << *board << std::endl;
    std::cout << curr_player->get_player_num()-1 << std::endl;
    std::cout << player1->pieces.size() << " "<< player2->pieces.size() << std::endl;
}

// Moves a piece on the game board
void Game::move_piece( std::string source, std::string destination ) {
    
    char letters[9] { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
    int source_row = source[1] - '0';
    int source_col = 0;
    for (int i = 0; i < 9; i++) {
        if (source[0] == letters[i]) {
            source_col = i;
        }
    }
    int dest_row = destination[1] - '0';
    int dest_col = 0;
    for (int i = 0; i < 9; i++) {
        if (destination[0] == letters[i]) {
            dest_col = i;
        }
    }
    
    if ( legal( curr_player, source_row, source_col, dest_row, dest_col ) ) {
        if (debug_mode_) {
            std::cout << "Moving piece from (" << source_row << "," << source_col << ") to (" << dest_row << "," << dest_col << ")" << std::endl;
        }
        board->move_piece( source_row, source_col, dest_row, dest_col );
        curr_player->move_piece( board->get_num_rows() - source_row, source_col, board->get_num_rows() - dest_row, dest_col );
        if ( curr_player == players[1] ) {
            curr_player = players[0];
        } else { curr_player = players[1]; }
    }
    
    if (debug_mode_) {
        print_board();
        std::cout << "Curr_player = " << curr_player->get_player_num() << std::endl;
    }
}

void Game::fill_player1_pieces( Player* player, std::vector<Piece*> v ) {
    std::cout << "Wrong one boijj" << std::endl;
}

void Game::fill_player2_pieces( Player* player, std::vector<Piece*> v ) {
    std::cout << "Wrong one boijj" << std::endl;
}

bool Game::legal( Player* player, int source_row, int source_col, int dest_row, int dest_col ) {
    Piece* curr_piece = new Piece();
    
    
    for (int i = 0; i < curr_player->get_num_pieces(); i++) {
        if (source_row == board->get_num_rows() - curr_player->pieces[i]->get_row() && source_col == curr_player->pieces[i]->get_col()) {
            if (debug_mode_) {
                std::cout << "Piece on source point!" << std::endl;
            }
            curr_piece = curr_player->pieces[i];
            if (curr_piece->legal_move(board->get_num_rows() - dest_row, dest_col)) {
                return true;
            } else { std::cout << "illegal move!" << std::endl; }
        }
        else {
            if (debug_mode_) {
                std::cout << "Piece not on source point!" << std:: endl;
            }
        }
    }
    return false;
}

void Game::toggle_debug_mode() {
    if (debug_mode_ == true) {
        debug_mode_ = false;
    } else { debug_mode_ = true; std::cout << "Debug mode on" << std::endl; }
}

void Game::get_all_legal_moves() {
    std::cout << "Writes out all legal moves for current player" << std::endl;
}

bool Game::end_state() {
    std::cout << "Wrong one love" << std::endl;
    return false;
}

int Game::get_curr_player() {
    return curr_player->get_player_num();
}
