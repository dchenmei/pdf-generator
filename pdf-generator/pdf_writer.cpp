/************************************************
 *
 * Implements PDFWriter
 *
 * swolewizard
 ************************************************/
#include "pdf_writer.h"

/* Public */
/* Takes string s and o, file name and output name and initialize writer */
PDFWriter::PDFWriter(string s, string o): name(s), out(o)
{
	file.open(s);
	if(!file.is_open())
	{
		throw invalid_argument("File not found.");
	}
}

/* When PDFWriter dies, close the file */
PDFWriter::~PDFWriter()
{
	if (file.is_open())
	{
		file.close();
	}
}

/* Write a pdf file from the given text file */
void PDFWriter::write_to_pdf()
{
	/* Create output file name */
	string out_file_name = out + ".pdf";

	/* Copy header and overhead from template */
	ifstream src("txt_template.pdf", ios::binary);
	ofstream pdf(out_file_name, ios::binary);
	
	pdf << src.rdbuf();
	src.close();
	pdf.close();

	/* Write PDF version */
	pdf.open(out_file_name, ios::in);
	pdf << "%PDF-" + PDF_VERSION;
	pdf.close();
	
	/* Write content of text file */
	pdf.open(out_file_name, ios::app);
	
	string::size_type length = 100;
	length += 30; 
	pdf << "<</Length " + to_string(length) + ">>\n";
	
	pdf << "stream\n";

	/* Write line by line, font size is 12 so 12 space for each line */
	string line;
	int y = DEFAULT_Y;
	while (getline(file, line))
	{
		pdf << create_line(line, DEFAULT_X, y);
		y -= 12;
	}
	// pdf << create_line(line, DEFAULT_X, DEFAULT_Y);
	// pdf << create_line(line2, DEFAULT_X, DEFAULT_Y - 12);

	pdf << "endstream\n";
	pdf << "endobj\n";

	/* Put in the xref and etc stuff */
	pdf << "xref\n";
	pdf << "0 7\n";
	pdf << "0000000000 65535 f\n";
	pdf << "0000000009 00000 n\n";
	pdf << "0000000056 00000 n\n";
	pdf << "0000000111 00000 n\n";
	pdf << "0000000212 00000 n\n";
	pdf << "0000000250 00000 n\n";
	pdf << "0000000317 00000 n\n";
	pdf << "trailer <</Size 7/Root 1 0 R>>\n";
	pdf << "startxref\n";
	pdf << "406\n";
	pdf << "%%EOF\n";

	pdf.close();
}

/* Private */

/* Takes input line s and coordinates x and y, create a text object in PDF format */ 
string PDFWriter::create_line(string s, int x, int y)
{
	return "BT /F1 12 Tf " + to_string(x) + " " + to_string(y) + " Td\n" +
		   "(" + s + ") Tj ET\n";
}
