
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<algorithm>
#include<Windows.h>

/*template<>

//Hash creada a partir del ejemplo del pdf de unordered_map
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(std::pair<std::string, std::string> &a) const {
		return((std::hash<std::string>()(a.first)
			^ (std::hash<std::string>()(a.second) << 1)) >> 1);
	}
};*/