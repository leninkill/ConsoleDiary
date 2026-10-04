#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Welcome to Daily Planner!" << endl << "You can:" << endl << "1. Open existing diary \n 2. Create new diary" << endl << "Choose one option:" << " ";

    int input;
    cin >> input;

    if (input == 1) {
        string filename;
        getline(cin, filename);
        string filepath = R"(C:\Users\swexi\CLionProjects\ConsoleDiary\)" + filename;
        cout << filepath << endl;

        ifstream file(filepath);

        while (!file.eof()) {

        }
    }



    char buffer[255];

    return 0;
}