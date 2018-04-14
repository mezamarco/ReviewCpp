#include <iostream>  //For input and output
#include <fstream>   //For file input and file output
#include <string>    //For strings
#include <ctime>     //FOr seeding the random generator using the clock



int main(){

  char myGrade = 'A';  // 1 Byte
  bool isHappy = true; // 1 Byte
  int favNumber = 26;  // 4 Bytes
  float number = 22.44; // 4 Bytes
  double secondNumber = 34.667;   //8 Bytes

  //Pointers are 4 Bytes if we are dealing with a 32 bit system
  //Pointers are 8 Bytes if we are dealing with a 64 bit system



  std::string oneLetter = "n";
  std::cout << "The size of a string with only one letter is: " << sizeof(oneLetter) << std::endl;
  std::string aWord = "Turtle";
  std::cout << "The size of a string with only a word is: " << sizeof(aWord) << std::endl;


  /*PreIncrement vs PostIncrement
  
  Note that PostIncrement has to create a copy and therefore PreIncrement is a bit faster

  Image the following functions


  int preIncrement(int &i){			//Pass-by-reference
  	i = i+1;
	return i;
  }

  int postIncrement(int  &j){		       	//Pass-by-reference
  	int original = j;
	j = j+1;
	return original;
  }


  */
   int theValue = 5;
   std::cout << "\nStarting with theValue: 5\n";

   std::cout << "theValue++ = " << theValue++ << std::endl;  //5
   std::cout << "++theValue = " << ++theValue << std::endl;  //7
   std::cout << "theValue-- = " << theValue-- << std::endl;  //7
   std::cout << "--theValue = " << --theValue << std::endl;  //5


  









  //Switch Statements: Use if there exist only a small limited amount of cases
  int caseNumber = 3;

  switch(caseNumber){
  

  	case 1:
		std::cout << "Case 1 was picked, Hello." << std::endl;	
  		break;
	case 2:
		std::cout << "Case 2 was picked, Hello." << std::endl;	
  		break;
  	case 3:
		std::cout << "Case 3 was picked, Hello." << std::endl;	
  		break;
  	//If none of the case number matches then go to the dafault
	default: 
		std::cout << "No Case Match, Ok,Bye." << std::endl;
	
  }



  //Turnary Operators, Assigns a value depending if a condition is true or false
  //Use the following template
  //variable = ( (condition) ? true:false);
  int largerNumber = ((5>2) ? 5:2);   //Since the condition is true then the number 5 is assigned to largerNumber
 
  std::cout << "\nSwitch Statement: The value of the larger number is: " << largerNumber << std::endl;

  //Arrays (Arrays are just boxes)
  double numOfBoxes[5]= {6,7,8,9,10};   //Note that every double box is 8 bytes => 5 boxes * 8  = 40 bytes
  int arr[5] = {4,5,6,7,8}; 		//Note that every int box is 4 bytes => 5 boxes * 4 = 20 bytes
  char charArr[5] = {'a','b','c','d','e'};   //Note that every char box is 1 byte => 5 boxes * 1 byte = 5 bytes 


  std::cout << "\nAn array of 5 character boxes has the size of: " 
	  << sizeof(charArr) << " bytes." <<std::endl; //Prints: 5 bytes
  
  std::cout << "An array of 5 integer boxes has the size of: " 
	  << sizeof(arr) << " bytes." <<std::endl; //Prints: 20 bytes

  std::cout << "An array of 5 double boxes has the size of: " 
	  << sizeof(numOfBoxes) << " bytes." <<std::endl; //Prints: 40 bytes
 


  //Multidimensional Array

  char myName[2][5] = { {'M','A','R','C','O'},
	  		{'M','E','Z','A'} };

  std::cout << "\nA multi-dimensional array of 10 char boxes has the size of: " << sizeof(myName) << " bytes." <<std::endl;

  std::cout << "In my multiDimensional Array, the position [1][2] holds: " << myName[1][2]<< std::endl; 
  std::cout << "In my multiDimensional Array, the position that is empty [1][4] holds: " << myName[1][4]<< std::endl;
  std::cout << "Note: It actually printed the empty character^^^^^^^^^^" << std::endl;
  


  //Random numbers  
  int randNum = (rand() % 100);  //Range: 0 to 99
  std::cout << "A random number between 0 and 99 is: " << randNum << std::endl;
  
  int randNumTwo = (rand() % 100) + 1 ;  //Range: 1 to 100
  std::cout << "A random number between 1 and 100 is: " << randNumTwo << std::endl;

  //If you want different random values each time the program runs, make sure to include:  
  //#include <ctime>     and only once call:      srand(time(NULL));


  //do-while loop, it goes through the do-block at least one time

  srand(time(NULL));

  int theNumber;
  do{
    theNumber = (rand() % 10)+ 1;
    std::cout << "The random number is: " << theNumber <<std::endl; 
  } while (theNumber != 5);

  std::cout<< "We have exited the do-while loop because we got 5.\n" << std::endl; 

  std::string theWord;
  std::cout << "\nLets now do determine if a word is a palindrome." << std::endl;
  std::cout << "Enter the word: ";
  getline(std::cin, theWord );

  //Case: Empty String
  if(theWord.length() == 0 ){
	  std::cout << "The word is empty and therefore it is a valid palindrome." << std::endl;

  } else { //Case: We have an actual word, so lets determine if it is a palindrome

	int i = 0;
	int j = theWord.length()-1;
 
 	while (i<j){
        		
          if(theWord[i] == theWord[j]){
	     ++i;
	     --j;
	   } else { 
	   	std::cout << theWord << " is NOT a valid palindrome" << std::endl;
		return 1;	
	   
	   }	
	
	}
        std::cout << theWord << " is a valid palindrome" << std::endl;

  }
  





 return 1;

}


