#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>

int main()
{
    std::fstream dataFile;
    dataFile.open("NUMBERS.txt", std::ios::in);
    std::vector <int> vecStringNumbers;
    if (dataFile.good())
    {
        std::string strNumLine;
        while (!dataFile.eof())
        {
            std::getline(dataFile, strNumLine);
            vecStringNumbers.push_back(atoi(strNumLine.c_str()));
        }
        dataFile.close();
    }
    else std::cout << "Error!" << std::endl;

    if (vecStringNumbers.empty())
        return 0;

    int numMeasurement = 0;
    for (int i = 1; i < vecStringNumbers.size(); i++)
        if (vecStringNumbers[i - 1] < vecStringNumbers[i])
            numMeasurement++;

    std::cout << numMeasurement << std::endl;
    std::cin.get();
    return 0;
}
