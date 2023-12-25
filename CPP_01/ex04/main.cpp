#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int replace(char **av)
{
    std::ifstream orig_file(av[1]);
    if (orig_file.fail())
    {
        std::cerr << "Could not open file " << av[1] << std::endl;
        return (1);
    }
    if (orig_file.peek() == EOF)
    {
        std::cerr << "File " << av[1] << " is empty" << std::endl;
        orig_file.close();
        return (1);
    }
    bool only_ws = true;
    while (orig_file.peek() != EOF)
    {
        
        if (!std::isspace(orig_file.get()))
        {
            only_ws = false;
            orig_file.unget();
            break ;
        }
    }
    if (only_ws)
    {
        std::cerr << "Only whitespaces in " << av[1] << std::endl;
        orig_file.close();
        return (1);
    }
    orig_file.clear();
    orig_file.seekg(0, std::ios::beg);

    std::string rep_file_name = av[1];
    rep_file_name += ".replace";
    std::ofstream rep_file(rep_file_name.c_str());
    if (rep_file.fail())
    {
        orig_file.close();
        std::cerr << "Could not open the file " << av[1] << std::endl;
        return (1);
    }


    std::string content;
    std::string word;
    std::string rep_by = av[2];
    std::string to_rep = av[3];
    while (!orig_file.eof())
    {
        std::getline(orig_file, content);
        std::istringstream iss(content);
        while (iss >> word)
        {
            if (word == rep_by)
                rep_file << to_rep;
            else
                rep_file << word;
        }
        rep_file << std::endl;
    }
    orig_file.close();
    rep_file.close();
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 4)
        return (replace(av));
    else
        std::cout << "Wrong number of arguments!\n";
}