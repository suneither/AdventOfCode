#include <iostream>
#include <fstream>

using namespace std;

int current_number = 50;
int password = 0;

char ExtractDirection(const string& rotation);
int ExtractNumber(const string& rotation);

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
        while (number != 0)
        {
            switch (ExtractDirection(rotation))
            {
            case 'L':
                {
                    current_number--;
                    break;
                }
            case 'R':
                {
                    current_number++;
                    break;
                }
            default: break;
            }

            number--;

            if (current_number == -100 ||
                current_number == 0 ||
                current_number == 100)
            {
                password++;
                current_number = 0;
            }
        }
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
