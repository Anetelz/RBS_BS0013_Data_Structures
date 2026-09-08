#include <iostream>
#include <vector>

void print_values(const std::vector<int>& values) {
    
    // Print every value followed by a space, then print a newline.
    for(int value: values){
        std::cout << value << ' ';
    }
    
    std::cout << '\n';
}

int sum(const std::vector<int>& values) {
    // Calculate and return the sum of the values.
    int sum = 0;

    for(int value: values){
        sum += value;
    }
    return sum;
}

void add_to_all(std::vector<int>& values, int amount) {
    //Add amount to every element.
    /*
    int x = 0;
    for(x = 0; x < (int)values.size(); x++){
        values[x] += amount;
    }
    */
   
    for(int& value: values){
        value += amount;
    }
}

int main() {
    std::vector<int> values{12, 7, 18, 4, 21, 9};

    std::cout << "Original: ";
    print_values(values);
    std::cout << "Sum: " << sum(values) << '\n';

    add_to_all(values, 5);

    std::cout << "Modified: ";
    print_values(values);
    std::cout << "New sum: " << sum(values) << '\n';
}
