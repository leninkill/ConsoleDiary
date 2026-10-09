#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string continueAnswer;

    do {
        cout << "Welcome to Daily Planner!" << endl << "You can:" << endl <<
                "1. Open existing diary\n2. Create new diary" << endl << "Choose one option:";

        int input;
        cin >> input;

        if (input == 1) {
            cout << "Enter file name" << " " << endl;
            string filename;
            getchar();
            getline(cin, filename);
            string filepath = R"(C:\Users\swexi\CLionProjects\ConsoleDiary\)" + filename + ".txt";
            // cout << filepath << endl;

            ifstream file(filepath);

            while (!file.is_open()) {
                cout << "Can't open this file" << endl << "Try to reenter name of the file or enter \"EXIT\":" << endl;
                getline(cin, filename);

                if (filename == "EXIT") {
                    break;
                }

                filepath = R"(C:\Users\swexi\CLionProjects\ConsoleDiary\)" + filename + ".txt";

                file.open(filepath);
            }

            if (file.is_open()) {
                cout << "Successfully opened:" << endl;

                char buffer[255];
                while (!file.eof()) {
                    file.read(buffer, 255);
                }

                cout << buffer << endl;
                file.close();

                cout << "You can:" << endl << "1. Add something to the existing file \n 2. Close the application" <<
                        endl << "Choose one option:";
                cin >> input;

                if (input == 1) {
                    ofstream file(filepath, ios::app);

                    cout << "Write what do you want in this diary: " << endl << "Enter \"EXIT\" for leave: " << endl;

                    string s;
                    while (s != "EXIT") {
                        getline(cin, s);

                        if (s != "EXIT") {
                            file << s << "\n";
                        }
                    }

                    file.close();
                }
            }
        } else if (input == 2) {
            cout << "Enter name for new diary:" << endl;
            string filename;
            getchar();
            getline(cin, filename);

            string filepath = R"(C:\Users\swexi\CLionProjects\ConsoleDiary\)" + filename + ".txt";

            cout << "Current path is:\n" << filepath << endl;

            ofstream file(filepath);

            cout << "Write what do you want in this diary: " << endl << "Enter \"EXIT\" for leave: " << endl;

            string s;
            while (s != "EXIT") {
                getline(cin, s);

                if (s != "EXIT") {
                    file << s << "\n";
                }
            }

            file.close();
        }
        cout << R"(If you want to do something else, then enter "YES", else enter "NO": )" << endl;
        getline(cin, continueAnswer);
    } while (continueAnswer == "YES");

        return 0;
    }
