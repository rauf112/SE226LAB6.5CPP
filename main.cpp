#include <iostream>
using namespace std;


void commonNumbers(int a[], int x, int b[], int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (a[i] == b[j]) {
                cout << a[i] << " ";
                break;
            }
        }
    }
}



bool palindrome(const char* a) {
    int x = 0;
    while (a[x] != '\0') x++;

    for (int i = 0, j = x - 1; i < j; ++i, --j) {
        char low1 = a[i] >= 'A' && a[i] <= 'Z' ? a[i] + 32 : a[i];
        char low2 = a[j] >= 'A' && a[j] <= 'Z' ? a[j] + 32 : a[j];

        if (low1 != low2) return false;
    }
    return true;
}

void palindromes(const char* x[], int a) {
    for (int i = 0; i < a; ++i) {
        if (palindrome(x[i])) {
            cout << x[i] << " ";
        }
    }
}

bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void sieveOfEratosthenes(int x[], int a) {
    for (int i = 0; i < a; ++i) {
        if (prime(x[i])) {
            cout << x[i] << " ";
        }
    }
}


bool isAnagram(const char* x, const char* y) {
    int x_counts[26] = {0};
    int y_counts[26] = {0};

    int i = 0;
    while (x[i] != '\0') {
        char c = tolower(x[i]);
        if (c >= 'a' && c <= 'z') {
            x_counts[c - 'a']++;
        }
        i++;
    }

    i = 0;
    while (y[i] != '\0') {
        char c = tolower(y[i]);
        if (c >= 'a' && c <= 'z') {
            y_counts[c - 'a']++;
        }
        i++;
    }

    for (i = 0; i < 26; ++i) {
        if (x_counts[i] != y_counts[i]) {
            return false;
        }
    }
    return true;
}


void findAnagrams(const char* word, const char* words[], int size) {
    cout << "[";
    bool first_anagram = true;
    for (int i = 0; i < size; ++i) {
        if (isAnagram(word, words[i])) {
            if (first_anagram) {
                first_anagram = false;
            } else {
                cout << ", ";
            }
            cout << "\"" << words[i] << "\"";
        }
    }
    cout << "]";
}

int main() {
    cout << "part 1:" << endl;
    int listA[] = {5, 99, 53, 234, 531, 645, 96, 223};
    int listB[] = {77, 43, 99, 234, 5, 53, 645};
    commonNumbers(listA, 8, listB, 7);

    cout << "" << endl;
    cout << "" << endl;
    cout << "part 2:" << endl;

    const char* words[] = {"raufFuar", "Yatay", "Urla", "Edirne"};
    palindromes(words, 4);
    cout << "" << endl;
    cout << "" << endl;
    cout << "part 3:" << endl;

    int numbers[] = {99, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    sieveOfEratosthenes(numbers, 25);
    cout << "" << endl;
    cout << "" << endl;
    cout << "part 4:" << endl;

    const char* a = "listen";
    const char* anagramWords[] = {"enlists", "google", "inlets", "banana"};
    findAnagrams(a, anagramWords, 4);
    return 0;
}
