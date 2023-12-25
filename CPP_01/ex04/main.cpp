#include <iostream>
#include <string>
#include <fstream>

void    replace(std::ifstream &orig_file, std::ofstream &rep_file, 
                std::string rep_by, std::string to_rep)
{
    std::string content;
    std::size_t pos;

    while (std::getline(orig_file, content))
    {
        std::string result;
        pos = content.find(rep_by);
        if (pos != std::string::npos)
        {
            while (pos != std::string::npos)
            {
                result += content.substr(0, pos);
                result += to_rep;
                content = content.substr(pos + rep_by.size());
                pos = content.find(rep_by);
            }
            result += content;
            rep_file << result;
        }
        else
            rep_file << content;
        rep_file << std::endl;
    }
}

int prepare_files(char **av)
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
    
    std::string rep_file_name = av[1];
    rep_file_name += ".replace";
    std::ofstream rep_file(rep_file_name.c_str());
    if (rep_file.fail())
    {
        orig_file.close();
        std::cerr << "Could not open the file " << av[1] << std::endl;
        return (1);
    }

    replace(orig_file, rep_file, av[2], av[3]);
    orig_file.close();
    rep_file.close();
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 4)
        return (prepare_files(av));
    else
        std::cout << "Wrong number of arguments!\n";
}
