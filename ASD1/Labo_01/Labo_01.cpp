/*
 * Labo: 1
 * File: Labo1.cpp
 * Author: fatemeh.borran
 * Description: Evaluation of the polynoms using three different algorithms.
 * Created on February 11, 2015, 1:59 PM
 * Modified by olivier.cuisenaire Feb 20, 2015.
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;

/*
 * Reads the degree of a polynom.
 * The degree should be a positive integer.
 * Returns the degree.
 */
int readDegree() {
   int n = 0;
   bool ok = false;

   while (!ok) {
      cout << "Reading degree (integer > 0):";
      cin >> n;
      if (!cin.good()) {
         cout << "Not valid integer value!\n";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else if (n <= 0) {
         cout << "Not valid positive integer!\n";
      } else
         ok = true;
   }

   return n;
}

/*
 * Reads a double value (X_0).
 * Returns a double.
 */
double readX() {
   double x = 0.;
   bool ok = false;

   while (!ok) {
      cout << "Reading X (double):";
      cin >> x;
      if (!cin.good()) {
         cout << "Not valid double number!\n";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else
         ok = true;
   }

   return x;
}

/*
 * Reads the coefficients (doubles) of a polynom with degree n.
 * Param: n degree of the polynom (integer value > 0).
 * Returns the coefficients (vector of doubles).
 */
vector<double> readCoef(int n) {
   cout << "Reading coefficients:\n";

   vector<double> a(n + 1);

   for (int i = 0; i <= n; i++) {
      bool ok = false;
      while (!ok) {
         cout << "Reading coef_" << i << " (double):";
         cin >> a[i];
         if (!cin.good()) {
            cout << "Not valid coefficient!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         } else
            ok = true;
      }
   }

   return a;
}

/*
 * Generates random coefficients (doubles) of a polynom with degree n.
 * Param: n degree of the polynom (integer value > 0).
 * Returns the coefficients (vector of doubles [0,1]).
 */
vector<double> randomCoef(int n) {
   //cout << "Random coefficients:\n";

   vector<double> a(n + 1);

   for (int i = 0; i <= n; i++) {
      a[i] = (double) rand() / RAND_MAX;
      //cout << "coef_" << i << " = " << a[i] << endl;
   }

   return a;
}

/*
 * Evaluates a polynom with degree n and coefficients a.
 * Algorithm 1.
 * Params: - n the degree of the polynom (integer value > 0)
 *         - a the coefficients (vector of doubles)
 *         - x the point to evaluate polynom
 * Returns a double.
 */
double evalPoly1(const vector<double>& a, double x) {
   int n = (int) a.size() - 1;

   cout << "Evaluating polynom using Algorithm 1:" << endl;
   long long int sums = 0;
   long long int mults = 0;

   double result = 0;
   
   for (int i = 0; i <= n; i++){
      double w = a[i];
      for (int j = 0; j < i; j++){
         w *= x;
         mults++;
      }
      result += w;
      sums++;
   }


   cout << "#adds = " << sums << " #mults = " << mults << endl;
   return result;

}

/*
 * Evaluates a polynom with degree n and coefficients a.
 * Algorithm 2.
 * Params: - n the degree of the polynom (integer value > 0)
 *         - a the coefficients (vector of doubles)
 *         - x the point to evaluate polynom
 * Returns a double.
 */
double evalPoly2(const vector<double>& a, double x) {
   int n = (int) a.size() - 1;

   cout << "Evaluating polynom using Algorithm 2:" << endl;
   int sums = 0;
   int mults = 0;

   double result = 0;
   double w = 1;
   
   for (int i = 0; i <= n; i++){
      result += a[i] * w;
      w *= x;
      mults += 2;
      sums++;
   }

   cout << "#adds = " << sums << " #mults = " << mults << endl;
   return result;

}

/*
 * Evaluates a polynom with degree n and coefficients a.
 * Algorithm 3: Horner.
 * Params: - n the degree of the Polynom (integer value > 0)
 *         - a the coefficients (vector of doubles)
 *         - x the point to evaluate polynom
 * Returns a double.
 */
double evalPoly3(const vector<double>& a, double x) {
   int n = (int) a.size() - 1;

   cout << "Evaluating polynom using Algorithm 3:" << endl;
   int sums = 0;
   int mults = 0;

   double result = a[n];
   
   for (int i = n-1; i>= 0; i--){
      result *= x;
      result += a[i];
      sums++;
      mults++;
   }

   cout << "#adds = " << sums << " #mults = " << mults << endl;
   return result;

}

void menu();

/*
 * Tests a polynom on different points using three algorithms.
 * Params: - n the degree of the polynom.
 *         - a the coefficients (vector of doubles)
 */
void testPoly(int n, vector<double> a) {
   char ch = 'c';
   while (ch == 'c') {
      double x = readX();
      double eval1 = evalPoly1(a, x);
      cout << "eval1 = " << eval1 << endl;
      double eval2 = evalPoly2(a, x);
      cout << "eval2 = " << eval2 << endl;
      double eval3 = evalPoly3(a, x);
      cout << "eval3 = " << eval3 << endl;
      cout << "Press 'q' to quit. Press 'c' to continue. Press 'm' to go back to the menu.\n";
      cin >> ch;
      if (ch == 'q')
         break;
      if (ch == 'm')
         menu();
      else
         cout << "Incorrect choice!" << endl;
   }
}

/*
 * Menu that asks user to choose between:
 * 1. Evaluates the polynom.
 * 2. Compares three algorithms for evaluting a polynom.
 */
void menu() {

   int choice;

   cout << "=============== MENU ===============" << endl;
   cout << "1 - Evaluation of polynom." << endl;
   cout << "2 - Comparison of three algorithms for evaluating a polynom." << endl;

   cin >> choice;

   if (choice == 1) {
      int n = readDegree();
      vector<double> a = readCoef(n);
      testPoly(n, a);
   } else if (choice == 2) {
      double x = readX();
      for (int m = 1; m < 6; m++) {
         double n = pow(10, m);
         cout << "n = " << n << endl;
         vector<double> a = randomCoef(n);
         double eval1 = evalPoly1(a, x);
         cout << "eval1 = " << eval1 << endl;
         double eval2 = evalPoly2(a, x);
         cout << "eval2 = " << eval2 << endl;
         double eval3 = evalPoly3(a, x);
         cout << "eval3 = " << eval3 << endl;
         cout << "-----------------" << endl;
      }
   } else {
      cout << "Incorrect choice!" << endl;
      menu();
   }
}

/*
 * Main programm.
 */
int main(int argc, char** argv) {
   menu();
   return EXIT_SUCCESS;
}
