#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cstdlib>


using std::cin;
using std::cout;



void create_files (char* name_files) {  // creates a text file

    std::ofstream out_file(name_files);  //opens a file
    
    if (!out_file) {
        std::cout << "Failid to open file! \n";
    }

    out_file << "aslidgvlawiufhvpwrhvwqoihoHello, world!GLjih;iohsdvoinsf[ab\n";  // writes text to a file

    out_file.close();   // closes the file

}

int number_char_in_file (char* name_file) { // counts the number of characters in the file

    std::ifstream file (name_file);
    if (!file) {
        std::cout << "Failid to open file! \n";
    }
    std::string s;

    std::getline(file, s, '\n');
    int count = s.size();
    file.close();

    return count;

}

void add_files (char* name_files_1, char* name_files_2, char* fail_res) {
    
    int char_f_1 = number_char_in_file (name_files_1);
    std::cout << "Number of characters in the first file: " <<char_f_1 << "\n";
    int char_f_2 = number_char_in_file (name_files_2);
    std::cout << "Number of characters in the second file: " <<char_f_2 << "\n";

    unsigned num {};
    num = char_f_1 + char_f_2 + 1;
    std::unique_ptr<char[] > numbers {new char[num]}; //we allocate memory for all characters
    std::cout << "The number of characters in two files, including '/n' = " << num << "\n";

    std::ifstream files_1 (name_files_1);
    if (!files_1) {
        std::cout << "Failid to open file! \n";
    }
    
    std::string s;    
    std::getline(files_1, s, '\n');

    for(size_t i = 0; i < char_f_1; i++) {
        numbers[i] = s[i];
    } 
    files_1.close();    

    std::ifstream files_2 (name_files_2);
    if (!files_2) {
        std::cout << "Failid to open file! \n";
    }
    
    std::getline(files_2, s, '\n');

    for(int i = char_f_1; i < num; i++) {
        numbers[i] = s[i - char_f_1];
    } 
    files_2.close();    

    std::cout << "Output the array for checking: \n";
    for(int i = 0; i < num; i++) {  // Output the array for checking
        cout << numbers[i];
    }
    std::cout << "\n";

    create_files (fail_res);
    std::ofstream out_file(fail_res);  //opens the file for overwriting

    if (!out_file) {
        std::cout << "Failid to open file! \n";
    }
    for(int i = 0; i < num - 1; i++) {  // writing to a file
        out_file << numbers[i];
    }

    out_file.close();
    std::cout << "File created: " << fail_res << "\nCheck the content for compliance!" <<"\n";

}

int presence_word(char* file_str, char* world) {

    std::ifstream file(file_str);
    if (!file) {
        std::cout << "Failid to open file! \n";
    }
    
    std::string s;    
    std::getline(file, s, '\n');
    int char_file = number_char_in_file (file_str);
    std::cout << "Number of characters in the file: " << char_file << "\n";
    int char_world = 0;
    for(char_world = 0; world[char_world]; char_world++);
    std::cout << "Number of characters per word: " << char_world << "\n";

    int n = 0;
    for (int i = 0; i < char_file - char_world; i++ ) { //while it is possible to check the match of the first character
        if(s[i] == world[0]) {
            std::cout << "i: " << i << "\n";
            for(int j = 0; s[i + j] == world[j]; j++) { //we check the further match by letters
                std::cout << "j: " << j << "\n";
                if(j == char_world - 1) n++;
            }
        }
    }
    return n;
}

int main(int argc, char** argv) {

    // lesson 1

    char filename_1[40];
    char filename_2[40];

    cout << "lesson 1: \n";
    cout << "Input file name 1: ";
    cin >> filename_1;
    create_files (filename_1);

    cout << "Input file name 2: ";
    cin >> filename_2;
    create_files (filename_2);

    // lesson 2

    cout << "\nlesson 2: \n";
    char merge_file[40];
    cout << "Input merge file name: ";
    cin >> merge_file;
    
    add_files (filename_1, filename_2, merge_file);

    // lesson 3
    
    cout << "\nlesson 3: \n";
    for(int i = 0; i< argc; i++) {  // to read parameters from the command line
        std::cout << argv[i] << "\n";   // print the parameters from the command line
    }
    int n = presence_word(argv[1], argv[2]);
    std::cout << "Found words in the file: " << n << "\n";
    
    return 0;
}