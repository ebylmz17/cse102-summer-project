#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cad2d.h"

// ! label için point olur birde textfield olur belkide hashcode olur

/* ****************************************************************
! NOT IMPLEMENTED YET
**************************************************************** */ 

void u_print_gtucad_text_style (FILE * fid, TextStyle * s) {}
void u_print_gtucad_entity_style (FILE * fid, Label * l, EntityStyle * s) {}
void u_print_gtucad_xy_plane (FILE * fid, Canvas * canvas, EntityStyle * s) {}
void u_print_gtucad_circle (FILE * fid, Circle * e) {}
void u_print_gtucad_ellipse (FILE * fid, Ellipse * e) {}
void u_print_gtucad_triangle (FILE * fid, Triangle * e) {}
void u_print_gtucad_rectangle (FILE * fid, Rectangle * e) {}
void u_print_gtucad_line (FILE * fid, PointList * e) {}
void u_print_gtucad_spline (FILE * fid, PointList * e) {}
void u_print_gtucad_regular_polygon (FILE * fid, RegularPolygon * e) {}
void u_print_gtucad_text (FILE * fid, Text * e) {}

/*
1 0 0 		 setrgbcolor	red
0 1 0 		 setrgbcolor	green
0 0 1 		 setrgbcolor	dark blue
0 1 1 		 setrgbcolor	light blue
1 0 1 		 setrgbcolor	magenta
1 1 0 		 setrgbcolor	yellow
1 1 1 		 setrgbcolor	white
0 0 0 		 setrgbcolor	black
1.0 0.7 0.0  setrgbcolor	orange
0.7 0.3 1.0  setrgbcolor	purple
0.7 0.3 0.0  setrgbcolor	brown
0.0 0.5 0.0  setrgbcolor	dark green
*/

/*
typedef enum {
    white, silver, gray, black, red, maroon, yellow, 
    olive, lime, green, aqua, teal, blue, navy,
    fuchsia, purple
} ColorPalette;
*/

/*
    White 	#FFFFFF 	rgb(255, 255, 255)
	Silver 	#C0C0C0 	rgb(192, 192, 192)
	Gray 	#808080 	rgb(128, 128, 128)
	Black 	#000000 	rgb(0, 0, 0)
	Red 	#FF0000 	rgb(255, 0, 0)
	Maroon 	#800000 	rgb(128, 0, 0)
	Yellow 	#FFFF00 	rgb(255, 255, 0)
	Olive 	#808000 	rgb(128, 128, 0)
	Lime 	#00FF00 	rgb(0, 255, 0)
	Green 	#008000 	rgb(0, 128, 0)
	Aqua 	#00FFFF 	rgb(0, 255, 255)
	Teal 	#008080 	rgb(0, 128, 128)
	Blue 	#0000FF 	rgb(0, 0, 255)
	Navy 	#000080 	rgb(0, 0, 128)
	Fuchsia #FF00FF 	rgb(255, 0, 255)
	Purple 	#800080 	rgb(128, 0, 128)
*/
