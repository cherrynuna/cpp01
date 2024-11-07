#include <iostream>
#include <fstream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "I take three parameters!" << std::endl; 
		return (1);
	}

	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		outfile;
	std::string		content;
	std::string		s1;
	std::string		s2;
	int s1_len;
	int s2_len;

	s1 = av[2];
	s2 = av[3];
	s1_len = s1.length();
	s2_len = s2.length();
	if (std::strlen(av[1]) == 0 || s1_len == 0 || s2_len == 0)
	{
		std::cout << "error: empty string" << std::endl; 
		return (1);
	}
	ifs.open(av[1]);
	if (ifs.fail())
	{
		std::cout << "open error" << std::endl; 
		return (1);
	}
	outfile = av[1];
	outfile.append(".replace");
	ofs.open(outfile.c_str());
	if (ofs.fail())
	{
		std::cout << "open error" << std::endl; 
		return (1);
	}

	while (1)
	{
		std::getline(ifs, content);

		size_t	pos = 0;
		while (1)
		{
			pos =  content.find(s1, pos);
			if (pos == std::string::npos)//no position
				break;
			content.erase(pos, s1_len);
			content.insert(pos, s2);
			pos += s2_len;
		}
		ofs << content;
		if (ifs.eof())
			break;
		ofs << std::endl;
	}

	return (0);
}
