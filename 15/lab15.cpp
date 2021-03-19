#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int inter_search(list<int> l, int key, int start = 0) {
    int left = start;
    int right = l.size() - 1;
    if (left == right) {
        return left + 1;
    }
    auto begin = l.begin();
    auto end = l.end();
    end--;
    for (int i = 0; i < start; i++) {
        begin++;
    }
    if (key < *begin) {
        return left;
    }
    if (key > *end) {
        return right + 1;
    }
    auto index = l.begin();
    if (*end == *begin) {
        return left;
    }
    int mid = left + (key - *begin) * (right - left) / (*end - *begin);
    if (mid > right) {
        return right + 1;
    }
    if (mid < left) {
        return left;
    }
    for (int i = 0; i < mid; i++) {
        index++;
    }
    while (left != right && mid >= left && mid <= right) {
        if (key > *index) {
            for (int i = left; i < mid; i++) {
                begin++;
            }
            if (left == mid) {
                left++;
                begin++;
            }
            else {
                left = mid;
            }
        }
        else if (key < *index) {
            for (int i = right; i > mid ; i--) {
                end--;
            }
            if (right == mid) {
                right--;
                end--;
            }
            else {
                right = mid;
            }
        }
        else {
            return mid;
        }
        if (right == left) {
            return left;
        }
        int n_mid = left + (key - *begin) * (right - left) / (*end - *begin);
        if (n_mid > right) {
            return right + 1;
        }
        if (n_mid < left) {
            return left;
        }
        for (int i = mid; i < n_mid; i++) {
            index++;
        }
        for (int i = mid; i > n_mid; i--) {
            index--;
        }
        mid = n_mid;
    }
    if (key > *index) {
        return left;
    }
    else {
        return mid;
    }
}

list<int> read_list() {
    list<int> a;
    string line;
    getline(cin, line);
    int length = line.size();
    int number = 0;
    bool neg = false;
    for (int i = 0; i < length; i++) {
        if (line[i] != ' ') {
            if (line[i] == '-') {
                neg = true;
            }
            else {
                number = number * 10 + (int(line[i]) - 48);
            }
        }
        else {
            if (neg) {
                number *= -1;
                neg = false;
            }
            a.push_back(number);
            number = 0;
        }
    }
    if (neg) {
        number *= -1;
        neg = false;
    }
    a.push_back(number);
    number = 0;
    return a;
}

int main()
{
    list<int> a, b, c;
    cout << "Enter three sorted arrays of ints to merge:\n";
    string line;
    a = read_list();
    b = read_list();
    c = read_list();
    int start = 0;
    for (auto i : b) {
        start = inter_search(a, i, start);
        auto iter = a.begin();
        for (int j = 0; j < start; j++) {
            iter++;
        }
        a.insert(iter, i);
    }
    start = 0;
    for (auto i : c) {
        start = inter_search(a, i, start);
        auto iter = a.begin();
        for (int j = 0; j < start; j++) {
            iter++;
        }
        a.insert(iter, i);
    }
    for (auto i : a) {
        cout << i << ' ';
    }
}
