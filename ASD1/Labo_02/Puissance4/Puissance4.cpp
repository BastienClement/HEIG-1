//
//  Puissance4.cpp
//  Tic Tac Toe
//
//  Created by Olivier Cuisenaire on 09.03.15.
//  Copyright (c) 2015 Olivier Cuisenaire. All rights reserved.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
using namespace std;

//
// Variables globales
//

//
// A COMPLETER PAR LES VARIABLES DONT VOUS AVEZ BESOIN
//

// les joueurs sont +1 et -1. 0 pour les cases vides
const int X = 1, O = -1, EMPTY = 0;

/////////////////////////////////////////////////

//
// Fonctions
//

//
// A COMPLETER PAR LES FONCTIONS DONT VOUS AVEZ BESOIN
//

// efface le tableau
void clearBoard() {
    
    // A COMPLETER
    
}

// applique un movement en mettant à
// currentPlayer la case du tableau
// correspondante.
void applyMove(int n, int player) {
    
    // A COMPLETER
    
}

// trouve le joueur gagnant. Renvoie EMPTY
// si aucun joueur ne gagne à ce stade.
int  getWinner() {
    
    // A COMPLETER
    
    return 0;
}

// indique si le tableau est plein
// (les 7 colonnes sont pleines)
bool isFull() {
    
    // A COMPLETER
    
    return true;
}

// verifie le validite d'un movement.
// doit etre entre 1 et 7 (inclus) et
// la colonne corrspondant doit avoir de la place.
bool isValidMove(int n) {
    
    // A COMPLETER
    
    return true;
}

// affiche le tableau
void printBoard() {
    
    // A COMPLETER
    
}

// choisit automatiquement le prochain mouvement
// comme etant celui qui donne le meilleur score
int ai(int player) {

    // A COMPLETER
    
    return 0;
}


////// NE RIEN MODIFIER SOUS CETTE LIGNE ///////



// choisit interactivement le prochain mouvement
// en le demandant au joueur et en verifiant que
// le choix est licite.
// cette fonction est recursive si le choix est
// illicite.
int interactive(int player) {
    cout << endl << "Prochain movement du joueur " << ((player==X) ? "X" : "O" ) << ": " << flush;
    
    int n;
    cin >> n;
    cout << endl;
    
    if(!cin.good() || !isValidMove(n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Movement non valide. Essayez encore." << endl;
        return interactive(player);
    } else
        return n;
}

// choisit interactivement le nombre de joueurs humains
// en le demandant au joueur et en verifiant que
// le choix est licite.
// cette fonction est recursive si le choix est
// illicite.
int askNumberOfPlayers() {
    
    cout << "Combien de joueurs humains? (0,1 ou 2) " << flush;
    
    int n;
    cin >> n;
    cout << endl;
    
    if(!cin.good() || (n < 0) || (n>2) ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Nombre de joueur invalide. " << endl;
        return askNumberOfPlayers();
    }
    else
        return n;
}

// programme principal. Demande le nombre de joueurs
// humains, choisit aleatoirement qui commence en cas
// de match humain/ordinateur. Puis boucle tant qu'il
// n'y a pas de vainqueur et que le tableau n'est pas
// plein. Affiche le resultat du match.
int main() {
    // joueur courant. +1 ou -1;
    int currentPlayer;
    
    // indique si un joueur est humain ou ordinateur
    bool human[2];
    
    srand ( (int) time(0) );
    
    int np = askNumberOfPlayers();
    
    switch(np) {
        case 0:
            human[0] = human[1] = false;
            break;
        case 1:
            human[0] = rand() % 2;  // choix aleatoire du premier joueur
            human[1] = !human[0];
            break;
        case 2:
            human[0] = human[1] = true;
            break;
    }
    
    clearBoard();
    currentPlayer = X;
    
    while( getWinner() == EMPTY && !isFull() ) {
        printBoard();
        
        int nextMove;
        if (human[(currentPlayer + 1) / 2])
            nextMove = interactive(currentPlayer);
        else {
            nextMove = ai(currentPlayer);
            cout << endl << "AI joue " << nextMove << endl;
        }
        applyMove(nextMove,currentPlayer);
        currentPlayer = - currentPlayer;
    }
    
    printBoard();
    
    int winner = getWinner();
    if (winner != EMPTY)
        cout << " \n\n" << (winner == X ? 'X' : 'O') << " gagne! \n\n\n";
    else
        cout << " \n\n Egalité! \n\n\n";
    
    return EXIT_SUCCESS;
}