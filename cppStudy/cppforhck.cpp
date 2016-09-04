/*
 * cppforhck.cpp
 *
 *  Created on: 2016. 8. 29.
 *      Author: hanseul
 */

#include <iostream> //For cout
#include <cstring>  //For the string functions
#include <fstream> //for file stream
#include <cstdarg> //for funny var args
using namespace std;

struct database {   int id_number;   int age;   float salary; };
struct xampl {
	int x;
};
struct node {
  int x;
  node *next;
};

inline void hello() ;
void recurse (int count);
void doll ( int size ); //recursive
void printnum ( int begin ) ;
double average(int num, ...);

int main(){
	cout<<"HEY, you, I'm alive! Oh, and Hello World!\n";
	cin.get();

	int thisisanumber;
	cout<<"Please enter a number: ";
	cin>> thisisanumber;
	cin.ignore();
	cout<<"You entered: "<< thisisanumber <<"\n";
	cin.get();

	//chap 06. pointers
	int x;            // A normal integer
	int *p;           // A pointer to an integer
	p = &x;           // Read it, "assign the address of x to p"
	cin>> x;          // Put a value in x, we could also use *p here
	cin.ignore();
	cout<< *p <<"\n"; // Note the use of the * to get the value
	cin.get();
	int *ptr = new int;
	delete ptr;

	//chap07. struct
	database employee;  //There is now an employee variable that has modifiable
	// variables inside it.
	employee.age = 22;
	employee.id_number = 1;
	employee.salary = 12000.21;
	xampl structure;
	xampl *ptr;
	structure.x = 12;
	ptr = &structure;
	// Yes, you need the & when dealing with structures
	// and using pointers to them
	cout<< ptr->x;
	// The -> acts somewhat like the * when used with pointers
	// It says, get whatever is at that memory address
	// Not "get what that memory address is"
	cin.get();

	//chap08. arrays
	int x;
	int y;
	int array[8][8]; // Declares an array like a chessboard
	for ( x = 0; x < 8; x++ ) {
		for ( y = 0; y < 8; y++ )
			array[x][y] = x * y; // Set each element to a value
	}
	cout<<"Array Indices:\n";
	for ( x = 0; x < 8;x++ ) {
		for ( y = 0; y < 8; y++ )
			cout<<"["<<x<<"]["<<y<<"]="<< array[x][y] <<" ";
		cout<<"\n";
	}
	cin.get();

	char *ptr2;
	char str[40];
	ptr2 = str;  // Gives the memory address without a reference operator(&)
	//t *ptr;
	int num;
	ptr = &num; // Requires & to give the memory address to the ptr

	//chap09. strings
	char string[50]; //To declare a string of 49 letters, you would want to say:
	char arry = new char[256]; //char *arry; Can also be used as a string.
	//If you have read the tutorial on pointers
	//which allows you to access arry just as if it were an array.
	// Keep in mind that to use delete you must put []
	// between delete and arry to tell it to free all 256 bytes of memory allocated.
	delete [] arry;
	//The prototype for that function is:
	istream& getline(char *buffer, int length, char terminal_char);
	//It is possible to make a function call of cin.getline(arry, 50);
	//without the terminal character.
	//Note that '\n' is
	//the way of actually telling the compiler you mean a new line,
	//i.e. someone hitting the enter key.
	char string[256];                               // A nice long string
	cout<<"Please enter a long string: ";
	cin.getline ( string, 256, '\n' );              // Input goes into string
	cout<<"Your long string was: "<< string <<endl;
	cin.get();
	//	   int strcmp ( const char *s1, const char *s2 );
	//	   char *strcat ( char *dest, const char *src );
	//	   char *strcpy ( char *dest, const char *src );
	//	   size_t strlen ( const char *s );
	//cstring import
	char name[50];
	char lastname[50];
	char fullname[100]; // Big enough to hold both name and lastname
	cout<<"Please enter your name: ";
	cin.getline ( name, 50 );
	if ( strcmp ( name, "Julienne" ) == 0 ) // Equal strings
		cout<<"That's my name too.\n";
	else                                    // Not equal
		cout<<"That's not my name.\n";
	// Find the length of your name
	cout<<"Your name is "<< strlen ( name ) <<" letters long\n";
	cout<<"Enter your last name: ";
	cin.getline ( lastname, 50 );
	fullname[0] = '\0';            // strcat searches for '\0' to cat after
	strcat ( fullname, name );     // Copy name into full name
	strcat ( fullname, " " );      // We want to separate the names by a space
	strcat ( fullname, lastname ); // Copy lastname onto the end of fullname
	cout<<"Your full name is "<< fullname <<"\n";
	cin.get();

	//chap10. file i/o
	/*
	 * C++ has two basic classes to handle files, ifstream and ofstream.
	 * To use them, include the header file fstream.
	 * Ifstream handles file input (reading from files),
	 * and ofstream handles file output (writing to files).
	 * The way to declare an instance of the ifstream or ofstream class is:
	 */
	//ifstream a_file;
	//ifstream a_file ( "filename" );
	char str[10];
	//Creates an instance of ofstream, and opens example.txt
	ofstream a_file ( "example.txt" );
	// Outputs to example.txt through a_file
	a_file<<"This text will now be inside of example.txt";
	// Close the file stream explicitly
	a_file.close();
	//Opens for reading the file
	ifstream b_file ( "example.txt" );
	//Reads one string from the file
	b_file>> str;
	//Should output 'this'
	cout<< str <<"\n";
	// b_file is closed implicitly here
	/*
	 * ios::app   -- Append to the file
	 * ios::ate   -- Set the current position to the end
	 * ios::trunc -- Delete everything in the file
	 */
	ofstream a_file ( "test.txt", ios::app );
	if ( !a_file.is_open() ) {
		// The file could not be opened
	}
	else {
		// Safely use the file stream
	}

	//chap11. typecasting
	cout<< (char)65 <<"\n";
	// The (char) is a typecast, telling the computer to interpret the 65 as a
	//  character, not as a number.  It is going to give the character output of
	//  the equivalent of the number 65 (It should be the letter A for ASCII).
	cin.get();
	for ( int x = 0; x < 256; x++ ) {
		cout<< x <<". "<< (char)x <<" ";
		//Note the use of the int version of x to
		// output a number and the use of (char) to
		// typecast the x into a character
		// which outputs the ASCII character that
		// corresponds to the current number
	}
	cin.get();
	//First is the function-style cast:
	cout<< char ( 65 ) <<"\n";
	cin.get();
	//Next is the named cast, of which there are four:
	cout<< static_cast<char> ( 65 ) <<"\n";
	cin.get();

	//chap12 : class --> studyClass.cpp

	//chap13. function continued
	hello(); //Call it like a normal function...
	cin.get();
	/*
	 * However, once the program is compiled, the call to hello();
	 * will be replaced by the code making up the function.
	 * A WORD OF WARNING: Inline functions are very good for saving time,
	 * 	but if you use them too often or with large functions you will have a tremendously large program.
	 * 	Sometimes large programs are actually less  efficient,
	 * 	and therefore  they will run more slowly than before.
	 * 	Inline functions are best for small functions that are called often.
	 * 	In the future, we will discuss inline functions in terms of C++ classes.
	 * 	However, now that you understand the concept I will feel comfortable using inline functions in later tutorials.
	 */

	//chap14. accepting command line --> studyCommand.cpp

	//chap15. singely linked list
	node *root;      // This will be the unchanging first node
	  root = new node; // Now root points to a node struct
	  root->next = 0;  // The node root points to has its next pointer
	                   //  set equal to a null pointer
	  root->x = 5;     // By using the -> operator, you can modify the node
	                   //  a pointer (root in this case) points to.
	  /*
	   * Lets imagine a conductor who can only enter the train through the engine,
	   * and can walk through the train down the line as long as the connector connects to another car.
	   * This is how the program will traverse the linked list.
	   * The conductor will be a pointer to node, and it will first point to root,
and then, if the root's pointer to the next node is pointing to something, the "conductor" (not a technical
term) will be set to point to the next node. In this fashion, the list can be traversed. Now, as long as there is
a  pointer to something, the traversal  will  continue. Once it reaches  a null  pointer (or  dummy  node),
meaning there are no more nodes (train cars) then it will be at the end of the list, and a new node can
subsequently be added if so desired.
	   */
	  node *root2;       // This won't change, or we would lose the list in memory
	  node *conductor;  // This will point to each node as it traverses the list
	  root2 = new node;  // Sets it to actually point to something
	  root2->next = 0;   //  Otherwise it would not work well
	  root2->x = 12;
	  conductor = root; // The conductor points to the first node
	  if ( conductor != 0 ) {
	    while ( conductor->next != 0)
	      conductor = conductor->next;
	  }
	  conductor->next = new node;  // Creates a node at the end of the list
	  conductor = conductor->next; // Points to that node
	  conductor->next = 0;           // Prevents it from going any further
	  conductor->x = 42;
	  //That is the basic code for traversing a list.
	  //To print a linked list, the traversal function is almost the same.
	  //It is necessary to ensure that the last element is printed after the while loop terminates.
	  conductor = root;
	  if ( conductor != 0 ) { //Makes sure there is a place to start
	    while ( conductor->next != 0 ) {
	      cout<< conductor->x;
	      conductor = conductor->next;
	    }
	    cout<< conductor->x;
	  }
	  //Bad for the conductor (if it were a real person),
	  //but the code is simpler as it also allows us to remove the initial check for null
	  //(if root is null, then conductor will be immediately set to null and the loop will never begin):
	  conductor = root;
	  while ( conductor != NULL ) {
	    cout<< conductor->x;
	    conductor = conductor->next;
	  }

	  //chap16. recursion
	  doll ( 10 ); //Starts off with a large doll (its a logarithmic scale)
	  recurse ( 1 ); //First function call, so it starts at one
	  printnum ( 1 ); //First function call, so it starts at one

	  //chap17. funny var arg
	  cout<< average ( 3, 12.2, 22.3, 4.5 ) <<endl;
	    cout<< average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) <<endl;

	    //chap18. binary trees 1. --> binaryTree.cpp
	    //The binary tree is a fundamental data structure used in computer science.
	    //The binary tree is a useful data structure for rapidly storing sorted data and rapidly retrieving stored data.

	    //chap19. inheritance concept
	    //chap20. inheritance syntax --> studyInheritance.cpp


	return 1;
}
double average ( int num, ... )
{
  va_list arguments; // A place to store the list of arguments
  double sum = 0;
va_start ( arguments, num ); // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ ) // Loop until all numbers are added
sum += va_arg ( arguments, double ); // Adds the next value in argument list to sum.
  va_end ( arguments ); // Cleans up the list
  return sum / num; // Returns some number (typecast prevents truncation)
}

void printnum ( int begin )
{
  cout<< begin;
  if ( begin > 9 ) // The base case is when begin is greater than 9
printnum ( begin + 1 ); // for it will not recurse after the if-statement
  cout<< begin; // Outputs the second begin, after the program has
// gone through and output
}
void doll ( int size )
{
  if ( size == 0 )   // No doll can be smaller than 1 atom (10^0==1) so doesn't call itself
    return;          // Return does not have to return something, it can be used
                     //  to exit a function
  doll ( size - 1 ); // Decrements the size variable so the next doll will be smaller.
}
void recurse ( int count ) // Each call gets its own count
{
  cout<< count <<"\n";
  // It is not necessary to increment count sinceeach function's
  //  variables are separate (so each count will be initialized one greater)
  recurse ( count + 1 );
}

inline void hello()
{
	cout<<"hello";
}

/*
 * cin.get():
 * This is another function call:
 *  it reads in input and expects the user to hit the return key.
 *  Many compiler environments will open a new console window,
 *  run the program, and then close the window.
 *  This command keeps that window from closing
 *  because the program is not done yet
 *  because it waits for you to hit enter.
 * Including that line gives you time to see the program run.
 *
 */

/*
 *  The function cin>> reads a value into thisisanumber;
 *   the user must press enter before the number is read by the program.
 *   cin.ignore() is another function that reads and discards a character.
 *   Remember that when you type intput into a program,
 *   it takes the enter key too. We don't need this,
 *   so we throw it away.
 *   Keep in mind that the variable was declared an integer;
 *   if the user attempts to type in a decimal number,
 *   it will be truncated (that is, the decimal component of the number will be ignored).
 *   Try typing in a sequence of characters or a decimal number
 *   when you run the example program;
 *   the response will vary from input to input,
 *   but in no case is it particularly pretty.
 *   Notice that when printing out a variable quotation marks are not used.
 *   Were there quotation marks,
 *   the output would be "You Entered: thisisanumber."
 *   The lack of quotation marks informs the compiler
 *   that there is a variable, and
 *   therefore that the program should check the value of the variable
 *   in order to replace the variable name with the variable
 *   when executing the output function.
 *   Do not be confused by the inclusion of two separate insertion operators on one line.
 *   Including multiple insertion operators on one line is perfectly acceptable and all of the output will go to the same place.
 *   In fact, you must separate string literals
 *   (strings enclosed in quotation marks) and variables by giving each its own insertion operators (<<).
 *
 *
 */
