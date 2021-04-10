#include <iostream>
#include "Pair.h"
#include <fstream>
#include "file_work.h"
#include <string>

using namespace std;

int main() {
    Pair p, a;
    int k, c;
    char file_name[30];
    do {
        cout << "1. Make file, 2. Print file, 3. Delete pair from file, 4. Increase pairs, 5. Add pairs, 0. Exit\n";
        cin >> c;
        switch (c) {
            case 1:
                cout << "File name? ";
                cin >> file_name;
                k = make_file(file_name);
                if (k < 0) cout << "Can't make file";
                break;
            case 2:
                cout << "File name? ";
                cin >> file_name;
                k = print_file(file_name);
                if (k == 0)cout << "Empty file\n";
                if (k < 0)cout << "Can't read file\n";
                break;
            case 3:
                cout << "File name? ";
                cin >> file_name;
                cin >> p;
                k = del_file(file_name, p);
                if (k < 0)cout << "Can't read file";
            case 4:
                cout << "File name? ";
                cin >> file_name;
                cout << "What pairs to increase?\n";
                cin >> p;
                cout << "By what amount?\n";
                cin >> a;
                k = increase_file(file_name, p, a);
                if (k == -1) cout << "Can't open file\n";
                if (k == 0) cout << "No such pairs\n";
                break;
            case 5:
                cout << "File name? ";
                cin >> file_name;
                int n, s;
                cout << "After what position pairs should be added? ";
                cin >> n;
                cout << "How many pairs to add? ";
                cin >> s;
                Pair *items = new Pair[s];
                for (int i = 0; i < s; ++i) {
                    cin >> items[i];
                }
                k = add_file(file_name, n, s, items);
                if (k==-1) cout << "Can't open file\n";
                break;
        }
    } while (c != 0);
}

