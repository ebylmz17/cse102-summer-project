#ifndef cad2d
#define cad2d

#define INIT_SIZE_HIER 10 /* Size of hash table */
#define INIT_SIZE_HASH 10 /* Size of hash table */

/*********************************************************************************
 * Fundamental Structures
*********************************************************************************/

typedef enum {
    point, line, spline, polyline, polygon,
    rectangle, circle, arc, ellipse, text, image
} EntityType;

typedef enum {
    white, silver, gray, black, red, maroon, yellow, 
    olive, lime, green, aqua, teal, blue, navy,
    fuchsia, purple
} ColorPalette;

typedef enum  {stroke, fill} DrawStyle;

/* RGB color scheme */
typedef struct RGBColor {
    double red, green, blue;
} RGBColor;

typedef struct LineStyle {
    //! NOT IMPLEMENTED YET:
} LineStyle;

typedef struct Style {
    //! NOT IMPLEMENTED YET: Color choice
    LineStyle line_style;
    double thickness;
    int filled;
} Style;

typedef struct Label {
    EntityType type;    /* identifies the type of the cad entity */
    char * name;        /* name of the object */
    int hash_code;      /* labels are should be unique to do that we use hashing */
} Label;

typedef struct Entity {
    Label * label;      /* unique label to identify cad entities */
    void * data;        /* specific data for the entity like radius for Circle type */
} Entity;

typedef struct Size {
    int cur, max;
} Size;

typedef struct Hierarchy {
    CAD2D * cad;
    struct Hierarchy * parent;
    struct Hierarchy ** children;   /* array of children hierarchies */
    Size size;
} Hierarchy;

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

typedef struct Line {
    Point2D start, end;
    Style style;
} Line;

typedef struct Arc {
    Point2D center;
    double radius;
    double start_angle, end_angle;
    Style style;
} Arc; 

typedef struct Circle {
    Point2D center;
    double radius;
    double start_angle, end_angle;
    Style style;
} Circle;

// ! We actualy do not need a new data type for polyline, we can add * next inside of the Point2D
typedef struct Polyline {
    Point2D point;
    struct Polyline * next;
    Style style;
} Polyline;

typedef struct Text {
    Point2D point;
    char * text_field;
    Style style;
} Text;

typedef struct Rectangle {
    Point2D corner_down_left, corner_top_right;
    Style style;
} Rectangle;

typedef struct Spline {
    //! NOT IMPLMENTED YET
} Spline;

typedef struct Polygon {
    //! NOT IMPLMENTED YET
} Polygon;

typedef struct Ellipse{
    //! NOT IMPLMENTED YET
} Ellipse;

typedef struct Image {
    //! NOT IMPLMENTED YET
} Image;

/*********************************************************************************
 * Function Definitions
*********************************************************************************/

CAD2D * c2d_start_wh (double width, double height);
CAD2D * c2d_start();
Label * c2d_add_line(CAD2D * cad, Point2D start, Point2D end);
Label * c2d_add_point_xy (CAD2D * cad, double x, double y);
void c2d_export (CAD2D * cad, char * file_name, char * options);
void c2d_export_eps (CAD2D * cad, char * file_name);
Label * c2d_add_arc (CAD2D * cad, Point2D center, double radius, double start_angle, double end_angle);

#endif

