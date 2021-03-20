#include <iostream>
#include <ctime>
#include <string>
#include <math.h> 

using namespace std;

struct person {
    string name;
    string passport;
    string phone;
};

struct h_person {
    person current;
    h_person* next;
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

int hash_func(string key, int size) {
    double f;
    return int(size * modf(get_value(key) * 0.803523421, &f));
}

pair<h_person**, int> make_table(person* items, int n, int size) {
    h_person** table = new h_person * [size];
    for (int i = 0; i < size; i++) {

        table[i] = nullptr;
    }
    int n_of_collisions = 0;
    for (int i = 0; i < n; i++) {
        int hash = hash_func(items[i].name, size);
        if (table[hash] == nullptr) {
            h_person* p = new h_person;
            p->current = items[i];
            p->next = nullptr;
            table[hash] = p;
        }
        else {
            n_of_collisions++;
            h_person* current = table[hash];
            while (current->next != nullptr) {
                current = current->next;
            }
            h_person* p = new h_person;
            p->current = items[i];
            p->next = nullptr;
            current->next = p;
        }
    }
    return make_pair(table, n_of_collisions);
}

int main()
{
    int n;
    cout << "How many people to generate? ";
    cin >> n;
    person* people = new person[n];
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
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
        people[i] = p;
    }
    cout << "Enter hash table size: ";
    int size;
    cin >> size;
    auto table = make_table(people, n, size);
    cout << "Number of collisions: " << table.second << endl;
    int input = -1;
    while (input != 0) {
        cout << "0 - exit, 1 - print, 2 - search, 3 - regenerate hash table\n";
        cin >> input;
        if (input == 1) {
            for (int i = 0; i < n; i++) {
                cout << people[i].name << ' ' << people[i].passport << ' ' << people[i].phone << endl;
            }
        }
        else if (input == 2) {
            string key;
            cin.ignore();
            getline(cin, key);
            int hash = hash_func(key, size);
            h_person* current = table.first[hash];
            if (current != nullptr) {
                while (current->current.name != key && current->next != nullptr) {
                    current = current->next;
                }
                if (current->current.name == key) {
                    cout << "Passport: " << current->current.passport << endl;
                    cout << "Phone: " << current->current.phone << endl;
                }
                else {
                    cout << "No such person" << endl;
                }
            }
            else {
                cout << "No such person" << endl;
            }
        }
        else if (input == 3) {
            cout << "Enter new size: ";
            cin >> size;
            auto table = make_table(people, n, size);
            cout << "Number of collisions: " << table.second << endl;
        }
    }
}
