#include <iomanip>
#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct legosets {
	string theme;
	int minifigs;
	string number;
	int pieces;
	double price;
	string setname;
};

int counter;
int sum1;
int sum2;
double sum3;
double average1;
double average2;
double average3;
vector<legosets> legolist;

void ReadLegos(const char* filepath, vector<legosets>& legolist) {
	ifstream files(filepath);

	if (files.is_open()) {
		string LEGO;
		getline(files, LEGO);
		while (!files.eof()) {

			getline(files, LEGO);
			istringstream stream(LEGO);
			string first, second, third, fourth, fifth, sixth;
			getline(stream, first, ',');
			getline(stream, second, ',');
			getline(stream, third, ',');
			getline(stream, fourth, ',');
			getline(stream, fifth, ',');
			getline(stream, sixth, ',');

			legosets ls;
			ls.number = first;
			ls.theme = second;
			ls.setname = third;
			ls.minifigs = stoi(fourth);
			ls.pieces = stoi(fifth);
			ls.price = stod(sixth);
			legolist.push_back(ls);
		}
	}
}

void printstandcolumn(int i) { 
	cout << "Name: " << legolist[i].setname << endl;
	cout << "Number: " << legolist[i].number << endl;
	cout << "Theme: " << legolist[i].theme << endl;
	cout << "Price: $" << legolist[i].price << endl;
	cout << "Minifigures: " << legolist[i].minifigs << endl;
	cout << "Piece count: " << legolist[i].pieces << endl;
}

void printstandline(int i) {
	cout << legolist[i].number << " " << legolist[i].setname << " $" << legolist[i].price << endl;
}

void partcount() {
	int total = counter;
	int taverage = average2;
	cout << "Average part count for " << total << " sets: " << taverage << endl;
}

void priceinfo(vector<legosets>& legolist) {
	cout << "Average price count for " << counter << " sets: $" << average3 << endl;

	cout << "Set with the minimum price: " << endl;
	for (size_t i = 0; i < legolist.size(); i++) {
		//int a;
		double b;
		//a = 0;
		b = 0;
		if (legolist[i].price <= b) {
			b = legolist[i].price;
			//a = i;
			printstandcolumn(i);
		}
	}
	cout << "Set with the maximum price: " << endl;
	for (size_t i = 0; i < legolist.size(); i++) {
		//int y = 0;
		double x = 0;
		if (legolist[i].price >= x) {
			x = legolist[i].price;
			//y = i;
			printstandcolumn(i);
		}
	}
}

void mostexpensive(vector<legosets>& legolist) {
	cout << "Most expensive set:" << endl;
	for (size_t i = 0; i < legolist.size(); i++) {
		//int y = 0;
		double x = 0;
		if (legolist[i].price >= x) {
			x = legolist[i].price;
			//y = i;
			printstandcolumn(i);
		}
	}
}

void largestpiece(vector<legosets>& legolist) {
	cout << "The set with the highest parts count:" << endl;
	for (size_t i = 0; i < legolist.size(); i++) {
		//int y = 0;
		double x = 0;
		if (legolist[i].pieces >= x) {
			x = legolist[i].pieces;
			//y = i;
			printstandcolumn(i);
		}
	}
}

void minifigureinfo(vector<legosets>& legolist) {
	cout << "Average number of minifigures: " << average1 << endl;
	cout << "Set with the most minifigures:" << endl;
	for (size_t i = 0; i < legolist.size(); i++) {
		//int y = 0;
		double x = 0;
		if (legolist[i].minifigs >= x) {
			x = legolist[i].minifigs;
			//y = i;
			printstandcolumn(i);
		}
	}
}

void searchforname(vector<legosets>& legolist) {
	string searcher;
	int z = 0;
	cin >> searcher;
	cin.get(); //check to see if needed
	cout << "Sets matching " << searcher << endl;
	for (size_t i = 0; i < legolist.size(); i++) {
		string name = legolist[i].setname;
		size_t found = name.find(searcher);
		if (found != string::npos) {
			printstandline(i);
			z++;
		}
	}
	if (z == 0) {
		cout << "No sets found matching that search term" << endl;
	}
}

void searchfortheme(vector<legosets>& legolist) {
	string searcher;
	cin >> searcher;
	cin.get();
	cout << "Sets matching " << searcher << endl;
	for (size_t i = 0; i < legolist.size(); i++) {
		if (legolist[i].theme == searcher) {
			printstandline(i);
		}
	}
}

void mathstuff(vector<legosets>& legolist) {
	counter = legolist.size();
	sum1 = 0;
	sum2 = 0;
	sum3 = 0;
	average1 = 0;
	average2 = 0;
	average3 = 0;
	for (size_t i = 0; i < legolist.size(); i++) {
		sum1 = legolist[i].minifigs + sum1;
		sum2 = legolist[i].pieces + sum2;
		sum3 = legolist[i].price + sum3;
	}
	average1 = sum1 / counter;
	average2 = sum2 / counter;
	average3 = sum3 / counter;
}

int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/
	if (option == 1) {
		vector<legosets> legolist;
		ReadLegos("lego1.csv", legolist);
	}
	if (option == 2) {
		vector<legosets> legolist;
		ReadLegos("lego2.csv", legolist);
	}
	if (option == 3) {
		vector<legosets> legolist;
		ReadLegos("lego3.csv", legolist);
	}
	if (option == 4) {
		vector<legosets> legolist;
		ReadLegos("lego1.csv", legolist);
		ReadLegos("lego2.csv", legolist);
		ReadLegos("lego3.csv", legolist);
	}
	mathstuff(legolist);
	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/
	/*======= Based on the choice, execute the appropriate task and show the results =======*/
	if (choice == 1) {
		mostexpensive(legolist);
	}
	if (choice == 2) {
		largestpiece(legolist);
	}
	if (choice == 3) {
		searchforname(legolist);
	}
	if (choice == 4) {
		searchfortheme(legolist);
	}
	if (choice == 5) {
		partcount();
	}
	if (choice == 6) {
		priceinfo(legolist);
	}
	if (choice == 7) {
		minifigureinfo(legolist);
	}
	if (choice == 8) {
		cout << "It would cost: $" << sum3 << endl;
		cout << "You would have " << sum2 << " pieces in your collection" << endl;
		cout << "You would have an army of " << sum1 << " mini-figures!" << endl;
	}
	if (choice == 0) {
		return 0;
	}
}