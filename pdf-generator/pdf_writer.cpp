#include "pdf_writer.h"

// Public 
//
PDFWriter::PDFWriter(FILE *f, string e): file(f), extension(e), out(e)
{
	// TODO: Get the original name instead?
}

PDFWriter::PDFWriter(FILE *f, string e, string o): file(f), extension(e), out(o)
{
}

FILE* PDFWriter::write_to_pdf()
{
	FILE *pdf;
	switch(extension[0])
	{
		case 't':
			pdf = text_to_pdf();
			break;
		case 'j':
			pdf = img_to_pdf();
			break;
		case 'h':
			pdf = html_to_pdf();
			break;
		default:
			break;
	}

	return pdf;
}

// Private

FILE* PDFWriter::text_to_pdf()
{
	string line = "Hello, my name is Jack!";
	string line2 = "No, my name is actually spelled Jeck";
	
    // string filename = out + ".pdf";
	// const char* f = filename.c_str();
	ofstream pdf;
	
	/* Line to modify I: version number aka overwrite first line */
	pdf.open("1.pdf", ios::in);
	pdf << "%PDF-" + PDF_VERSION;
	pdf.close();
	
	/* Open in append mode instead */
	pdf.open("1.pdf", ios::app);
	
	/* Length calculation */
	string::size_type length = line.size() + line2.size();;
	length += 30; // The other stuff like font takes bytes too
	pdf << "<</Length " + to_string(length) + ">>\n";
	
	/* Put in the content */
	/* Because font size is 12, each line is separated by 12 plus no margin */
	pdf << "stream\n";

	pdf << create_line(line, DEFAULT_X, DEFAULT_Y);
	pdf << create_line(line2, DEFAULT_X, DEFAULT_Y - 12);

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

	/*
	ofstream qqq;
	qqq.open("2.pdf", ios::out);
	qqq << pdf.rdbuf();
	*/

	pdf.close();
	// qqq.close();
}

FILE* PDFWriter::img_to_pdf()
{
}

FILE* PDFWriter::html_to_pdf()
{
}

string PDFWriter::create_line(string s, int x, int y)
{
	return "BT /F1 12 Tf " + to_string(x) + " " + to_string(y) + " Td\n" +
		   "(" + s + ") Tj ET\n";
}
