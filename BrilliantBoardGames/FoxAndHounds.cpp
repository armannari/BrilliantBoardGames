//
//  FoxAndHounds.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 14/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "FoxAndHounds.h"
#include "Fox.h"
#include "Hound.h"

FoxAndHounds::FoxAndHounds() : Game(8, 8, 1, 4) {
    board = new Board( num_rows_, num_cols_ );
    player1 = new Player( 1, player1_pieces );
    player2 = new Player( 2, player2_pieces );
    players.push_back(player1);
    players.push_back(player2);
    
    std::vector<Piece*> player1_piece_vector;
    std::vector<Piece*> player2_piece_vector;
    
    fill_player1_pieces(player1, player1_piece_vector);
    fill_player2_pieces(player2, player2_piece_vector);
    
    player1->put_pieces_on_board(board);
    player2->put_pieces_on_board(board);
    curr_player = player1;
    debug_mode_ = false;
}

void FoxAndHounds::fill_player1_pieces( Player* player, std::vector<Piece*> v ) {
    v.push_back(new Fox(7, 0));
    
    for (int i = 0; i < v.size(); i++) {
        player->fill_pieces(v[i]);
    }
}

void FoxAndHounds::fill_player2_pieces(Player* player, std::vector<Piece*> v) {
    v.push_back( new Hound( 0, 1 ) );
    v.push_back( new Hound( 0, 3 ) );
    v.push_back( new Hound( 0, 5 ) );
    v.push_back( new Hound( 0, 7 ) );
    
    for (int i = 0; i < v.size(); i++) {
        player->fill_pieces(v[i]);
    }
}

bool FoxAndHounds::legal( Player* player, int source_row, int source_col, int dest_row, int dest_col ) {
    Piece* curr_piece = new Piece();
    
    if (dest_row >= 0 && dest_row <= board->get_num_rows() && dest_col >= 0 && dest_col <= board->get_num_cols()) {
        if (source_row >= 0 && source_row <= board->get_num_rows() && source_col >= 0 && source_col <= board->get_num_cols()) {
            if ( board->is_empty( board->get_num_rows() - dest_row, dest_col ) ) {
                for ( int i = 0; i < curr_player->get_num_pieces(); i++ ) {
                    if (source_row == board->get_num_rows() - curr_player->pieces[i]->get_row() && source_col == curr_player->pieces[i]->get_col()) {
                        if (debug_mode_) {
                            std::cout << "Piece on source point!" << std::endl;
                        }
                        curr_piece = curr_player->pieces[i];
                        if ( curr_piece->legal_move( board->get_num_rows() - dest_row, dest_col ) ) {
                            return true;
                        } else { std::cout << "illegal move!" << std::endl; }
                    }
                    else {
                        if ( debug_mode_ ) {
                            std::cout << "Piece not on source point!" << std::endl;
                        }
                    }
                }
            }
            else {
                if ( debug_mode_ )  {
                    std::cout << "There is aldready a piece on that point!" << std::endl;
                }
            }

        } else {
            if (debug_mode_) {
                std::cout << "Source point not on board!" << std::endl;
            }
        }
    } else {
        if ( debug_mode_ ) {
            std::cout << "Destination point not on board!" << std::endl;
        }
    }
    
    return false;
}


bool FoxAndHounds::end_state() {
    int closest_row = board->get_num_rows();
    for (int i = 0; i < player2->get_num_pieces(); i++) {
        if (player2->pieces[i]->get_row() < closest_row) {
            closest_row = player2->pieces[i]->get_row();
        }
    }
    if ( ( player1->pieces[0]->get_row() < closest_row ) || ( player1->pieces[0]->get_row() == 0) ) {
        return true;
    }
    if ( legal( player1, player1->pieces[0]->get_row(), player1->pieces[0]->get_col(), player1->pieces[0]->get_row()+1, player1->pieces[0]->get_col()+1 ) ) {
        return false;
    }
    if ( legal( player1, player1->pieces[0]->get_row(), player1->pieces[0]->get_col(), player1->pieces[0]->get_row()+1, player1->pieces[0]->get_col()-1 ) ) {
        return false;
    }
    if ( legal( player1, player1->pieces[0]->get_row(), player1->pieces[0]->get_col(), player1->pieces[0]->get_row()-1, player1->pieces[0]->get_col()+1 ) ) {
        return false;
    }
    if ( legal( player1, player1->pieces[0]->get_row(), player1->pieces[0]->get_col(), player1->pieces[0]->get_row()-1, player1->pieces[0]->get_col()-1 ) ) {
        return false;
    }
    return false;
}

