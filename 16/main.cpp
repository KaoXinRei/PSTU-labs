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
    fstream dest_stream(destination_file, ios::out | ios::trunc);
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
    priority_queue<int, vector<int>, greater<>> q;
    int e;
    while (read_stream >> e) {
        if (n % 2 == 0 && !q.empty()) {
            write_stream.close();
            write_stream.open((temp_path + "temp" + to_string(n / 2 - 1)).c_str(), ios::out);
            write_stream << q.top() << '\n';
            q.pop();
            write_stream << q.top() << '\n';
            q.pop();
            write_stream.close();
        }
        q.push(e);
        ++n;
    }
    if (!q.empty()) {
        write_stream.open((temp_path + "temp" + to_string(n / 2 - 1)).c_str(), ios::out);
        write_stream << q.top() << '\n';
        q.pop();
        if (!q.empty()) {
            write_stream << q.top() << '\n';
            q.pop();
        }
        write_stream.close();
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
        rename((temp_path + "temp" + to_string(n - 1)).c_str(),
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

void polyphase_merge(const char *input_file, const char *destination_file) {
    fstream input(input_file, ios::in);
    fstream f1(temp_path + "poly_temp1", ios::out);
    fstream f2(temp_path + "poly_temp_temp2", ios::out);
    fstream f3(temp_path + "poly_temp_temp3", ios::out);
    int n, i = 0;
    while (input >> n) {
        f1 << n << '\n';
        ++i;
    }
    f1.close();
    int fib1 = 1, fib2 = 1, res1 = 1, res2 = 1;
    while (fib2 < sqrt(i)) {
        int tmp = fib2;
        fib2 += fib1;
        fib1 = tmp;
        if (i / fib2 * fib2 == i) {
            res1 = fib2 - fib1;
            res2 = fib1;
        }
    }
    f1.open(temp_path + "poly_temp1", ios::in);
    for (int j = 0; j < i / res2; ++j) {
        f1 >> n;
        f2 << n << '\n';
    }
    f2.close();
    balanced_merge((temp_path + "poly_temp_temp2").c_str(), (temp_path + "poly_temp2").c_str());
    remove((temp_path + "poly_temp_temp2").c_str());
    while (f1 >> n) {
        f3 << n << '\n';
    }
    f3.close();
    balanced_merge((temp_path + "poly_temp_temp3").c_str(), (temp_path + "poly_temp3").c_str());
    remove((temp_path + "poly_temp_temp3").c_str());
    f1.close();
    string file_in1 = "poly_temp2";
    string file_in2 = "poly_temp3";
    string file_out = "poly_temp1";
    int size = i / res2;
    while (res1 != 0) {
        size = size * res1 / res2;
        fstream in(temp_path + file_in1, ios::in);
        fstream tmp1(temp_path + "poly_temp_temp1", ios::out | ios::trunc);
        fstream tmp2(temp_path + "poly_temp_temp2", ios::out | ios::trunc);
        for (int j = 0; j < size; ++j) {
            in >> n;
            tmp1 << n << '\n';
        }
        while (in >> n) {
            tmp2 << n << '\n';
        }
        in.close();
        tmp1.close();
        tmp2.close();
        remove((temp_path + file_in1).c_str());
        general_merge((temp_path + "poly_temp_temp1").c_str(), (temp_path + file_in2).c_str(),
                      (temp_path + file_out).c_str());
        remove((temp_path + file_in2).c_str());
        rename((temp_path + "poly_temp_temp2").c_str(), (temp_path + file_in1).c_str());
        string str_tmp1 = file_in1;
        file_in1 = file_out;
        string str_tmp2 = file_in2;
        file_in2 = str_tmp1;
        file_out = str_tmp2;
        int tmp = res2;
        res2 = res1;
        res1 = tmp - res2;
    }
    general_merge((temp_path+file_in1).c_str(), (temp_path+file_in2).c_str(), destination_file);
};

int main() {
    //natural_merge("test", "result");
    //balanced_merge("test", "result");
    polyphase_merge("test1", "result");
}
