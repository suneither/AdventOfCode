#include <iostream>
#include <vector>

using namespace std;

int current_number = 50;
int password = 0;

char ExtractDirection(const string& rotation);
int ExtractNumber(const string& rotation);
void RotateLeft(const int& number);
void RotateRight(const int& number);

int main(){

    vector<string> rotations;
    rotations.emplace_back("L68");
    rotations.emplace_back("L30");
    rotations.emplace_back("R48");
    rotations.emplace_back("L5");
    rotations.emplace_back("R60");
    rotations.emplace_back("L55");
    rotations.emplace_back("L1");
    rotations.emplace_back("L99");
    rotations.emplace_back("R14");
    rotations.emplace_back("L82");

    for (const string& rotation : rotations)
    {
        if (ExtractDirection(rotation) == 'L')
        {
            RotateLeft(ExtractNumber(rotation));
            if (current_number < 0) current_number += 100;
        }else
        {
            RotateRight(ExtractNumber(rotation));
            if (current_number >= 100) current_number -= 100;
        }

        if (current_number == 0)
            password++;
    }

    cout << password << endl;

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