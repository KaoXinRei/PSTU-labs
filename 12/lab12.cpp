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

int get_value(string str) {
    int value = 0;
    int j = 1;
    for (auto i : str) {
        value += i * j;
        j++;
    }
    return value;
}

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

bool compare(pair<int, person> x, pair<int, person> y) {
    return x.first < y.first;
}

int main() {
    srand(time(nullptr));
    vector<person> people;
    deque<pair<person, int>> deleted;
    vector<pair<int,person>> sorted_people;
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
        sorted_people.push_back(make_pair(get_value(p.name), people.back()));
    }
    sort(sorted_people.begin(), sorted_people.end(), compare);
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
        else if (input == 3){
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
                people.insert(people.begin(),p);
                sorted_people.push_back(make_pair(get_value(people.back().name), people.back()));
                sort(sorted_people.begin(), sorted_people.end(), compare);
            }
            else if (a_input == 1) {
                people.push_back(p);
                sorted_people.push_back(make_pair(get_value(people.back().name), people.back()));
                sort(sorted_people.begin(), sorted_people.end(), compare);
            }
            else if (a_input == 2) {
                cout << "Position: ";
                int pos;
                cin >> pos;
                people.insert(people.begin() + pos, p);
                sorted_people.push_back(make_pair(get_value(people.back().name), people.back()));
                sort(sorted_people.begin(), sorted_people.end(), compare);
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
                for (auto i = sorted_people.begin(); i < sorted_people.end();) {
                    if (i->second.name == key) {
                        sorted_people.erase(i);
                        break;
                    }
                    else {
                        i++;
                    }
                }
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
                people.erase(people.begin()+pos);
                for (auto i = sorted_people.begin(); i < sorted_people.end();) {
                    if (i->second.name == key) {
                        sorted_people.erase(i);
                        break;
                    }
                    else {
                        i++;
                    }
                }
            }
        }
        else if (input == 5) {
            for (auto i : people) {
                cout << i.name << ' ' << i.passport << ' ' << i.phone << endl;
            }
        }
        else if (input == 6) {
            int a_input = -1;
            cout << "0 - Interpolation search, 1 - linear search, 2 - String search\n";
            cin >> a_input;
            if (a_input == 0) {
                string key;
                cin.ignore();
                getline(cin,key);
                int left = 0;
                int right = sorted_people.size() - 1;
                int mid = left + ((get_value(key) - sorted_people[left].first) * (right - left)) / (sorted_people[right].first - sorted_people[left].first);
                while (mid <= right && mid >= left && sorted_people[mid].second.name != key && left != right) {
                    if (get_value(key) > get_value(sorted_people[mid].second.name)) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                    mid = left + ((get_value(key) - sorted_people[left].first) * (right - left)) / (sorted_people[right].first - sorted_people[left].first);
                }
                if (mid > right || mid < left || sorted_people[mid].second.name != key) {
                    cout << "No such person\n";
                }
                else {
                    cout << "Passport: " << sorted_people[mid].second.passport << endl;
                    cout << "Phone: " << sorted_people[mid].second.phone << endl;
                }
            }
            else if (a_input == 1) {
                string key;
                cin.ignore();
                getline(cin, key);
                bool found = false;
                for (auto i : people) {
                    if (i.name == key && not(found)) {
                        cout << "Passport: " << i.passport << endl;
                        cout << "Phone: " << i.phone << endl;
                        found = true;
                    }
                }
                if (not(found)) {
                    cout << "No such person\n";
                }
            }
            else if (a_input == 2) {
                string key;
                cin.ignore();
                getline(cin, key);
                for (auto i : people) {
                    for (int j = 0; j < i.name.size() - key.size(); j++) {
                        bool flag = true;
                        for (int k = j; k < j + key.size(); k++) {
                            if (key[k - j] != i.name[k]) {
                                flag = false;
                            }
                        }
                        if (flag) {
                            cout << "Name: " << i.name << endl;
                            cout << "Passport: " << i.passport << endl;
                            cout << "Phone: " << i.phone << endl;
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
                sorted_people.push_back(make_pair(get_value(deleted.back().first.name), deleted.back().first));
                sort(sorted_people.begin(), sorted_people.end(), compare);
                deleted.pop_back();
            }
        }
    }
    return 0;
}
