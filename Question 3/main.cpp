// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool find_substring(const string& word_to_find, const string& target);

int main() {
    ifstream in_file;
    string word_to_find;
    string word_read;
    int word_count = 0;
    int match_count = 0;

    in_file.open("romeoandjuliet.txt");
    if (!in_file) {
        cerr << "Error opening file" << endl;
        return 0;
    }

    cout << "Enter substring to search for: ";
    cin >> word_to_find;
    while (in_file >> word_read) {
        ++word_count;
        if (find_substring(word_to_find, word_read)) {
            ++match_count;
            cout << word_read << " ";
        }
    }

    cout << " words searched: " << word_count << endl;
    cout << "Substring \"" << word_to_find << "\" was found " << match_count << " times " << endl;

   
    cout << endl;
    return 0;
}

bool find_substring(const string& word_to_find, const string& target) {
    size_t found = target.find(word_to_find);
    if (found == string::npos)
        return false;
    else
        return true;
}

