#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Person {
 private:
    std::vector<std::string> data_base;
    std::vector<int> count;
    std::vector<std::string> names; //save the pointer of each word

    int input_count = 0;
 public:

     void count_word() {
         std::sort(data_base.begin(), data_base.end());
         std::string previous = "";

         int word_number = 0;  //to count each word
         for (auto& p: data_base) {

             if (p == previous) {
                 word_number++;
             } else {
                 names.push_back(p);
                 if (word_number != 0)
                    count.push_back(word_number);
                 word_number = 1;

             }
             previous = p;    //update previous
         }

     }


     std::istream& read_name(std::istream& in) {
         if (in) {
             data_base.clear();

             std::string record;
             while (in >> record) {
                 if (record == "eof") {
                     break;
                 }
                 data_base.push_back(record);
                 input_count++;
             }
             in.clear();
         }
         return in;
     }

     void print() {
         for (auto& x: data_base) {
             std::cout << x <<" ";
         }
         std::cout << "\n";
     }

     void print_names() {
         for (auto&n : names) {
             std::cout<< n <<" ";
         }
         std::cout << "\n";
     }

     void print_count() {
         for (auto& c : count) {
             std::cout << c << " ";
         }
         std::cout << "\n";
     }
};

int main(){
    Person p;
    p.read_name(std::cin);
    p.count_word();
    p.print();
    p.print_names();
    p.print_count();


}
