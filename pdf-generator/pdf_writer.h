/*********************************************
 * Describes PDF Writer
 *
 * Author: swo
 *********************************************/

#include <string>
#include <iostream>
#include <fstream> // file i/o
#include <iomanip> // set precision

using namespace std;

const string PDF_VERSION = "1.5";


class PDFWriter
{
  public:
	PDFWriter(FILE *f, string e);           // write w/o output name 
	PDFWriter(FILE *F, string e, string o); // writer w/ output name
	FILE* write_to_pdf();

  private:
	// helper functions
	FILE* text_to_pdf();
	FILE* img_to_pdf();
	FILE* html_to_pdf();

	FILE *file;
	string extension;
	string out;
};
