#include "Phoneme.h"
#include <algorithm>

using namespace std;

Phoneme::Phoneme(wstring symbol, set<PhonemeTypes> types) {
	this->symbol = symbol;
	this->types = types;
}

Phoneme::Phoneme(wstring symbol, initializer_list<PhonemeTypes> types) {
	this->symbol = symbol;
	this->types = types;
}

bool Phoneme::includesTypes(initializer_list<PhonemeTypes> types) const {
	set<PhonemeTypes> typeSet = types;

	return includes(this->types.begin(), this->types.end(), typeSet.begin(), typeSet.end());
}

map<string, PhonemeTypes> Phoneme::stringToTypeMap = { 
	{"consonant", CONSONANT}, {"pulmonic", PULMONIC}, {"voiced", VOICED}, {"unvoiced", UNVOICED},
	{"bilabial", BILABIAL}, {"labiodental", LABIODENTAL}, {"dental", DENTAL}, {"alveolar", ALVEOLAR}, {"postalveolar", POSTALVEOLAR}, {"retroflex", RETROFLEX}, {"alveolopalatal", ALVEOLOPALATAL}, {"palatal", PALATAL}, {"velar", VELAR}, {"uvular", UVULAR}, {"pharyngeal", PHARYNGEAL}, {"glottal", GLOTTAL},
	{"plosive", PLOSIVE}, {"sibilant", SIBILANT}, {"nonsibilant-fricative", NONSIBILANT_FRICATIVE}, {"nasal", NASAL}, {"approximant", APPROXIMANT}, {"tap", TAP}, {"trill", TRILL}, {"lateral-fricative", LATERAL_FRICATIVE}, {"lateral-approximant", LATERAL_APPROXIMANT}, {"lateral-flap", LATERAL_FLAP},
	{"affricate", AFFRICATE}, {"coarticulated", COARTICULATED},
	{"nonpulmonic", NONPULMONIC},{"click", CLICK},{"implosive", IMPLOSIVE},{"ejective", EJECTIVE},
	{"vowel", VOWEL},{"rounded", ROUNDED},{"unrounded", UNROUNDED},
	{"front", FRONT},{"near-front", NEAR_FRONT},{"central", CENTRAL},{"near-back", NEAR_BACK},{"back", BACK},
	{"close", CLOSE},{"near-close", NEAR_CLOSE},{"close-mid", CLOSE_MID},{"mid", MID},{"open-mid", OPEN_MID},{"near-open", NEAR_OPEN},{"open", OPEN},
};