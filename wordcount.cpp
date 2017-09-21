/*
 * CSc103 Project 3: wordcount++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: To complete this project I had to researched more about functions in cplusplus.com.
 *The website taught me how to use new functions for strings such as substr(), I also learned how to use isspace() for the white space characters.
 *The book (chapter 8) helped me understand different ways to pass references for my sets and counters.
 *and I learned about sets and vectors in class
 * Finally, please indicate approximately how many hours you spent on this:
 *
 * #hours: 5 hours coding 10 hours thinking about how to code
 */

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cctype>
#include <fstream>
using std::set;
using std::cin;
using std::cout;
using std::string;
using std::vector;

int countWords(const string& line, int& counter1, set<string>& word_container) 
{
   int  first_letter;    //Saves the position of the first letter of a word
   int  timer = 0;       //Counts how many characters are between the first letter and whitespace
   int  i = 0;           //Used to execute the loop
   char position;        //Saves the position of a specific character in the string        
   string single_words;  //Holds a single word after it is found             
   vector<string>total;  //Saves total number of words

   while(i < line.length())   //Ends once it reaches surpasses the number of characters in the line
   { 
       
   position = line[i];        //Assigns character position
      
   if(isspace(position))      //isspace() determines whether the char is a space or not
   {
      ++i;
   }
   else 
   {
      first_letter = i;
         
      while(!(isspace(position)) && i <= line.length()-1) //Explores a word until a whitespace character is found
      {
         ++i;
         position = line[i];
         ++timer;
                        
      }
         
      single_words = line.substr(first_letter, timer);    //Assigns the words as substrings using the location of characters
      total.push_back(single_words);                      //Puts each word in a vector
	  counter1++;                                         //Increases the number of words
      timer = 0;                                          //Resets timer for new word
   }
   }
  
   for(int m=0; m < total.size(); ++m)                       //Moves vector objects to the set
   {
   word_container.insert(total[m]);
   }
   
}

int countLines(const string& lines, int& counter2, set<string>& line_counter)     
{
   line_counter.insert(lines);                                                  //Inserts each string to the set
   ++counter2;                                                                  //Increases the number of lines
}

int countCharacters(const string& this_line, int& char_count)
{
   char_count += this_line.length();                                            //Gets the length of each string
}

int main()
{
   string input;
   int characters  = 0;                                 //Variables for counting words, chars and lines
   int word_number = 0;
   int line_number = 0;
   set<string> unique_words;                            //Sets for the functions
   set<string> unique_lines;           
   
   while(getline(cin,input))
   {
      countWords(input, word_number, unique_words);
	  countLines(input, line_number, unique_lines);
	  countCharacters(input, characters);
	  characters++;                                    //Compensates for the new line character
	  
   }
   cout<< line_number <<"	";
   cout<< word_number <<"	";
   cout<< characters  <<"	";
   cout<< unique_lines.size() <<"	";
   cout<< unique_words.size() <<"	\n";
   
   return 0;
}
