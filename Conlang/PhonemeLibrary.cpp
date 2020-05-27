#include "PhonemeLibrary.h"
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace std;
using convert_type = std::codecvt_utf8<wchar_t>;

set<Phoneme> PhonemeLibrary::includesTypes(std::initializer_list<PhonemeTypes> types) {

	set<Phoneme> matches;\
	for (set<Phoneme>::iterator iter = allPhonemes.begin(); iter != allPhonemes.end(); iter++) {
		if ((*iter).includesTypes(types)) {
			matches.insert(*iter);
		}
	}

	return matches;
}

PhonemeLibrary::PhonemeLibrary() {
	wifstream phonemeInput;
	phonemeInput.open("rscphonemes.txt");

	if (!phonemeInput.is_open()) {
		throw exception("Unable to open RSCPhonemes.txt. Does it exist?");
	}

	std::wstring line;
	std::wstring_convert<convert_type, wchar_t> converter;
	while (getline(phonemeInput, line)) {
		std::wstring symbol;
		std::set<PhonemeTypes> types;

		std::wstringstream lineStream(line);
		lineStream >> symbol;
		lineStream.ignore(numeric_limits<streamsize>::max(), '=');

		std::wstring type;
		while (lineStream >> type) {
			types.insert(Phoneme::stringToType(converter.to_bytes(type)));
		}

		allPhonemes.insert(Phoneme(symbol, types));
	}
}