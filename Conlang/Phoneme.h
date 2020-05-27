#pragma once
#include <set>
#include <map>
#include <string>
#include <cstdarg>
#include <initializer_list>

enum PhonemeTypes { CONSONANT, PULMONIC, VOICED, UNVOICED, 
	BILABIAL, LABIODENTAL, DENTAL, ALVEOLAR, POSTALVEOLAR, RETROFLEX, ALVEOLOPALATAL, PALATAL, VELAR, UVULAR, PHARYNGEAL, GLOTTAL,
	PLOSIVE, SIBILANT, NONSIBILANT_FRICATIVE, NASAL, APPROXIMANT, TAP, TRILL, LATERAL_FRICATIVE, LATERAL_APPROXIMANT, LATERAL_FLAP, 
	AFFRICATE, COARTICULATED,
	NONPULMONIC, CLICK, IMPLOSIVE, EJECTIVE, //For economy, clicks should be encoded as Bilabial, Dental, Retroflex, Palatal, or "Lateral Frivative"
	VOWEL, ROUNDED, UNROUNDED,
	FRONT, NEAR_FRONT, CENTRAL, NEAR_BACK, BACK,
	CLOSE, NEAR_CLOSE, CLOSE_MID, MID, OPEN_MID, NEAR_OPEN, OPEN
};

class Phoneme
{
public:
	Phoneme(std::wstring symbol, std::initializer_list<PhonemeTypes> types);
	Phoneme(std::wstring symbol, std::set<PhonemeTypes> types);

	bool includesTypes(std::initializer_list<PhonemeTypes> types) const;

	std::wstring getSymbol() const {
		return symbol;
	}

	static PhonemeTypes stringToType(std::string string) {
		return stringToTypeMap[string];
	}

	bool operator<(const Phoneme& other) const {
		return symbol < other.getSymbol();
	}

	bool operator==(const Phoneme& other) const {
		return symbol == other.getSymbol();
	}
private:
	std::set<PhonemeTypes> types;
	std::wstring symbol;

	static std::map<std::string, PhonemeTypes> stringToTypeMap;
};

