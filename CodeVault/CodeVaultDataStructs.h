#pragma once
#include <iostream>
#include <string>

enum class ProgrammingLanguage {
	Python,
	C,
	Cplusplus,
	Csharp,
	Java,
	Javascript,
	Count
};

inline ProgrammingLanguage getProgrammingLanguageFromIndex(int index) {
	if (index < 0 || index >= static_cast<int>(ProgrammingLanguage::Count)) {
		throw std::out_of_range("Invalid index for ProgrammingLanguage enum");
	}
	return static_cast<ProgrammingLanguage>(index);
}
inline std::string programmingLanguageToString(ProgrammingLanguage lang) {
	switch (lang) {
	case ProgrammingLanguage::Python: return "Python";
	case ProgrammingLanguage::C: return "C";
	case ProgrammingLanguage::Cplusplus: return "C++";
	case ProgrammingLanguage::Csharp: return "C#";
	case ProgrammingLanguage::Java: return "Java";
	case ProgrammingLanguage::Javascript: return "Javascript";
	default: return "Unknown";
	}
}