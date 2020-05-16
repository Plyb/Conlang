#include "Phoneme.h"
#include <algorithm>

using namespace std;

Phoneme::Phoneme(std::wstring symbol, std::set<PhonemeTypes> types) {
	this->symbol = symbol;
	this->types = types;
}

Phoneme::Phoneme(std::wstring symbol, unsigned int typeCount, PhonemeTypes ...) {
	va_list types;
	va_start(types, typeCount);
	set<PhonemeTypes> typeSet;
	for (unsigned int i = 0; i < typeCount; i++) {
		typeSet.insert(va_arg(types, PhonemeTypes));
	}
	va_end(types);

	this->symbol = symbol;
	this->types = typeSet;
}

bool Phoneme::includesTypes(unsigned int typeCount, PhonemeTypes ...) const {
	va_list inputTypes;
	va_start(inputTypes, typeCount);
	set<PhonemeTypes> inputTypeSet;
	for (unsigned int i = 0; i < typeCount; i++) {
		inputTypeSet.insert(va_arg(inputTypes, PhonemeTypes));
	}
	va_end(inputTypes);

	return includes(types.begin(), types.end(), inputTypeSet.begin(), inputTypeSet.end());
}

const map<string, PhonemeTypes> Phoneme::stringToTypeMap = { 
	{"consonant", CONSONANT}, {"pulmonic", PULMONIC}, {"voiced", VOICED}, {"unvoiced", UNVOICED},
	{"bilabial", BILABIAL}, {"labiodental", LABIODENTAL}, {"dental", DENTAL}, {"alveolar", ALVEOLAR}, {"palatoalveolar", PALATOALVEOLAR}, {"retroflex", RETROFLEX}, {"alveolopalatal", ALVEOLOPALATAL}, {"palatal", PALATAL}, {"velar", VELAR}, {"uvular", UVULAR}, {"pharyngeal", PHARYNGEAL}, {"glottal", GLOTTAL},
	{"plosive", PLOSIVE}, {"fricative", FRICATIVE}, {"nasal", NASAL}, {"approximant", APPROXIMANT}, {"tap", TAP}, {"trill", TRILL}, {"lateral-fricative", LATERAL_FRICATIVE}, {"lateral-approximant", LATERAL_APPROXIMANT}, {"lateral-flap", LATERAL_FLAP},
	{"affricate", AFFRICATE}, {"coarticulated", COARTICULATED},
	{"nonpulmonic", NONPULMONIC},{"click", CLICK},{"implosive", IMPLOSIVE},{"ejective", EJECTIVE},
	{"vowel", VOWEL},{"rounded", ROUNDED},{"unrounded", UNROUNDED},
	{"front", FRONT},{"near-front", NEAR_FRONT},{"central", CENTRAL},{"near-back", NEAR_BACK},{"back", BACK},
	{"close", CLOSE},{"near-close", NEAR_CLOSE},{"close-mid", CLOSE_MID},{"mid", MID},{"open-mid", OPEN_MID},{"near-open", NEAR_OPEN},{"open", OPEN},
};