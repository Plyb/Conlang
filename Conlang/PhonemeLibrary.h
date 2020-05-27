#pragma once
#include "Phoneme.h"

class PhonemeLibrary
{
public:
	PhonemeLibrary();

	std::set<Phoneme> includesTypes(std::initializer_list<PhonemeTypes> types);
private:
	std::set<Phoneme> allPhonemes;
};

