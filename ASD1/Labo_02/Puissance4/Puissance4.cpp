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
#include <stack>
#include <cstring>
using namespace std;

//
// Variables globales
//

//
// A COMPLETER PAR LES VARIABLES DONT VOUS AVEZ BESOIN
//

// les joueurs sont +1 et -1. 0 pour les cases vides
const int X = 1, O = -1, EMPTY = 0;

int grid[7][6];
stack<int> moves;

struct BestMove {
   int col;
   double score;
};

/////////////////////////////////////////////////

//
// Fonctions
//

//
// A COMPLETER PAR LES FONCTIONS DONT VOUS AVEZ BESOIN
//

// efface le tableau

void clearBoard() {
   memset(grid, EMPTY, sizeof (grid));
}

// applique un movement en mettant Ã 
// currentPlayer la case du tableau
// correspondante.

void applyMove(int n, int player) {
   int row = 0;
   while (grid[n][row] != EMPTY && row < 5) row++;

   if (grid[n][row] == EMPTY) {
      grid[n][row] = player;
      moves.push(n);
   }
}

bool findLastMove(int& x, int& y) {
   if (moves.empty())
      return false;

   x = moves.top();
   y = 5;
   while (y > 0 && grid[x][y] == EMPTY) y--;
   return true;
}

void cancelMove() {
   int x, y;
   if (!findLastMove(x, y)) return;
   grid[x][y] = EMPTY;
   moves.pop();
}

int countSequence(int x, int y, int dx, int dy) {
   int player = grid[x][y];
   int count = 0;

   for (int i = 1; i < 4; i++) {
      int ix = x + (i * dx);
      int iy = y + (i * dy);

      if (ix < 0 || ix > 6) break;
      if (iy < 0 || iy > 5) break;

      if (grid[ix][iy] == player) {
         count++;
      } else {
         break;
      }
   }

   return count;
}

// trouve le joueur gagnant. Renvoie EMPTY
// si aucun joueur ne gagne Ã  ce stade.

int getWinner() {
   int x, y;
   if (!findLastMove(x, y)) return EMPTY;

   int player = grid[x][y];
   if ((countSequence(x, y, 1, 0) + countSequence(x, y, -1, 0) >= 3) ||
           (countSequence(x, y, 0, 1) + countSequence(x, y, 0, -1) >= 3) ||
           (countSequence(x, y, 1, 1) + countSequence(x, y, -1, -1) >= 3) ||
           (countSequence(x, y, 1, -1) + countSequence(x, y, -1, 1) >= 3))
      return player;

   return EMPTY;
}

// indique si le tableau est plein
// (les 7 colonnes sont pleines)

bool isFull() {
   for (int i = 0; i < 7; i++) {
      if (grid[i][5] == EMPTY)
         return false;
   }
   return true;
}

// verifie le validite d'un movement.
// doit etre entre 1 et 7 (inclus) et
// la colonne corrspondant doit avoir de la place.

bool isValidMove(int n) {
   return grid[n][5] == EMPTY;
}

// affiche le tableau

void printBoard() {
	bool has_winner = getWinner() != EMPTY;
	int win_x, win_y;
	if (has_winner) findLastMove(win_x, win_y);

	cout << "\n  1   2   3   4   5   6   7\n";
	cout << "\n+---+---+---+---+---+---+---+\n";

	for (int i = 5; i >= 0; i--) {
		cout << "|";
		for (int j = 0; j < 7; j++) {
			cout << (has_winner && win_x == j && win_y == i ? "(" : " ");
			switch (grid[j][i]) {
				case X: cout << "X"; break;
				case O: cout << "O"; break;
				case EMPTY: cout << " ";
			}
			cout << (has_winner && win_x == j && win_y == i ? ")" : " ");
			cout << "|";
		}
		cout << "\n+---+---+---+---+---+---+---+\n";
	}
}

BestMove bestMove(int player, int depth = 7);

double score(int n, int player, int depth) {
	double playerScore = 0;

	applyMove(n, player);

	if (getWinner() == player) {
		playerScore = 10;
	} else if (isFull() || depth <= 0) {
		playerScore = 0;
	} else {
		playerScore = -bestMove(-player, depth - 1).score;
	}

   cancelMove();
   // Pondération du score en fonction de la colonne
   // l'IA aura tendance à plus jouer dans les colonnes centrales
   return playerScore + (double(rand()) / RAND_MAX) * (0.66+2*n/9-n*n/27);
}

BestMove bestMove(int player, int depth) {
	int bestCol = 0;
	double bestScore = -100;

	for (int i = 0; i < 7; i++) {
		if (isValidMove(i)) {
			double scr = score(i, player, depth);
			if (scr > bestScore) {
				bestScore = scr;
				bestCol = i;
			}
		}
	}

	return {bestCol, bestScore};
}

// choisit automatiquement le prochain mouvement
// comme etant celui qui donne le meilleur score

int ai(int player) {
   return bestMove(player).col;
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

	// Simple correction pour les index utilisÃ© dans le code ci-dessus
	n -= 1;
    
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

   if (!cin.good() || (n < 0) || (n > 2)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Nombre de joueur invalide. " << endl;
      return askNumberOfPlayers();
   } else
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
            cout << endl << "AI joue " << nextMove + 1 << endl;
        }
        applyMove(nextMove,currentPlayer);
        currentPlayer = - currentPlayer;
    }
    
    printBoard();
    
    int winner = getWinner();
    if (winner != EMPTY)
        cout << " \n\n" << (winner == X ? 'X' : 'O') << " gagne! \n\n\n";
    else
        cout << " \n\n EgalitÃ©! \n\n\n";
    
    return EXIT_SUCCESS;
}