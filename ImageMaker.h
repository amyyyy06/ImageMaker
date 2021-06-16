//
// Assignment Created by Varick Erickson
//

#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

#include <string>
#include <cmath>
#include <fstream>

const int MAX_WIDTH = 800;
const int MAX_HEIGHT = 800;
const int MAX_COLOR = 255;
enum COLOR { RED, GREEN, BLUE };

using namespace std;

//  Please put your pre and post comments in this file. See page 139 in the textbook.

class ImageMaker
{
public:
    ImageMaker();
    ImageMaker(string filename);

    // Opens image with filename and stores information into
    void LoadImage(string filename);
    // Pre:
    // Post:
    void SaveImage(string filename);
    // Pre:
    // Post:

    // Size functions
    int GetWidth();
    int GetHeight();
    // Pre:  Image has been initialized.
    // Post:
    void SetWidth(int width);
    void SetHeight(int height);
    // Pre: Image has been initialized
    // Post:

    // Color functions
    int GetPenRed();
    int GetPenGreen();
    int GetPenBlue();
    // Pre:  Image has been initialized.
    // Post:
    void SetPenRed(int newR);
    void SetPenGreen(int newG);
    void SetPenBlue(int newB);
    // Pre: Image has been initialized
    // Post:

    // Drawing methods
    // These methods will use the current red, green, blue values of the pen
    void DrawPixel(int x, int y);
    // Pre: Image has been initialized
    // Post:
    void DrawRectangle(int x1, int y1, int x2, int y2);
    // Pre: Image has been initialized
    // Post:
    void DrawLine(int x1, int y1, int x2, int y2);
    // Pre: Image has been initialized
    // Post:

private:
    string magic;
    int width{};
    int height{};
    int pen_red{};    // Used by draw functions
    int pen_green{};  // Used by draw functions
    int pen_blue{};   // Used by draw functions
    bool PointInBounds(int x, int y);  // Not a bad idea to implement

               //   x          y
    short image[MAX_WIDTH][MAX_HEIGHT][3]{};
};

#endif //IMAGEMAKER_H
