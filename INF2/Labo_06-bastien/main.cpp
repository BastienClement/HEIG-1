#include <iostream>
#include <vector>

using namespace std;

enum class Image {
	man, check, cross
};

class Table {
	friend ostream& operator<<(ostream& os, const Table& table);

private:
	size_t width;
	vector<Image> cells;

	int random(int min, int max);
	void shuffle(vector<size_t>& vec);

public:
	Table(size_t width, size_t height, size_t count);
};

ostream& operator<<(ostream& os, const Table& table);

Table::Table(size_t w, size_t h, size_t count) : width(w), cells(w * h, Image::man) {
	const size_t size = cells.size();

	if (count > size) count = size;

	vector<size_t> random(size);
	for (size_t i = 0; i < size; i++) random[i] = i;
	shuffle(random);

	for (size_t i = 0; i < count; i++) {
		cells[random[i]] = (rand() % 2 == 0) ? Image::check : Image::cross;
	}
}

int Table::random(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void Table::shuffle(vector<size_t>& vec) {
	for (size_t max = vec.size() - 1; max > 0; max--) {
		swap(vec[max], vec[random(0, max)]);
	}
};

ostream& operator<<(ostream& os, const Table& table) {
	size_t i = 0;
	for_each(table.cells.begin(), table.cells.end(), [&](Image img) {
		os << " " << (int) img << " ";
		if (++i % table.width == 0) cout << endl;
	});
	return os;
}

unsigned int readUnsigned(string what) {
	unsigned int val;

	while (true) {
		cout << what << "? ";
		if (cin >> val) break;
		cin.clear();
		while(cin.get() != '\n');
	}

	return val;
}

int main() {
	srand(time(NULL));

	size_t width = readUnsigned("Table width");
	size_t height = readUnsigned("Table height");
	size_t count = readUnsigned("How many signs");

	Table t(width, height, count);
	cout << t << endl;

	return 0;
}