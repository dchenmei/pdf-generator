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

const string PDF_VERSION = "1.7";
const int DEFAULT_X = 50;
const int DEFAULT_Y = 720;


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
	string create_line(string s, int x, int y);

	FILE *file;
	string extension;
	string out;
};
