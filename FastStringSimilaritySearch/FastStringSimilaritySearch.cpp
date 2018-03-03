// FastStringSimilaritySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordSplitter.h"
#include "WordEditDistance.h"
#include "HammingDistance.h"
#include "LevenshteinDistance.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	WordSplitter splitter = WordSplitter();
	WordInfix* infixRoot = splitter.split("xlead", 3);

	cout << infixRoot->print();

	cout << "Splitting finished!";

	delete infixRoot;

	cout << "Calculating Hamming Distance";
	HammingDistance hdist = HammingDistance();
	WordEditDistance* dist = (WordEditDistance*) &hdist;

	string a = "lead";
	string b = "xleadx";
	
	cout << "\n Distance between " + a + " and " + b + " = " << dist->getDistance(a, b) << "\n";

	cout << "Calculating Levenshtein Distance";
	LevenshteinDistance ldist = LevenshteinDistance();
	WordEditDistance* dist2 = (WordEditDistance*)&ldist;

	cout << "\n Distance between " + a + " and " + b + " = " << dist2->getDistance(a, b);

	string input;
	std::getline(std::cin, input);

    return 0;
}

