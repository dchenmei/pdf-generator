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
	// Option 1: Open one, copy to another (worse than writing one by one)
	// Option 2: Have it stored, use a stream to dump all of it in (no need to clutter code with fputs)
	/* Alternative solution, modifying a pdf template to save time */

	/* Line to modify I: version number */


	/* Line to modify II: length of stream */


	/* Line(s) to modify III: Actual content */


	/* Line(s) to modify IV: xref table */

	
	/* Line to modify V: final total byte value */
	
	#if 0
	/* No need to check, a new file is created anyway */
	string filename = out + ".pdf";
	const char* f = filename.c_str();
	FILE *pdf = fopen(f , "w");

	/* Header */
	// TODO: use the macro instead to keep it easier to update?
	fputs("%PDF-1.7\n", pdf);

	/* Necessary set up objects */

	/* Catalog obj */
	fputs("1 0 obj <</Type /Catalog /Pages 2 0 R>>\n", pdf);
	fputs("endobj\n", pdf);

	/* Page obj */
	fputs("2 0 obj <</Type /Pages /Kids [3 0 R] /Count 1>>\n", pdf);
	fputs("endobj\n", pdf);

	/* Mediabox obj */
	fputs("3 0 obj <</Type /Page /Parent 2 0 R /Resources 4 0 R /MediaBox [0 0 612 792] /Contents 6 0 R>>\n", pdf);
	fputs("endobj\n", pdf);
	
	/* Font */
	fputs("4 0 obj <</Font <</F1 5 0 R>>>>\n", pdf);
	fputs("endobj\n", pdf);
 
	fputs("5 0 obj <</Type /Font /Subtype /Type1 /BaseFont /Times-Roman>>\n", pdf);
	fputs("endobj\n", pdf);

	/* Content */
	fputs("6 0 obj\n", pdf);
	fputs("<</Length 44>>\n", pdf);
	fputs("stream\n", pdf);
	fputs("BT /F1 24 Tf 175 720 Td (Hello World!)Tj ET\n", pdf);
	fputs("endstream\n", pdf);
	fputs("endobj\n", pdf);

	/* xref table */
	fputs("xref\n", pdf);
	fputs("0 7\n", pdf);
	fputs("0000000000 65535 f\n", pdf);
	fputs("0000000009 00000 n\n", pdf);
	fputs("0000000056 00000 n\n", pdf);
	fputs("0000000111 00000 n\n", pdf);
	fputs("0000000212 00000 n\n", pdf);
	fputs("0000000250 00000 n\n", pdf);
	fputs("0000000317 00000 n\n", pdf);
	fputs("trailer <</Size 7/Root 1 0 R>>\n", pdf);
	fputs("startxref\n", pdf);
	fputs("406\n", pdf);
	fputs("%%EOF\n", pdf);
	fclose(pdf);
	#endif
}

FILE* PDFWriter::img_to_pdf()
{
}

FILE* PDFWriter::html_to_pdf()
{
}
