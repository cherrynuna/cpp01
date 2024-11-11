#include <iostream>
#include <fstream>
#include <cstring>

bool	replace(char *infile, std::string s1, std::string s2)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		outfile;
	std::string		content;
	std::size_t 	s1_len = s1.length();

	if (s1_len == 0)
	{
		std::cerr << "error: empty string" << std::endl; 
		return (false);
	}
	ifs.open(infile);
	if (ifs.fail())
	{
		std::cerr << "open error" << std::endl; 
		return (false);
	}
	outfile = infile;
	outfile += ".replace";
	ofs.open(outfile.c_str());//open이 c스타일 문자열을 인자로 요한다
	if (ofs.fail())
	{
		std::cerr << "open error" << std::endl;
		ifs.close();
		return (false);
	}

	while (std::getline(ifs, content))
	{
		size_t	pos = 0;

		while ((pos =  content.find(s1, pos)) != std::string::npos)
		{
			content.erase(pos, s1_len);
			content.insert(pos, s2);
		}
		ofs << content;
		if (!ifs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (true);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "I take three parameters!" << std::endl; 
		return (1);
	}

	if (replace(av[1], av[2], av[3]) == false)
		return (1);

	return (0);
}
