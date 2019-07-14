#include "pch.h"
#include "Universal.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include<boost/tokenizer.hpp>


Universal::Universal()
{
}


Universal::~Universal()
{
}

string Universal::ToLowerString(string s)
{
	string out = s;
	boost::to_lower(out);
	return out;
}




