#pragma once
#include <string>
#include <vector>
#include "Man.h"

class Common {

protected:
	Man nameSurname;

public:
	virtual std::string ToShortString() = 0;
	virtual std::string ToString() = 0;
	void search(std::string fam) {};

	const bool operator == (Man manr);

	static bool has_number(const std::string& s)
	{
		/*
		std::string::const_iterator it = s.begin();
		while (it != s.end()) {
			if (std::isdigit(*it)) return true;
			++it;
		}
		return false;
		*/
		if (s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷øùüûúışÿ") != std::string::npos)
		{
			return true;
		}
		else return false;
	}

	static bool is_number(const std::string& s)
	{
		std::string::const_iterator it = s.begin();
		while (it != s.end() && std::isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
	}
};