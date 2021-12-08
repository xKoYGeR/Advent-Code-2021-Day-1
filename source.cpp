#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>

int main()
{
    /* LOADING DATA */
    std::fstream dataFile;
    dataFile.open("NUMBERS.txt", std::ios::in);
    std::vector <int> vecNumbers;
    if (dataFile.good())
    {
        std::string strNumLine;
        while (!dataFile.eof())
        {
            std::getline(dataFile, strNumLine);
            vecNumbers.push_back(atoi(strNumLine.c_str()));
        }
        dataFile.close();
    }
    else std::cout << "Error!" << std::endl;

    if (vecNumbers.empty())
        return 0;

    /* PART I */
    int numMeasurement = 0;
    for (int i = 1; i < vecNumbers.size(); i++)
        if (vecNumbers[i - 1] < vecNumbers[i])
            numMeasurement++;

    /* PART II */
    int numMeasurement2 = 0;
    for (int i = 1; i < vecNumbers.size() - 2; i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < 3; j++)
        {
            sum1 += vecNumbers[i - 1 + j];
            sum2 += vecNumbers[i + j];
        }
        if (sum1 < sum2)
            numMeasurement2++;
    }

    std::cout << numMeasurement << std::endl;
    std::cout << numMeasurement2 << std::endl;
    std::cin.get();
    return 0;
}
