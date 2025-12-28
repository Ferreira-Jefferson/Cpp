#include <string>

std::string replace(std::string& toReplace, std::string& replacer, std::string content) {
	size_t pos = 0;

	while (true)
	{
		pos = content.find(toReplace, pos);
		if (pos == std::string::npos)
			break ;		
		content.erase(pos, toReplace.length());
		content.insert(pos, replacer);
		pos += replacer.length();
	}
	return (content);
}