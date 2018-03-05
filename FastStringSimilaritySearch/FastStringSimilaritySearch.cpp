// FastStringSimilaritySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordSplitter.h"
#include "WordEditDistance.h"
#include "HammingDistance.h"
#include "LevenshteinDistance.h"
#include "InfixTreeSearcher.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	string a = "lead";
	string b = "xleadx";

	WordSplitter splitter = WordSplitter();
	WordInfix infixRoot = splitter.split(b, 3);

	cout << infixRoot.print();

	cout << "Splitting finished!";

	//delete infixRoot;

	cout << "Calculating Hamming Distance";
	HammingDistance hdist = HammingDistance();
	WordEditDistance* dist = (WordEditDistance*) &hdist;

	
	cout << "\n Distance between " + a + " and " + b + " = " << dist->getDistance(a, b) << "\n";

	cout << "Calculating Levenshtein Distance";
	LevenshteinDistance ldist = LevenshteinDistance();
	WordEditDistance* dist2 = (WordEditDistance*)&ldist;

	cout << "\n Distance between " + a + " and " + b + " = " << dist2->getDistance(a, b);

	InfixTreeSearcher searcher = InfixTreeSearcher();
	searcher.search(&infixRoot,10);

	string input;
	std::getline(std::cin, input);

    return 0;
}

