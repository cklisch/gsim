#include "bmp.h"

void print_matrix(const char* path, int x, int y, uint64_t** matrix)
{
	FILE* file = fopen(path, "w");
	bitmap_file_header(file, max, max);
	bitmap_info_header(file, max, max);
	for (int x = 0; x < max; x++) {
		for (int y = 0; y < max; y++) {
			write_N_byte(file, matrix[x][y], 4);

		}
	}
}

void write_N_byte(FILE * file, uint64_t byte, int N) {

   
   for (int i = 0; i < N; i++)
   {
    fputc(byte % 256, file);
    byte = byte / 256;
   }
 }

void bitmap_file_header(FILE * file, int x, int y) {
  // (2 Byte, uint16_t) ASCII-Zeichenkette "BM" (Hex: 0x42 0x4D Dez: 19778).
  write_N_byte(file, 'B', 1);
  write_N_byte(file, 'M', 1);
  // (4 Byte, uint32_t) Groesse der BMP-Datei in Byte.
  // = bitmap_file_header + bitmap_info_header + Daten
  write_N_byte(file, 14 + 40 + x * y * 32, 4);
  // (4 Byte, uint32_t) Reserviert, Standard: 0
  write_N_byte(file, 0, 4);
  // (4 Byte, uint32_t) Offset der Bilddaten in Byte vom Beginn der Datei an,
  // bei Echtfarben fast immer 54 (manche Software ignoriert diese Angabe
  // daher fehlerhafterweise).
  write_N_byte(file, 54, 4);
 
 }


void bitmap_info_header(FILE * file, int x, int y) {
  // (4 Byte, uint32_t) Groesse von bitmap_info_header in Byte
  write_N_byte(file, 40, 4);
  // (4 Byte, int32_t) Breite der Bitmap in Pixel.
  write_N_byte(file, x, 4);
  // (4 Byte, int32_t) Hoehe der Bitmap in Pixel. Negativ: top-bottom.
  write_N_byte(file, -y, 4);
  // (2 Byte, uint16_t) Anzahl der Farbebenen, nicht fuer BMP verwendet
  write_N_byte(file, 1, 2);
  // (2 Byte, uint16_t) Gibt die Farbtiefe der Bitmap in bpp an; muss einer
  // der folgenden Werte sein: 1, 4, 8, 16, 24 oder 32. Bei 1, 4 und 8 bpp
  // sind die Farben indiziert.
  write_N_byte(file, 32, 2);
  // (4 Byte, uint32_t) Keine Kompression verwendet = 0
  write_N_byte(file, 0, 4);
  // (4 Byte, uint32_t) Groesse der reinen Bilddaten in Byte (mit padding).
  write_N_byte(file, x * y * 32, 4);
  // (4 Byte, int32_t) Horizontale Aufloesung des Zielausgabegerätes in Pixel
  // pro Meter; wird aber fuer BMP-Dateien meistens auf 0 gesetzt.
  write_N_byte(file, 0, 4);
  // (4 Byte, int32_t) Vertikale Aufloesung des Zielausgabegerätes in Pixel
  // pro Meter; wird aber fuer BMP-Dateien meistens auf 0 gesetzt.
  write_N_byte(file, 0, 4);
  // (4 Byte, uint32_t) Anzahl der Eintraege der Farbtabelle; 0 bedeutet keine.
  write_N_byte(file, 0, 4);
  // (4 Byte, uint32_t) Anzahl wichtiger Farben; 0 bedeutet alle sind wichtig.
  write_N_byte(file, 0, 4);
 }
