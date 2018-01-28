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
}

FILE* PDFWriter::img_to_pdf()
{
}

FILE* PDFWriter::html_to_pdf()
{
}

int main()
{
	return 0;
}
