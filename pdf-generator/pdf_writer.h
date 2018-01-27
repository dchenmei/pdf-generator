/*********************************************
 * Describes PDF Writer
 *
 * Author: swo
 *********************************************/

#include <string>

using namespace std;

class PDFWriter
{
  public:
	PDFWriter(FILE *f, string e);           // write w/o output name 
	PDFWriter(FILE *F, string e, string o); // writer w/ output name

  private:
	double version = 1.7;
	FILE *file;
	string extension;
	string out;
	
};
