#include <iostream>
#include <fstream>
#include <string>

void    replacefile(std::ifstream &infile, const std::string &s1, const std::string &s2, std::ofstream &outfile)
{
    std::string str = "";
    size_t i = 0;

    while (std::getline(infile, str))
    {
        i = 0;
        if (!s1.empty())
        {
            while ((i = str.find(s1, i)) != std::string::npos)
            {
                str = str.erase(i, s1.length());
                str = str.insert(i, s2);
                i += s2.length(); 
            }
        }
        outfile << str << std::endl;
    }
}
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error! Introduce [filename] [find] [replace]" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string ofilename = filename + ".replace";

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cout << "Not possible to open the inputfile: " << filename << std::endl;
        return (1);
    } 
    std::ofstream outfile(ofilename.c_str(), std::ios::out | std::ios::trunc);
    if (!outfile.is_open())
    {
        std::cout << "Not possible to open the outputfile: " << ofilename << std::endl;
        return (1);
    }
    replacefile(infile, s1, s2, outfile);
    if (!s1.empty())
        std::cout << "Replace completed" << std::endl;
    else
        std::cout << "No changes" << std::endl;
    infile.close();
    outfile.close();
    return (0);
}
