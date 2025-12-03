#include <iostream>
#include <fstream>

using namespace std;

int current_number = 50;
int password = 0;

char ExtractDirection(const string& rotation);
int ExtractNumber(const string& rotation);
void RotateLeft(const int& number);
void RotateRight(const int& number);
void CalculateLeftPasses(const int& number);
void CalculateRightPasses(const int& number);

int main(){

    fstream file("Input.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    string rotation;
    while (std::getline(file, rotation))
    {
        int number = ExtractNumber(rotation);
        if (ExtractDirection(rotation) == 'L')
        {
            RotateLeft(number);
            CalculateLeftPasses(number);
        }
        else
        {
            RotateRight(number);
            CalculateRightPasses(number);
        }

        if (current_number >= 100 || current_number < 0)
            current_number %= 100;

        if (current_number == 0)
            password++;
    }

    cout << password << endl;
}

void CalculateRightPasses()
{
    current_number += current_number / 100;
}

void CalculateLeftPasses(const int& number)
{
    current_number += current_number / 100;
}

char ExtractDirection(const string& rotation)
{
    return rotation.at(0);
}

int ExtractNumber(const string& rotation)
{
    return stoi( rotation.substr(1, rotation.size() - 1));
}

void RotateLeft(const int& number)
{
    current_number -= number;
}

void RotateRight(const int& number)
{
    current_number += number;
}