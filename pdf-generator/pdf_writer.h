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
	PDFWriter(string s, string e);           // write using same name as input
	PDFWriter(string s, string e, string o); // write using custom name
	~PDFWriter();
	void write_to_pdf();

  private:
	// helper functions
	void text_to_pdf();
	void img_to_pdf();
	void html_to_pdf();
	string create_line(string s, int x, int y);

	ifstream file;
	string name;
	string extension;
	string out;
};
