//
//  main.cpp
//  BrilliantBoardGames
//
//  Created by Ármann Ari Árnason on 10/05/2017.
//  Copyright © 2017 Ármann Ari Árnason. All rights reserved.
//

#include "Board.h"
#include "Game.h"
#include "FoxAndHounds.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    vector<string> input_vector;
    
    Game* game = new Game();
    
    cout << "Welcome to Brilliant Board Games!" << endl;
    cout << "input 'list' to see list of available games" << endl;

    
    do {
        getline(cin, input);
        
        istringstream iss(input);
        string word;
        while(iss >> word) {
            input_vector.push_back(word);
        }
        
        if (input == "list") {
            cout << '\t' << "1. - Fox and Hound" << endl;
            cout << '\t' << "2. - Breaktrhough" << endl;
            cout << '\t' << "3. - Mega Breakthrough" << endl;
            cout << endl;
        }
        if ( input_vector[0] == "game" ) {
            if (input_vector[1] == "1") {
                game = new FoxAndHounds();
                cout << "Started Fox and Hounds!" << endl;
            }
            if (input_vector[1] == "2") {
                cout << "Not implemented yet" << endl;
            }
            if (input_vector[1] == "3") {
                cout << "Not implemented yet" << endl;
            }
        }
        if (input == "start") {
            game = new FoxAndHounds();
        }
        if (input == "legal") {
            game->get_all_legal_moves();
        }
        if ( input_vector[0] == "move" ) {
            game->move_piece(input_vector[1], input_vector[2]);
        }
        if (input == "retract") {
            cout << "Not implemented yet" << endl;
        }
        if ( input == "display") {
            game->print_board();
        }
        if (input == "evaluate") {
            cout << "Not implemented yet" << endl;
        }
        if (input == "go") {
            cout << "Not implemented yet" << endl;
        }
        if (input_vector[0] == "level") {
            cout << "Not implemented yet" << endl;
        }
        if (input == "debug") {
            game->toggle_debug_mode();
        }
        
        int vector_size = static_cast<int>(input_vector.size());
        
        for ( int i = 0; i < vector_size; i++ ) {
            input_vector.pop_back();
        }
        
        if (game->end_state()) {
            cout << "The game has ended!" << endl;
        }
        
    } while(input != "quit");
    
    delete game;
    
    return 0;
}
