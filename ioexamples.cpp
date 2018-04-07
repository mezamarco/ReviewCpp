#include <iostream>
#include <fstream>
#include <string>

int main(){

  //Let get some input and diplay it back
  
  std::string yourName;		
		
  std::cout <<"Enter your name: ";
  getline(std::cin, yourName);

  std::cout << "\nHey " << yourName << ", what is you favorite number: ";
  std::string numberString;
  getline(std::cin, numberString);


  std::cout << "\nWe will do math with your favorite integer number: " << numberString << std::endl;  


  //Given that the number I received is a string, I must first convert the string into a int.
  int userNumber = stoi(numberString);
  std::cout << userNumber << " * " << userNumber << " = " << (userNumber*userNumber) << std::endl;


  std::string decimalStringNumber;
  std::cout << "\nWhat is your favorite decimal number: ";
  getline(std::cin, decimalStringNumber); 
   
  //Given that the number I received is a string, I must first convert the string into a double.
  double decimalNumber = stod(decimalStringNumber);
  std::cout << decimalNumber << " * " << decimalNumber << " = " << (decimalNumber * decimalNumber) << std::endl;



  //We will now deal with File I/O
  
  std::string favQuote = "Give me six hours to chop down a tree and I will spend the first four hours sharpening the axe";

  //Create the output file stream and name the file.
  std::ofstream writer("theOutputFile.txt");

  //Verify that the file exists or has been created
  if(!writer){
    std::cout << "The file was not created" << std::endl;
    return -1;
  } else {
    //Now just place the quote into my output file stream 
    writer << favQuote << std::endl;
    //Close the output file stream 
    writer.close();
  }
 


  //Lets open an output stream that will append to the end of the given file
  std::ofstream anotherWriter("theOutputFile.txt", std::ios::app);

  //Note:
  //ios::app  	Allows us to append to the end of the file
  //ios::in 	Open a file to read the input
  //ios::out 	Open a file to write to output


  //Verify that the file exists or has been created
  if(!anotherWriter){
    std::cout << "The output file was not opened" << std::endl;
    return -1;
  } else {
    //Now just place the quote into my output file stream 
    anotherWriter << "\n\nThis quote is from Abraham Lincoln." << std::endl;
    //Close the output file stream 
    anotherWriter.close();
  }
 


  //Now let's read a file
  std::ifstream reader("theOutputFile.txt");
  char letter;


  //Verify that we have opened our input file
  if(!reader){
    std::cout << "The input file could not be opened." << std::endl;
    return -1;

  } else {
    //We are ready to read the characters of our input file
    
    for(int i = 0; !reader.eof(); i++){
      reader.get(letter);
      std::cout << letter;
    }
    std::cout << "We have reached the end of the file. Well done." << std::endl;
    //Close our input file
    reader.close();

  }

  

  //Exception handling
  //Surround the problematic code inside the try-block, This will prevent our program from crashing.
  
  int zeroValue = 0;

  try{
	  if(zeroValue != 0)
	  {
	    std::cout << 2/zeroValue << std::endl;
	  }
          else throw(zeroValue);
  }
  catch(int zeroValue)
  {
  	std::cout << zeroValue << " is not valid" << std::endl;
  }







}
