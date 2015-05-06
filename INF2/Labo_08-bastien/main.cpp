#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Erreur {
	string message;
};

struct Rel {
	char alpha;
	string morse;
};

static const vector<Rel> symboles = {
		{'A', ".-"},
		{'B', "-..."},
		{'C', "-.-."},
		{'D', "-.."},
		{'E', "."},
		{'F', "..-."},
		{'G', "--."},
		{'H', "...."},
		{'I', ".."},
		{'J', ".---"},
		{'K', "-.-"},
		{'L', ".-.."},
		{'M', "--"},
		{'N', "-."},
		{'O', "---"},
		{'P', ".--."},
		{'Q', "--.-"},
		{'R', ".-."},
		{'S', "..."},
		{'T', "-"},
		{'U', "..-"},
		{'V', "...-"},
		{'W', ".--"},
		{'X', "-..-"},
		{'Y', "-.--"},
		{'Z', "--.."},

		{'1', ".----"},
		{'2', "..---"},
		{'3', "...--"},
		{'4', "....-"},
		{'5', "....."},
		{'6', "-...."},
		{'7', "--..."},
		{'8', "---.."},
		{'9', "----."},
		{'0', "-----"},

		{'.', ".-.-.-"},
		{',', "--..--"},
		{'?', "..--.."},
		{'!', "---."},
		{'(', "-.--."},
		{')', "-.--.-"},
		{'&', ".-..."},
		{':', "---..."},
		{';', "-.-.-."},
		{'=', "-...-"},
		{'+', ".-.-."},
		{'-', "-....-"},
		{'$', "...-..-"},
		{'@', ".--.-."},

		{' ', "/"}
};

char alpha(const string& morse) {
	for (size_t i = 0; i < symboles.size(); i++) {
		if (symboles[i].morse == morse)
			return symboles[i].alpha;
	}

	throw Erreur {"Symbole morse inconnu"};
};

string morse(const char alpha) {
	for (size_t i = 0; i < symboles.size(); i++) {
		if (symboles[i].alpha == alpha)
			return symboles[i].morse;
	}

	throw Erreur {"Symbole alphabétique inconnu"};
}

string encode(const string& message) {
	if (message.length() < 1)
		return "";

	stringstream code;

	code << morse(toupper(message[0]));
	for (size_t i = 1; i < message.length(); i++) {
		code << " " << morse(toupper(message[i]));
	}

	return code.str();
}

string decode(const string& message) {
	if (message.length() < 1)
		return "";

	stringstream texte;
	string symbole = "";

	for (size_t i = 0; i < message.length(); i++) {
		char c = message[i];

		if (c == ' ') {
			if (!symbole.empty()) {
				texte << alpha(symbole);
				symbole = "";
			}
		} else {
			symbole += c;
		}
	}

	if (!symbole.empty()) {
		texte << alpha(symbole);
	}

	return texte.str();
}

int main() {
	string str = "... --- ... / - .. - .- -. .. -.-. / .--. --- ... .. - .. --- -. / ....- .---- .-.-.- ....- "
			"....- / -. / / ..... ----- .-.-.- ..--- ....- / .-- .-.-.- / .-. . --.- ..- .. .-. . / .. -- -- . "
			"-.. .. .- - . / .- ... ... .. ... - .- -. -.-. . .-.-.- / -.-. --- -- . / .- - / --- -. -.-. . "
			".-.-.- / .-- . / ... - .-. ..- -.-. -.- / .- -. / .. -.-. . -... . .-. --. .-.-.- / ... .. -. -.- "
			".. -. --. ---.";

	cout << decode(str) << endl;
	return 0;
}
