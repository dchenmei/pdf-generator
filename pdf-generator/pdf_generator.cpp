#include <iostream>
#include <string>
#include <cstdio>
#include "pdf_writer.h"

/* To compile, please include pdf_write.cpp */ 

/* TODO: optimize namespace later 
using std::cout;
using std::cin;
using std::endl;
using std::string;
*/

using namespace std;

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

	/* Open file */
	FILE *f = fopen(argv[1], "r");

	if (f == NULL) 
	{
		cout << "Error: File not found." << endl;
	}
	
	/* Pass to file writer and alert completion */
	
	PDFWriter *writer;
	if (argc == 4)
		writer = new PDFWriter(f, extension, argv[3]);
	else
		writer = new PDFWriter(f, extension);

	writer->write_to_pdf();

	// TODO: Print message about completion / failure as well as resulting file name

	return 0;
}
