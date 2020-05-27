#include "pch.h"
#include "../Conlang/Phoneme.cpp"
#include "../Conlang/PhonemeLibrary.cpp"

TEST(Phoneme, Instantiation) {
	EXPECT_NO_THROW(Phoneme(L"p", std::set<PhonemeTypes> { CONSONANT, BILABIAL, PLOSIVE }));
	EXPECT_NO_THROW(Phoneme(L"p", { CONSONANT, BILABIAL, PLOSIVE }));
	EXPECT_NO_THROW(Phoneme(L"ʈ", std::set<PhonemeTypes> { CONSONANT, BILABIAL, PLOSIVE }));
}

TEST(PhonemeLibrary, includesTypes) {
	PhonemeLibrary lib;
	EXPECT_EQ(lib.includesTypes({ BILABIAL, CONSONANT, PULMONIC, NASAL, VOICED }), std::set<Phoneme> { Phoneme(L"m", { BILABIAL, CONSONANT, PULMONIC, NASAL, VOICED }) });
}