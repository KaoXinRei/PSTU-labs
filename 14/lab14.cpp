#include <iostream>
#include <list>
#include <ctime>
#include <fstream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>  

using namespace std;

struct person {
    string name;
    string passport;
    string phone;
};

void write_lines(vector<person> lines) {
    ofstream file("people.txt");
    for (auto row : lines) {
        file << row.name << ' ' << row.passport << ' ' << row.phone << endl;
    }
    file.close();
}

vector<person> read_lines() {
    ifstream file("people.txt");
    if (!file) {
        cout << "Unable to open file";
    }
    vector<person> lines;
    while (!file.eof()) {
        person per;
        string row;
        stack<string> s;
        string p = "";
        getline(file, row);
        if (row != "") {
            for (auto i : row) {
                if (i != ' ') {
                    p.push_back(i);
                }
                else {
                    s.push(p);
                    p = "";
                }
            }
            per.phone = p;
            per.passport = s.top();
            s.pop();
            string name = s.top();
            s.pop();
            name.insert(0, " ");
            name.insert(0, s.top());
            s.pop();
            name.insert(0, " ");
            name.insert(0, s.top());
            s.pop();
            per.name = name;
            lines.push_back(per);
        }
    }
    file.close();
    return lines;
}


int main() {
    srand(time(nullptr));
    vector<person> people;
    deque<pair<person, int>> deleted;
    for (int i = 0; i < 100; i++) {
        person p;
        string full_name;
        int n = rand() % 6 + 6;
        full_name.push_back(rand() % 26 + 65);
        for (int i = 0; i < n - 1; i++) {
            full_name.push_back(rand() % 26 + 97);
        }
        full_name.push_back(' ');
        n = rand() % 6 + 4;
        full_name.push_back(rand() % 26 + 65);
        for (int i = 0; i < n - 1; i++) {
            full_name.push_back(rand() % 26 + 97);
        }
        full_name.push_back(' ');
        n = rand() % 6 + 8;
        full_name.push_back(rand() % 26 + 65);
        for (int i = 0; i < n - 1; i++) {
            full_name.push_back(rand() % 26 + 97);
        }
        p.name = full_name;
        string passport;
        for (int i = 0; i < 10; i++) {
            passport.push_back(rand() % 10 + 48);
        }
        p.passport = passport;
        string phone;
        for (int i = 0; i < 10; i++) {
            phone.push_back(rand() % 10 + 48);
        }
        p.phone = phone;
        people.push_back(p);
    }
    int input = -1;
    while (input != 0) {
        cout << "0 - exit, 1 - save to file, 2 - load from file, 3 - add item, 4 - delete item, 5 - print, 6 - search, 7 - undo deletion\n";
        cin >> input;
        if (input == 1) {
            write_lines(people);
        }
        else if (input == 2) {
            people = read_lines();
        }
        else if (input == 3) {
            person p;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, p.name);
            cout << "Enter passport: ";
            cin.ignore();
            getline(cin, p.passport);
            cout << "Enter phone: ";
            cin.ignore();
            getline(cin, p.phone);
            cout << "0 - add to begining, 1 - add to end, 2 - add to specified position\n";
            int a_input;
            cin >> a_input;
            if (a_input == 0) {
                people.insert(people.begin(), p);
            }
            else if (a_input == 1) {
                people.push_back(p);
            }
            else if (a_input == 2) {
                cout << "Position: ";
                int pos;
                cin >> pos;
                people.insert(people.begin() + pos, p);
            }

        }
        else if (input == 4) {
            int a_input = -1;
            cout << "0 - by key, 1 - by position\n";
            cin >> a_input;

            if (a_input == 0) {
                string key;
                cin.ignore();
                getline(cin, key);
                int j = 0;
                for (auto i = people.begin(); i < people.end();) {
                    if (i->name == key) {
                        deleted.push_back(make_pair(*i, j));
                        if (deleted.size() > people.size() / 2) {
                            deleted.pop_front();
                        }
                        people.erase(i);
                        break;
                    }
                    else {
                        ++j;
                        ++i;
                    }
                }
            }
            else if (a_input == 1) {
                int pos;
                cin >> pos;
                string key;
                deleted.push_back(make_pair(people[pos], pos));
                if (deleted.size() > people.size() / 2) {
                    deleted.pop_front();
                }
                key = people[pos].name;
                people.erase(people.begin() + pos);
            }
        }
        else if (input == 5) {
            for (auto i : people) {
                cout << i.name << ' ' << i.passport << ' ' << i.phone << endl;
            }
        }
        else if (input == 6) {
            int a_input = -1;
            cout << "0 - Boyer-Moore string-search, 1 - Knuth-Morris-Pratt string-searching\n";
            cin >> a_input;
            if (a_input == 0) {
                string key;
                cin.ignore();
                getline(cin, key);
                int kl = key.size();
                for (auto i : people)  {
                    bool flag = false;
                    int ll = i.name.size();
                    int b[256];
                    for (int i = 0; i < 256; i++) {
                        b[i] = kl;
                    }
                    for (int i = kl - 2; i >= 0; i--) {
                        if (b[int((unsigned char)key[i])] == kl) {
                            b[int((unsigned char)key[i])] = kl - i - 1;
                        }
                    }
                    int p = kl - 1;
                    while (p < ll && not(flag)) {
                        if (key[kl - 1] != i.name[p]) {
                            p += b[int((unsigned char)i.name[p])];
                        }
                        else {
                            for (int j = kl - 1; j >= 0; j--) {
                                if (key[j] != i.name[p - kl + j + 1]) {
                                    p += b[int((unsigned char)i.name[p])];
                                    break;
                                }
                                else if (j == 0) {
                                    flag = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (flag) {
                        cout << "Name: " << i.name << endl;
                        cout << "Passport: " << i.passport << endl;
                        cout << "Phone: " << i.phone << endl;
                    }
                }
            }
            else if (a_input == 1) {
                string key;
                cin.ignore();
                getline(cin, key);
                int kl = key.size();
                for (auto i : people) {
                    string line = i.name;
                    line.insert(0, "#");
                    line.insert(0, key);
                    int ll = line.size();
                    int *pref = new int[ll];
                    pref[0] = 0;
                    for (int j = 1; j < ll; j++) {
                        int k = pref[j - 1];
                        while (k > 0 && line[j] != line[k]) {
                            k = pref[k - 1];
                        }
                        if (line[j] == line[k]) {
                            k++;
                        }
                        pref[j] = k;
                    }
                    for (int j = kl; j < ll; j++) {
                        if (pref[j] == kl) {
                            cout << "Name: " << i.name << endl;
                            cout << "Passport: " << i.passport << endl;
                            cout << "Phone: " << i.phone << endl;
                            break;
                        }
                    }
                }
            }
        }
        else if (input == 7) {
            if (deleted.empty()) {
                cout << "Nothing to undo\n";
            }
            else {
                cout << deleted.back().first.name << " returned to position " << deleted.back().second << endl;
                people.insert(people.begin() + deleted.back().second, deleted.back().first);
                deleted.pop_back();
            }
        }
    }
    return 0;
}
