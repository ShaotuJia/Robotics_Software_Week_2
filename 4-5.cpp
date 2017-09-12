/**
 *@brief: This cpp code is to input words using stream and the total number
 *input and the frequency of each word
 *@author: Shaotu Jia
 */


#include <iostream>
#include <vector>
#include <memory>
#include <string>

/**
 * @breif This class is to contain all input data and also compute total number of input words
 * and  the frequency of each word occurs
 */

class Dictionary {

 private:
    std::vector<std::string> data_base; ///< An vector that contains all input words
    std::vector<int> count;             ///< An vector that contains the frequency of each word
    std::vector<std::string> names; ///< An vector that cotains each word
    int input_count = 0;            ///< An integer to count the total number of input words

 public:

     /**
      * @brief count the frequency of each word
      */
     void count_word() {
         // sort all input word
         std::sort(data_base.begin(), data_base.end());
         std::string previous = ""; ///< previous word for comparsion

         int word_number = 0;  ///< counter for each word
         // get the frequency of each word
         for (auto& p: data_base) {
             input_count++;      //The total number of words
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

     /**
      * @brief get input word from stream
      * @param in The input stream
      */
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

     /**
      * @brief print all input words
      */
     void print() {
         for (auto& x: data_base) {
             std::cout << x <<" ";
         }
         std::cout << "\n";
     }

     /**
      * @brief print each word with its frequency
      */
     void print_frequency() {
         for (auto&n : names) {
             std::cout<< n <<" ";
         }
         std::cout << "\n";

         for (auto& c : count) {
             std::cout << c << " ";
         }
         std::cout << "\n";
     }

};

int main(){
    Dictionary p;
    p.read_name(std::cin);
    p.count_word();
    p.print();
    p.print_frequency();



}
