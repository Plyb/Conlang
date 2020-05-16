#pragma once
#include "Phoneme.h"

class PhonemeLibrary
{
public:
	PhonemeLibrary();

	std::set<Phoneme> includesTypes(unsigned int typeCount, PhonemeTypes types...);
private:
	std::set<Phoneme> allPhonemes;
};

