//
//  abr.cpp
//  Binary Search Tree
//
//  Created by Olivier Cuisenaire on 18.05.2015
//  Copyright (c) 2015 Olivier Cuisenaire. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;


template < typename KeyType >
class BinarySearchTree {
	// Classe d'arbre binaire de recherche stockant des clés
	// de type KeyType

private:
	//
	// Noeud de l'arbre. contient une cle et les liens vers les
	// sous-arbres droit et gauche.
	//
	struct Node {
	public:
		KeyType key;
		Node* right; // sous arbre avec des cles plus grandes
		Node* left;  // sous arbre avec des cles plus petites
		Node(KeyType key) : key(key), right(nullptr), left(nullptr) { }
	};

	//
	// Racine de l'arbre.
	//
	Node* root;

public:
	BinarySearchTree() : root(nullptr) {
		//
		// Constructeur. La racine est vide
		//
		// NE PAS MODIFIER
		//


	}

public:
	~BinarySearchTree() {
		//
		// Destructeur. effacement récursif des noeuds
		//
		// NE PAS MODIFIER
		//

		deleteSubTree( root );
	}
private:
	void deleteSubTree(Node* x) {
		//
		// efface récursivement tous les noeuds
		//
		// NE PAS MODIFIER
		//

		if( x == nullptr) return;
		deleteSubTree( x->right );
		deleteSubTree( x->left );
		delete x;
	}

public:
	void insert( const KeyType& key) {
		//
		// Insertion d'une cle. appelle la version
		// récursive en lui fournissat la racine
		// en paramètre.
		//
		// NE PAS MODIFIER
		//

		root = insert(root,key);
	}

private:
	Node* insert(Node* x, const KeyType& key) {
		//
		// Insertion d'une cle dans le sous-arbre
		// de racine x. Renvoie x en retour sauf
		// si celui-ci doit-être modifié chez le
		// noeud parent.
		//
		// A COMPLETER
		//

		if (x == nullptr) {
			return new Node(key);
		} else if (key < x->key) {
			x->left = insert(x->left, key);
		} else if (key > x->key) {
			x->right = insert(x->right, key);
		}

		return x;
	}

public:
	bool contains( const KeyType& key ) {
		//
		// Recherche d'une cle. Renvoie true si la cle est
		// trouvee. Renvoie false sinon.
		//
		// NE PAS MODIFIER
		//

		return contains(root,key);
	}

private:
	bool contains(Node* x, const KeyType& key) {
		//
		// Recherche d'une cle dans le sous-arbre
		// de racine x. Renvoie true si la cle est
		// trouvee. Renvoie false sinon.
		//
		// A COMPLETER
		//

		if (x == nullptr) {
			return false;
		} else if (key < x->key) {
			return contains(x->left, key);
		} else if (key > x->key) {
			return contains(x->right, key);
		} else {
			return true;
		}
	}


public:
	KeyType min() {
		//
		// Renvoie la cle la plus petite de l'arbre
		//
		// NE PAS MODIFIER
		//

		return min(root)->key;
	}

private:
	Node* min(Node* x) {
		//
		// Renvoie l'élément à la plus petite clé
		// du sous-arbre de racine x
		//
		// A COMPLETER
		//

		return (x->left == nullptr) ? x : min(x->left);
	}

public:
	void deleteMin() {
		//
		// Efface le plus petit element de l'arbre.
		// Ne fait rien si l'arbre est vide.
		// NE PAS MODIFIER
		//

		if (root != nullptr) {
			root = deleteMin(root);
		}
	}

private:
	Node* deleteMin(Node* x) {
		//
		// Efface le plus petit element du sous-arbre
		// de racine x. Renvoie x par défaut, mais
		// éventuellement une autre valeur si la racine
		// du sous-arbre change.
		//
		// A COMPLETER
		//

		if (x == nullptr) {
			throw "Erreur";
		} else if (x->left == nullptr) {
			auto subtree = x->right;
			delete x;
			return subtree;
		} else {
			x->left = deleteMin(x->left);
			return x;
		}
	}


public:
	void deleteElement( const KeyType& key) {
		//
		// Efface l'element quelconque de cle key
		// Ne fait rien si la clé n'est pas présente.
		//
		// NE PAS MODIFIER
		//

		root = deleteElement( root, key );
	}

private:
	Node* deleteElement( Node* x, const KeyType& key) {
		//
		// Efface l'element quelconque de cle key dans
		// le sous-arbre de racine x. Ne fait rien si
		// la clé n'est pas présente.
		// renvoie la racine du sous-arbre après suppression
		// le plus souvent il s'agit de x.
		//
		// A COMPLETER
		//

		if (x == nullptr) {
			return x;
		}

		if (key < x->key) {
			x->left = deleteElement(x->left, key);
		} else if (key > x->key) {
			x->right = deleteElement(x->right, key);
		} else {
			if (x->right == nullptr) {
				auto subtree = x->left;
				delete x;
				return subtree;
			} else if (x->left == nullptr) {
				auto subtree = x->right;
				delete x;
				return subtree;
			} else {
				auto m = min(x->right);
				swap(m->key, x->key);
				x->right = deleteMin(x->right);
			}
		}

		return x;
	}


	// ********************************* //
	//                                   //
	// NE RIEN CHANGER APRES CETTE LIGNE //
	//                                   //
	// méthodes et main() de test        //
	//                                   //
	// ********************************* //


public:
	template < typename Fn >
	void visitInOrder (Fn f) {
		//
		// Parcours de l'arbre par ordre croissant de cle
		//

		if ( root != nullptr)
			visitInOrder(root,f);
	}

private:
	template < typename Fn >
	void visitInOrder ( Node* x, Fn f) {
		//
		// Parcours de l'arbre par ordre croissant de cle
		//

		if ( x->left != nullptr)
			visitInOrder(x->left,f);

		f( x->key );

		if ( x->right != nullptr)
			visitInOrder(x->right,f);
	}


public:
	void display () {
		//
		// utilise un parcours de l'arbre en largeur avec
		// un noeud sentinelle newLevel qui traque les
		// changements de niveaux
		//

		Node* newLevel = new Node(0);

		queue<Node*> Q;
		Q.push(root);
		Q.push(newLevel);

		while(!Q.empty()) {
			Node* x = Q.front();
			Q.pop();

			if(x == newLevel ) {
				cout << endl;
				if(!Q.empty())
					Q.push(newLevel);
			} else if(x==nullptr) {
				cout << "- ";
			} else {
				cout << x->key << " ";
				Q.push(x->left);
				Q.push(x->right);
			}
		}

		delete newLevel;
	}
};

// ******************* //

int main(int argc, const char * argv[]) {

	BinarySearchTree<int> abr;

	cout << "Test de suppressions sur arbre vide." << endl << endl;;

	abr.deleteMin();
	abr.deleteElement(42);

	const int N = 42;

	cout << "Insertion de " << N << " éléments au hasard" << endl;

	for(int i = 0; i < N; ++i) {
		int key = rand()%N;
		cout << key << " ";
		abr.insert(key);
	}
	cout << endl << endl;

	cout << "Etat de l'ABR: " << endl;
	abr.display();
	cout << endl;

	cout << "Contenu trié de l'ABR après les insertions" << endl;

	abr.visitInOrder([](int a){ cout << a << " "; });
	cout << endl << endl ;

	cout << "L'élément minimum est " << abr.min() << endl << endl ;

	cout << "Suppression du minimum" << endl;
	abr.deleteMin();

	cout << "Le nouveau minimum est " << abr.min() << endl << endl ;

	cout << "Etat de l'ABR: " << endl;
	abr.display();
	cout << endl;

	cout << "Contenu trié de l'ABR après suppression du minimum" << endl;
	abr.visitInOrder([](int a){ cout << a << " "; });
	cout << endl << endl ;

	cout << "Suppression des clés paires" << endl;

	for(int i = 0; i < (N+1)/2; ++i) {
		int key = i*2;
		cout << key << " ";
		abr.deleteElement(key);
	}
	cout << endl << endl;

	cout << "Etat de l'ABR: " << endl;
	abr.display();
	cout << endl;

	cout << "Contenu trié de l'ABR après les suppressions" << endl;

	abr.visitInOrder([](int a){ cout << a << " "; });
	cout << endl << endl ;

	cout << "Recherche des clés impaires" << endl;

	for(int i = 0; i < N/2; ++i) {
		int key = i*2+1;
		if( abr.contains(key) )
			cout << key << " ";
		else
			cout << "(" << key << ") ";
	}
	cout << endl;

	return 0;
}
