#include "ImageMaker.h"


// Your code goes here...
ImageMaker::ImageMaker() {
    //using constructor delegation
   // ImageMaker(""){}

    //set private variable to 0
    width = 0;
    height = 0;
    pen_red = 0;
    pen_green = 0;
    pen_blue = 0;
    magic = "P3";


// set every value in the image variable to 225

    for (int w = 0; w != MAX_WIDTH; w++){
        for(int  h = 0;  h != MAX_HEIGHT;  h++)
            for(int k = 0; k != 3 ; k++)
                image[w][h][k]=255;
    }


}

ImageMaker::ImageMaker(string filename) {
    //set private variable to 0
    width = 0;
    height = 0;
    pen_red = 0;
    pen_green = 0;
    pen_blue = 0;
    magic = "P3";


// set every value in the image variable to 225

    for (int w = 0; w != MAX_WIDTH; w++){
        for(int  h = 0;  h != MAX_HEIGHT;  h++)
            for(int k = 0; k != 3 ; k++)
                image[w][h][k]=255;
    }

    if (filename != ""){
        LoadImage(filename);
    }

}


void ImageMaker::LoadImage(string filename) {
// open on existing ppm image file
    ifstream img1File;
    img1File.open(filename);

    if(img1File.fail()){
       throw "File failed to open";
    }

    //store data into class imageMaker
    // read magic string

    string s;
    img1File >> s;

    if(s !="P3"){
        throw "Bad magic number";
    }

    int width, height, max_color;
    img1File >> width >> height >> max_color;

    SetWidth(width);
    SetHeight(height);

    //check max_color
    if( max_color !=255){
        throw "Max color range not 255";
    }

    //read pixel data
    //for each x, y coordinate

    for(int h = 0; h != height; h++){
        for(int w = 0; w != width; w++){
            int newR, newG, newB;
            // read RGB data
            img1File >> newR >> newG >> newB;
            //check RGB data

            if(newR < 0 || newR > 255 || newG < 0|| newG > 255 || newB < 0 || newB >255){
                throw "Color value invalid";
            }

            // set the pixel color

            image[w][h][RED] = newR;
            image[w][h][GREEN] = newG;
            image[w][h][BLUE] = newB;
        }

    }

    img1File.close();

}

void ImageMaker::SaveImage(string filename) {

    ofstream outFile;
    outFile.open(filename);
    //write magic number to file
    outFile << "P3\n";
    //check width and height to file
    outFile << GetWidth() << " " << GetHeight() << endl;

    if(width == 0 || height == 0){
        throw "Image must have non-zero dimensions";
    }


    //write max color value
    outFile << MAX_COLOR << endl;
    //write pixel data
    //For each x, y coordinate
    for (int h = 0; h != height; h++){ //getHeight()
        for(int w = 0; w != width; w++){ //getWidth()
            //write the pixel color
            outFile << image[w][h][RED] << " ";
            outFile << image[w][h][GREEN] << " ";
            outFile << image[w][h][BLUE] << " ";
        }

        outFile << " " << endl;
    }


    //finish writing file
    outFile.close();


}

int ImageMaker::GetWidth() {
    return width;
}

int ImageMaker::GetHeight() {
    return height;
}

void ImageMaker::SetWidth(int width) {
    if(width < 0 || width > MAX_WIDTH){
        throw "Width out of bounds";
    }
    this->width=width;
}

void ImageMaker::SetHeight(int height) {
    if(height < 0 || height > MAX_HEIGHT){
        throw "Height out of bounds";
    }
    this->height = height;
}

int ImageMaker::GetPenRed() {
    return pen_red;
}

int ImageMaker::GetPenGreen() {
    return pen_green;
}

int ImageMaker::GetPenBlue() {
    return pen_blue;
}

void ImageMaker::SetPenRed(int newR) {
    if(newR < 0 || MAX_COLOR < newR){
        throw "Color value invalid";
    }
    pen_red = newR;
}

void ImageMaker::SetPenGreen(int newG) {
    if(newG<0||MAX_COLOR<newG){
        throw "Color value invalid";
    }
    pen_green = newG;

}

void ImageMaker::SetPenBlue(int newB) {
    if(newB<0||MAX_COLOR<newB){
        throw "Color value invalid";
    }
    pen_blue = newB;

}

void ImageMaker::DrawPixel(int x, int y) {
    if(x < 0|| x >= width || y < 0 || y >= height){
        throw "Point out of bounds";
    }

    image[x][y][RED] = pen_red;
    image[x][y][GREEN] = pen_green;
    image[x][y][BLUE] = pen_blue;



}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {

    if(x1 < 0 || x1 > width || y1 < 0 || y1 > height || x2 < 0|| x2 > width || y2 < 0 || y2 > height){
        throw "Point out of bounds";
    }

    if(x1 > x2){
        swap(x1, x2);
    }
    if(y1 > y2){
        swap(y1, y2);
    }

    for(int x = x1; x <= x2; x++){
        DrawLine(x, y1, x, y2);
    }
    for(int y = y1; y <= y2; y++){
        DrawLine(x1, y, x2, y);
    }



}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {
    float m, b, y;
    float dx, dy;

    if(x1 < 0 || x1 > width || y1 < 0 || y1 > height || x2 < 0|| x2 > width || y2 < 0 || y2 > height){
        throw "Point out of bounds";
    }

    if(x1 == x2 && y1== y2){
        DrawPixel(x1, y1);
    }
    else if(y1 == y2){ //horizontal //y1 == y2 (2,5)(3,5)
        if(x1 > x2){
            swap(x1, x2);
        }
        for(int x = x1; x <= x2; x++){
            DrawPixel(x, y1);
        }
    }
    else if(x1 == x2){ // vertical // x1 == x2 (3,3) (3,5)
        if(y1 > y2){
            swap(y1, y2);
        }
        for(int x = y1; x <= y2; x++){
            DrawPixel(x1, x);
        }
    }
    else{
        dx = x2 - x1;
        dy = y2 - y1;
        m = dy/dx;
        b = y1 - m * x1;
        if(x1 > x2){
            swap(x1, x2);
        }
        for(int x = x1; x <= x2; x++){

            y = m*x + b;
            int yy = round(y);
            DrawPixel(x, yy);
        }
    }
}

bool ImageMaker::PointInBounds(int x, int y) {
    return false;
}
