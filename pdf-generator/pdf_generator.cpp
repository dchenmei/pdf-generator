#include <iostream>
#include <string>
#include <cstdio>
#include "pdf_writer.h"

using namespace std;

/* Usage Instructions
 *
 * ./pdf-generator filename.txt out
 *
 * out: optional out file name, default is input filename
 * 
 */
void print_usage_instruction()
{
	cout << "Usage: " << endl;
	cout << "./pdf-generator filename.txt out" << endl;
	cout << "out: optional file name for output pdf" << endl;
}

int main(int argc, char *argv[])
{
	/* Invalid number of arguments, print usage instruction */
	if (argc != 2 && argc != 3)
	{
		cout << "Error: Invalid number of arguments. See below." << endl;
		print_usage_instruction();
		return -1;
	}
	
	/* Check for correct extension, .txt */
	string file_name = argv[1];
	string extension; 

	int found = file_name.rfind(".");
	extension = file_name.substr(found + 1); /* offset by one to ignore "." */

	if (extension != "txt")
	{
		cout << "Error: Invalid file extension. Must be of type txt." << endl;
		return -1;
	}

	/* Extract default out name if not provided by user */
	string out;
	if (argc == 2)
	{
		out = file_name.substr(0, file_name.find('.' + extension));
	}
	else
	{
		out = argv[2];
	}
		
	/* Pass to writer */
	PDFWriter *writer = new PDFWriter(file_name, out);
	
	writer->write_to_pdf();

	/* Completion message */
	cout << "Writing to pdf... Done" << endl;

	return 0;
}
