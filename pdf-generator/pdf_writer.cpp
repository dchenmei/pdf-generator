#include "pdf_writer.h"

// Public 
//
PDFWriter::PDFWriter(string s, string e): name(s), extension(e), out(e)
{
	file.open(s);
	if(!file.is_open())
	{
		cout << "Error: File not found!" << endl;
	}
}

PDFWriter::PDFWriter(string s, string e, string o): name(s), extension(e), out(o)
{
	file.open(s);
	if(!file.is_open())
	{
		cout << "Error: File not found!" << endl;
	}
}

PDFWriter::~PDFWriter()
{
	file.close();
}

void PDFWriter::write_to_pdf()
{
	switch(extension[0])
	{
		case 't':
	    	text_to_pdf();
			break;
		case 'j':
			img_to_pdf();
			break;
		case 'h':
			html_to_pdf();
			break;
		default:
			break;
	}
}

// Private

void PDFWriter::text_to_pdf()
{
	//string line = "Hello, my name is Jack!";
	//string line2 = "No, my name is actually spelled Jeck";
	
    // string filename = out + ".pdf";
	// const char* f = filename.c_str();
	
	ifstream src("1.pdf", ios::binary);
	ofstream pdf("out.pdf", ios::binary);
	
	pdf << src.rdbuf();
	src.close();
	pdf.close();

	/* Line to modify I: version number aka overwrite first line */
	pdf.open("out.pdf", ios::in);
	pdf << "%PDF-" + PDF_VERSION;
	pdf.close();
	
	/* Open in append mode instead */
	pdf.open("out.pdf", ios::app);
	
	/* Length calculation TODO: Magic number spotted */
	string::size_type length = 100;
	length += 30; // The other stuff like font takes bytes too
	pdf << "<</Length " + to_string(length) + ">>\n";
	
	/* Put in the content */
	/* Because font size is 12, each line is separated by 12 plus no margin */
	pdf << "stream\n";

	//ifstream file(name);
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

void PDFWriter::img_to_pdf()
{
}

void PDFWriter::html_to_pdf()
{
}

string PDFWriter::create_line(string s, int x, int y)
{
	return "BT /F1 12 Tf " + to_string(x) + " " + to_string(y) + " Td\n" +
		   "(" + s + ") Tj ET\n";
}
