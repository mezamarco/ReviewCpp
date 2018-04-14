#include <iostream>
#include <fstream>      //Required to open and close the input and output file streams
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
  
  std::string favQuote = "Give me six hours to chop down a tree and I will spend the first four hours sharpening the axe.";
  //Open the output file stream. 
  //The variable name of our output file stream will be: writer.
  std::ofstream writer;
  writer.open("theOutputFile.txt");

  //Verify that the file was opened
  if(!writer){
    std::cout << "Unable to open: \"theOutputFile.txt\" " << std::endl;
    return -1;
  } else {
    //Now just place the quote into my output file stream 
    writer << favQuote << std::endl;
    //Close the output file stream 
    writer.close();
  }
 


  //Lets open an output stream that will append to the end of the given file
  std::ofstream anotherWriter;
  anotherWriter.open("theOutputFile.txt", std::ios::app);

  //Note:
  //std::ios::app  	Allows us to append to the end of the file
  //std::ios::in 	Open a file to read the input
  //std::ios::out 	Open a file to write to output
  //std::ios::binary	Operation are performed in binary mode rather than text
  //istd::os::trunc     (By Default) Discard the contents and begin writing from scratch


  //Verify that the file was opened
  if(!anotherWriter){
    std::cout << "Unable to open: \"theOutputFile.txt\"" << std::endl;
    return -1;
  } else {
    //Now just place the quote(we are appending: therefore its starts in a new line) into my output file stream 
    anotherWriter << "(Appended)This quote is from Abraham Lincoln." << std::endl;
    //Close the output file stream 
    anotherWriter.close();
  }
 


  //Now let's read a file
  //Open an input file stream
  std::ifstream reader;
  reader.open("theOutputFile.txt");
  
  char letter;

  //Verify that we have opened our input file stream
  if(!reader){
    std::cout << "Unable to open: \"theOutputFile.txt\"" << std::endl;
    return -1;
  } else {
    //We are ready to read the characters of our input file
    std::cout << "\nWe will now Read the characters of a file:" <<std::endl;

    //Read the input character by character and place them in the letter variable one by one
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
  
  std::cout << "\nException Handling: We will try to divide by zero." <<std::endl;
  int zeroValue = 0;

  //In the try block make sure to throw the problematic value and then catch
  try{
	  if(zeroValue != 0)
	  {
	    std::cout << 2/zeroValue << std::endl;
	  }
          else throw(zeroValue);
  }   //We throw the problematic value and now lets catch it. 
      //To catch it the paramenter must match the argument.
  catch(int zeroValue) //Go here if the value is of type integer
  {
  	std::cout << "We have an int: "<< zeroValue << " is not valid" << std::endl;
  }
  catch(double zeroValue) //Go here is the value is of type double
  {
  	std::cout <<"We have a double: "<< zeroValue << " is not valid" << std::endl;
  }
  catch(...) //By default, Go here if the value is neither an int value or a double value
  {
  	std::cout << "By default: " <<zeroValue << " is not valid" << std::endl;
  }



}//End of main function
