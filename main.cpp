#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Read {

private:
    char filename[20];
    std::string data;
    void read() {
        ifstream file(this->filename, ios::binary | ios::in);
        if (file.is_open()) {
            getline(file, data, '\0');
            cout << this->data << endl;
            file.close();
        }
    }

public:
    void init() {
        cout << "enter the file name!" << endl;
        cin >> this->filename;
        this->read();
    }

};


class Write {

private:
    std::string data;
    char filename[20];
    void write() {
        cout << "enter the data" << endl;
        cin.ignore();
        getline(cin, this->data);
        ofstream file(this->filename, ios::binary | ios::out);
        if(file.is_open()) {
            file.write(this->data.c_str(), data.length() + 1);
            file.close();
            cout << "written!" << endl;
        }
    }

public:
    void init() {
        cout << "enter the file name!" << endl;
        cin >> this->filename;
        this->write();
    }


};




int main(void) {
    char option;
    Read r;
    Write w;
    system("clear");
    cout << "you wanna read binary or write binary? \n A. Read \n B. Write" << endl;
    cin >> option;
    switch (option) {
        case 'A':
            r.init();
            break;
        case 'B':
            w.init();
            break;
        default:
            cout << "choose wisely" << endl;
            break;
    }
    return 0;
}
