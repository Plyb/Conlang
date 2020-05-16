#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>

class Phonemes
{
private:
	std::vector<std::string> phonemes;
	std::map<std::set<phonemeTypes>, std::string> allPhonemes;

public:
	Phonemes() {
		phonemes = generatePhonemes();
	}

	std::vector<std::string> generatePhonemes();
};

