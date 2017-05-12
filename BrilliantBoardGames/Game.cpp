//
//  Game.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Game.h"

Game::Game( int num_rows, int num_cols, int player1_pieces, int player2_pieces ) : num_rows_( num_rows ), num_cols_( num_cols ) {
    board = new Board( num_rows_, num_cols_ );
    player1 = new Player( 1, player1_pieces );
    player2 = new Player( 2, player2_pieces );
    players.push_back(player1);
    players.push_back(player2);
    player1->fill_pieces(new Piece(7, 0, 'p'));
    player1->fill_pieces(new Piece(7, 1, 'p'));
    player1->fill_pieces(new Piece(7, 2, 'p'));
    player1->fill_pieces(new Piece(7, 3, 'p'));
    player1->fill_pieces(new Piece(7, 4, 'p'));
    player1->fill_pieces(new Piece(7, 5, 'p'));
    player1->fill_pieces(new Piece(7, 6, 'p'));
    player1->fill_pieces(new Piece(7, 7, 'p'));
    player1->fill_pieces(new Piece(6, 0, 'm'));
    player1->fill_pieces(new Piece(6, 1, 'm'));
    player1->fill_pieces(new Piece(6, 2, 'm'));
    player1->fill_pieces(new Piece(6, 3, 'm'));
    player1->fill_pieces(new Piece(6, 4, 'm'));
    player1->fill_pieces(new Piece(6, 5, 'm'));
    player1->fill_pieces(new Piece(6, 6, 'm'));
    player1->fill_pieces(new Piece(6, 7, 'm'));
    
    player1->put_pieces_on_board(board);
    player2->put_pieces_on_board(board);
    curr_player = player1;
}

Game::~Game() {
    delete player1;
    delete player2;
    delete board;
}

// Outputs the game board
void Game::print_board() {
    std::cout << *board << std::endl;
}

// Moves a piece on the game board
void Game::move_piece( std::string source, std::string destination ) {
    if ( curr_player == players[1] ) {
        curr_player = players[0];
    } else { curr_player = players[1]; }
    std::cout << std::endl << "Player " << curr_player->get_player_num() << " your turn!" << std::endl;
    
    char letters[9] { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
    int source_row = source[1] - '0';
    int source_col = 0;
    for (int i = 0; i < 9; i++) {
        if (source[0] == letters[i]) {
            source_col = i;
        }
    }
    std::cout << std::endl;
    int dest_row = destination[1] - '0';
    int dest_col = 0;
    for (int i = 0; i < 9; i++) {
        if (destination[0] == letters[i]) {
            dest_col = i;
        }
    }
    
    board->move_piece( source_row, source_col, dest_row, dest_col );
    std::cout << std::endl;
    print_board();
}
