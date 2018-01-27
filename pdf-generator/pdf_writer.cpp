#include "pdf_writer.h"

PDFWriter::PDFWriter(FILE *f, string e): file(f), extension(e)
{
}

PDFWriter::PDFWriter(FILE *f, string e, string o): file(f), extension(e), out(o)
{
}
