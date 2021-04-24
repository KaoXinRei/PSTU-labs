#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <list>

using namespace std;

const string temp_path = "/temp/"; //may be different for other OS(this works in windows)

void make_file(const char *f_name, queue<int> &q, int state) {
    fstream stream(f_name, ios::out | ios::trunc);
    stream << state << '\n';
    while (!q.empty()) {
        stream << q.front() << '\n';
        q.pop();
    }
    stream.close();
}

int natural_split(const char *name) {
    fstream read_stream(name, ios::in);
    int a, b, i = 0;
    bool ascend, stop = true;
    read_stream >> a;
    queue<int> q;
    q.push(a);
    b = a;
    while (read_stream >> a) {
        if (stop) {
            q.push(a);
            ascend = a > b;
            stop = false;
            b = a;
        } else {
            if (ascend != (a > b)) {
                if (ascend) {
                    string s_name = temp_path + "temp" + to_string(i);
                    make_file(s_name.c_str(), q, 1);
                } else {
                    string s_name = temp_path + "temp" + to_string(i);
                    make_file(s_name.c_str(), q, -1);
                }
                stop = true;
                q.push(a);
                b = a;
                ++i;
            } else {
                q.push(a);
                b = a;
            }
        }
    }
    string s_name = temp_path + "temp" + to_string(i);
    if (ascend) {
        make_file(s_name.c_str(), q, 1);
    } else {
        make_file(s_name.c_str(), q, -1);
    }
    read_stream.close();
    return i + 1;
}

void first_level_natural_merge(const char *first_file, const char *second_file, const char *destination_file) {
    fstream stream1(first_file, ios::in);
    fstream stream2(second_file, ios::in);
    fstream dest_stream(destination_file, ios::out);
    int a, b;
    stream1 >> a;
    stream2 >> b;
    list<int> q1, q2;
    int in;
    stream1 >> in;
    if (a == 1) {
        while (!stream1.eof()) {
            q1.push_back(in);
            stream1 >> in;
        }
    } else {
        while (!stream1.eof()) {
            q1.push_front(in);
            stream1 >> in;
        }
    }
    stream2 >> in;
    if (b == 1) {
        while (!stream2.eof()) {
            q2.push_back(in);
            stream2 >> in;
        }
    } else {
        while (!stream2.eof()) {
            q2.push_front(in);
            stream2 >> in;
        }
    }
    while ((!q1.empty()) && (!q2.empty())) {
        if (q1.front() < q2.front()) {
            dest_stream << q1.front() << '\n';
            q1.pop_front();
        } else {
            dest_stream << q2.front() << '\n';
            q2.pop_front();
        }
    }
    while (!q1.empty()) {
        dest_stream << q1.front() << '\n';
        q1.pop_front();
    }
    while (!q2.empty()) {
        dest_stream << q2.front() << '\n';
        q2.pop_front();
    }
    stream1.close();
    stream2.close();
    dest_stream.close();
    remove(first_file);
    remove(second_file);
}

void levitate_first_level(const char *first_file, const char *second_file) {
    fstream stream1(first_file, ios::in);
    fstream stream2(second_file, ios::out);
    int a;
    stream1 >> a;
    list<int> q;
    int in;
    stream1 >> in;
    if (a == 1) {
        while (!stream1.eof()) {
            q.push_back(in);
            stream1 >> in;
        }
    } else {
        while (!stream1.eof()) {
            q.push_front(in);
            stream1 >> in;
        }
    }
    while (!q.empty()) {
        stream2 << q.front() << '\n';
        q.pop_front();
    }
    stream1.close();
    stream2.close();
    remove(first_file);
}

void general_merge(const char *first_file, const char *second_file, const char *destination_file) {
    fstream stream1(first_file, ios::in);
    fstream stream2(second_file, ios::in);
    fstream dest_stream(destination_file, ios::out);
    int a, b;
    stream1 >> a;
    stream2 >> b;
    while (!stream1.eof() && !stream2.eof()) {
        if (a < b) {
            dest_stream << a << '\n';
            stream1 >> a;
        } else {
            dest_stream << b << '\n';
            stream2 >> b;
        }
    }
    while (!stream1.eof()) {
        dest_stream << a << '\n';
        stream1 >> a;
    }
    while (!stream2.eof()) {
        dest_stream << b << '\n';
        stream2 >> b;
    }
    stream1.close();
    stream2.close();
    dest_stream.close();
    remove(first_file);
    remove(second_file);
}

void natural_merge(const char *input_file, const char *destination_file) {
    int n = natural_split(input_file);
    for (int i = 0; i < n - 1; i += 2) {
        first_level_natural_merge((temp_path + "temp" + to_string(i)).c_str(),
                                  (temp_path + "temp" + to_string(i + 1)).c_str(),
                                  (temp_path + "temp1_" + to_string(i / 2)).c_str());
    }
    if (n % 2 == 1) {
        levitate_first_level((temp_path + "temp" + to_string(n - 1)).c_str(),
                             (temp_path + "temp1_" + to_string(n / 2)).c_str());
    }
    n = ceil(double(n) / 2.0);
    int depth = 1;
    while (n != 1) {
        for (int i = 0; i < n - 1; i += 2) {
            general_merge((temp_path + "temp" + to_string(depth) + "_" + to_string(i)).c_str(),
                          (temp_path + "temp" + to_string(depth) + "_" + to_string(i + 1)).c_str(),
                          (temp_path + "temp" + to_string(depth + 1) + "_" + to_string(i / 2)).c_str());
        }
        if (n % 2 == 1) {
            rename((temp_path + "temp" + to_string(depth) + "_" + to_string(n - 1)).c_str(),
                   (temp_path + "temp" + to_string(depth + 1) + "_" + to_string(n / 2)).c_str());
        }
        n = ceil(double(n) / 2.0);
        ++depth;
    }
    rename((temp_path + "temp" + to_string(depth) + "_0").c_str(), destination_file);
}

int balanced_split(const char *name) {
    int n = 0;
    fstream read_stream(name, ios::in);
    fstream write_stream(temp_path + "temp0", ios::out);
    int e;
    while (read_stream >> e) {
        if (n % 2 == 0) {
            write_stream.close();
            write_stream.open((temp_path + "temp" + to_string(n / 2)).c_str(), ios::out);
        }
        write_stream << e << '\n';
        ++n;
    }
    return int(ceil(double(n) / 2.0));
}

void first_level_balanced_merge(const char *first_file, const char *second_file, const char *destination_file) {
    priority_queue<int, vector<int>, greater<>> input;
    fstream stream1(first_file, ios::in);
    fstream stream2(second_file, ios::in);
    fstream dest_stream(destination_file, ios::out);
    int n;
    while (stream1 >> n) {
        input.push(n);
    }
    while (stream2 >> n) {
        input.push(n);
    }
    while (!input.empty()) {
        dest_stream << input.top() << '\n';
        input.pop();
    }
    stream1.close();
    stream2.close();
    dest_stream.close();
    remove(first_file);
    remove(second_file);
}

void balanced_merge(const char *input_file, const char *destination_file) {
    int n = balanced_split(input_file);
    for (int i = 0; i < n - 1; i += 2) {
        first_level_balanced_merge((temp_path + "temp" + to_string(i)).c_str(),
                                   (temp_path + "temp" + to_string(i + 1)).c_str(),
                                   (temp_path + "temp1_" + to_string(i / 2)).c_str());
    }
    if (n % 2 == 1) {
        levitate_first_level((temp_path + "temp" + to_string(n - 1)).c_str(),
                             (temp_path + "temp1_" + to_string(n / 2)).c_str());
    }
    n = ceil(double(n) / 2.0);
    int depth = 1;
    while (n != 1) {
        for (int i = 0; i < n - 1; i += 2) {
            general_merge((temp_path + "temp" + to_string(depth) + "_" + to_string(i)).c_str(),
                          (temp_path + "temp" + to_string(depth) + "_" + to_string(i + 1)).c_str(),
                          (temp_path + "temp" + to_string(depth + 1) + "_" + to_string(i / 2)).c_str());
        }
        if (n % 2 == 1) {
            rename((temp_path + "temp" + to_string(depth) + "_" + to_string(n - 1)).c_str(),
                   (temp_path + "temp" + to_string(depth + 1) + "_" + to_string(n / 2)).c_str());
        }
        n = ceil(double(n) / 2.0);
        ++depth;
    }
    rename((temp_path + "temp" + to_string(depth) + "_0").c_str(), destination_file);
}

int main() {
    //natural_merge("test", "result");
    //balanced_merge("test", "result")
}
