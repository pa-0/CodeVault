#pragma once
#include <string>
#include <vector>
#include "../Models/CodeSnippetModel.h"

class CodeSnippetRepository 
{
public:
	CodeSnippetRepository() {};
	std::vector<CodeSnippetModel> GetAll() const ;

	


};

