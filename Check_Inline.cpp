#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("Inline_func.exe", ios::binary); // Open the file in binary mode

    if (file) { 
        file.seekg(0, ios::end);
        size_t filesize = file.tellg(); // Get the position, which is the size
        file.close();

        cout << "File size of  Inline_func.cpp  is " << filesize << " bytes." << endl;
    } else {
        cout << "File not found or unable to open: " << endl;
        return 1; // Indicate failure by returning a non-zero value
    }

    return 0;
}