// FastStringSimilaritySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordSplitter.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	WordSplitter splitter = WordSplitter();
	WordInfix* infixRoot = splitter.split("xlead", 4);

	cout << infixRoot->print();

	cout << "Splitting finished!";
	string input;
	std::getline(std::cin, input);

	delete infixRoot;

    return 0;
}

