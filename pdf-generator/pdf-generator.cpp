#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/* Usage Instructions
 *
 * ./pdf-generator filename.extension -o out.pdf
 *
 * -o: optional option to set the name for output pdf, default filename.pdf
 * 
 */
void print_usage_instruction()
{
	cout << "Usage: " << endl;
	cout << "./pdf-generator filename.ext -o out.pdf" << endl;
	cout << "-o: optional option to set name for output" << endl;
	cout << "Note: Only supports text files, images (jpeg and png), and HTML" << endl;
}

// TODO: Is this function necessary or can we just write one if statement 
bool valid_file_name(string name)
{
	/* Not using compare, because only true/false is needed */
	return name == "txt"  || 
		   name == "png"  || 
		   name == "jpg"  || 
		   name == "jpeg" ||
		   name == "html";  
}

int main(int argc, char *argv[])
{
	/* Pseudocode, for valid arguments:
     *			   extract the file name and check the extension then call proper functions
     *			   validate the extension
     *
     */

	/* Insufficient arguments, print usage instruction */
	if (argc != 2 && argc != 4)
	{
		cout << "Error: Invalid number of arguments. See below." << endl;
		print_usage_instruction();
		return -1;
	}
	
	/* Get extension */
	string file_name = argv[1];
	string extension; 

	int found = file_name.rfind(".");
	extension = file_name.substr(found + 1); /* offset by one to ignore "." */

	if (!valid_file_name(extension))
	{
		cout << "Error: Invalid file extension. See below." << endl;
		print_usage_instruction();
	}

	/* Open the file for processing */
	
	return 0;
}
