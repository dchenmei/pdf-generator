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
	cout << "./pdf-generator filename.ext out" << endl;
	cout << "out: optional file name for output pdf" << endl;
	cout << "Note: Only supports text files" << endl;
}

int main(int argc, char *argv[])
{
	/* Pseudocode, for valid arguments:
     *			   extract the file name and check the extension then call proper functions
     *			   validate the extension
     *
     */

	/* Insufficient arguments, print usage instruction */
	if (argc != 2 && argc != 3)
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

	if (extension != "txt")
	{
		cout << "Error: Invalid file extension. See below." << endl;
		print_usage_instruction();
		return -1;
	}

	/* Open file */
	ifstream file(argv[1]);

	/* Pass to file writer and alert completion */
	
	PDFWriter *writer;
	if (argc == 3)
		writer = new PDFWriter(argv[1], extension, argv[2]);
	else
		writer = new PDFWriter(argv[1], extension);

	writer->write_to_pdf();

	/* Completion message */
	cout << "Writing to pdf..." << endl;

	return 0;
}
