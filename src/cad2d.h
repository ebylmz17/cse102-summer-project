#ifndef cad2d
#define cad2d

#define INIT_HIER 10 /* Size of hierarcy array */
#define INIT_HASH 10 /* Size of hash table */
#define PRIME 17 /* Prime number for hash function */

/*********************************************************************************
 * Fundamental Structures
*********************************************************************************/
typedef struct {
    int p, q;
} HashInfo;

typedef enum {
    point_t, line_t, spline_t, polyline_t, polygon_t,
    rectangle_t, circle_t, arc_t, ellipse_t, text_t, image_t
} EntityType;

typedef struct {
    double red, green, blue;
} RGBColor;

typedef enum {
    red, green, green_dark, blue, blue_light, magenta,
    yellow, white, black, orange, purple, brown 
} Color;

typedef enum {
    Helvetica, Courier, Times, Coronet, Symbol, Albertus, Arial, Bodoni
} FontStyle;

typedef enum {
    dashed, solid
} LineStyle;

typedef enum  {
    stroke, fill
} DrawStyle;

//! NOT IMPLEMENTED YET: Set proper values
/*
typedef enum {
    small, medium, large
} LineWidth;

typedef enum {
    small, medium, large
} FontScale;
*/

// ! any basic 2D shape can have color, thickness and line style       
//* use -1 for default style choices
typedef struct {
    LineStyle line;
    RGBColor color;
    DrawStyle draw;
    double line_width;
} EntityStyle;

typedef struct {
    FontStyle font;
    double scale; //! ???
    RGBColor color;
} TextStyle;

typedef struct Label {
    EntityType type;    /* identifies the type of the cad entity */
    char * name;        /* name of the object */
    int hash_code;      /* labels are should be unique to do that we use hashing */
} Label;

typedef struct Entity {
    Label * label;      /* unique label to identify cad entities */
    void * data;        /* specific data for the entity like radius for Circle type */
    //! EntityStyle style;    
} Entity;

typedef struct Size {
    int cur, max;
} Size;

typedef struct Hierarchy {
    struct CAD2D * cad;
    char * name;
    struct Hierarchy * parent;
    struct Hierarchy ** child;   /* array of child hierarchies */
    Size size;
} Hierarchy;

/* also used as Line, Polyline and Polygone */
typedef struct Point2D {
    double x, y;
    struct Point2D * next;
} Point2D;

typedef struct Canvas {
    Point2D start;      /* (-width/2, -height/2) */
    Point2D end;        /* ( width/2,  height/2) */
} Canvas;

typedef struct CAD2D {
    Canvas * canvas;
    Size list_size;         
    Entity ** list;         /* hash table for keeping entities */
    Hierarchy * hierarchy;  /* to reach all the CAD entities */    
} CAD2D;

/*********************************************************************************
 * Basic CAD Entities:
 * point, line, spline, polyline, polygon, rectangle, circle, arc, ellipse, text, image
*********************************************************************************/


/*
typedef struct Line {
    Point2D start, end;
    EntityStyle style;
} Line;

typedef struct Polyline {
    Point2D point;
    // struct Polyline * next;
    EntityStyle style;
} Polyline;


typedef struct Polygon {
    Point2D point;
    struct Polyline * next;
    EntityStyle style;
    //! NOT IMPLMENTED YET
} Polygon;
*/

typedef struct Arc {
    Point2D center;
    double radius;
    double start_angle, end_angle;
    EntityStyle style;
} Arc; 

typedef struct Circle {
    Point2D center;
    double radius;
    double start_angle, end_angle;
    EntityStyle style;
} Circle;

typedef struct Text {
    Point2D point;
    char * text;
    TextStyle * style;
} Text;

/*
    D--C        we need corners at down-left and top-right
    |  |
    A--B
*/
typedef struct Rectangle {
    Point2D cornerA, cornerC;
    EntityStyle style;
    //* NOT IMPLMENTED YET
} Rectangle;

typedef struct Spline {
    //! NOT IMPLMENTED YET
} Spline;

typedef struct Ellipse{
    Point2D center;
    double width, hight;
    //* NOT IMPLMENTED YET
} Ellipse;

typedef struct Image {
    //! NOT IMPLMENTED YET
} Image;

/*********************************************************************************
 * Function Definitions
*********************************************************************************/
CAD2D * c2d_start();
CAD2D * c2d_start_wh (double width, double height);
CAD2D * c2d_start_wh_hier (double width, double height, Hierarchy * h);

Hierarchy * c2d_create_hierarchy (CAD2D * cad);
Hierarchy * c2d_create_hierarchy_parent (CAD2D * cad, Hierarchy * parent);
//* Hierarchy * c2d_create_hierarchy?(CAD2D * cad, …) {}

Point2D * c2d_create_point (double x, double y);
Label * c2d_create_label (CAD2D * cad, EntityType type, char * name);
EntityStyle * c2d_create_entity_style (LineStyle l, RGBColor c, DrawStyle d, double w);
TextStyle * c2d_create_text_style (FontStyle f, RGBColor c, double s);

Label * c2d_add_point_xy (CAD2D * cad, double x, double y);
Label * c2d_add_line(CAD2D * cad, Point2D *start, Point2D * end);
Label * c2d_add_arc (CAD2D * cad, Point2D center, double radius, double start_angle, double end_angle);
Label * c2d_add_circle (CAD2D * cad, Point2D center, double radius);
Label * c2d_add_rectangle (CAD2D * cad, Point2D cornerA , Point2D cornerC);
// Label * c2d_add_polyline (CAD2D * cad, Point2D * p);
Label * c2d_add_polyline (CAD2D * cad, Point2D * p, int size);
Label * c2d_add_text (CAD2D * cad, Point2D * point, char * text, TextStyle * style);

void c2d_export (CAD2D * cad, char * file_name, char * options);
CAD2D * c2d_import (char * file_name, char * options);
void c2d_delete (CAD2D * cad);

#endif

