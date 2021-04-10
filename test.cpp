#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Global Definitions:
#define SALARY_FILE_NAME "salaries.txt"
#define JOBS_SIZE 10
#define SALARY_DELIMITER "-"

using namespace std;

int main() {
    // Defining storage arrays:
    string roles[JOBS_SIZE];
    double salaries[JOBS_SIZE][2];
    
    // Opening data file:
    ifstream salaryFile(SALARY_FILE_NAME);
    if (!salaryFile.is_open()){
        cout << "File not found: " << SALARY_FILE_NAME;
    }

    // Allocating string variables:
    string new_role;
    string new_salary_str;
    // Iterating through file 2 lines at a time:
    for (
        int i = 0; 
        getline(salaryFile, new_role) && getline(salaryFile, new_salary_str);
        i++
    ) {
        // Storing role string
        roles[i] = new_role;

        // parsing salary strings:
        size_t s_point = new_salary_str.find(SALARY_DELIMITER);
        std::string token_1 = new_salary_str.substr(0, s_point); 
        std::string token_2 = new_salary_str.substr(s_point + 1);
        
        // Converting salaries to double, and storing.
        salaries[i][0] = stod(token_1);
        salaries[i][1] = stod(token_2);

    }

    salaryFile.close(); 
}
