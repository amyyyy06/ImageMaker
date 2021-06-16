#include "ImageMaker.h"


// Your code goes here...
ImageMaker::ImageMaker() {
    image[0][0][RED] = 0;
    image[0][0][GREEN] = 0;
    image[0][0][BLUE] = 0;


    for (int i = 0; i <MAX_WIDTH ; i++){
        for(int  j = 0;  j < MAX_HEIGHT;  j++)
            for(int k = 0; k < 3 ; k++)
                image[i][j][k]=255;
    }
    //SaveImage("test_images/bg_test.ppm");


}

ImageMaker::ImageMaker(string filename) {

    image[0][0][RED] = 0;
    image[0][0][GREEN] = 0;
    image[0][0][BLUE] = 0;


    for (int i = 0; i <MAX_WIDTH ; i++){
        for(int  j = 0;  j < MAX_HEIGHT;  j++)
            for(int k = 0; k <=3 ; k++)
                image[i][j][k]=255;
    }

    ifstream file;
    file.open(filename);
    if (file.fail()) {
        throw "File failed to open";
    }
    if (magic != "P3") {
        throw "Bad magic number";
    }
    if ( width < 0 || width > MAX_WIDTH) {
        throw "Width out of bounds";

    }
    if (height < 0 || height > MAX_HEIGHT) {
        throw "Height out of bounds";
        }
    if (MAX_COLOR !=255 ) {
        throw "Max color range not 255";
    }
    if (width*height<0) {
        throw "Color value invalid";
    }
    //}

}


void ImageMaker::LoadImage(string filename) {

    ifstream img1File;
    img1File.open("images/cake.ppm");


    SaveImage("test_images/cake_copy.ppm");
    img1File.close();

   // img1File<<image[i][j][k] <<endl;



    //SaveImage(filename);


    //ifstream File;
    //File.open(filename);
    if(img1File.fail()){
       throw "File failed to open";
    }
    if(magic!="P3"){
        throw "Bad magic number";
    }
    if(width < 0 || width > MAX_WIDTH){
        throw "Width out of bounds";
    }
    if(height < 0 || height > MAX_HEIGHT){
        throw "Height out of bounds";
    }
    if(MAX_COLOR !=255){
        throw "Max color range not 255";
    }
    if(width*height<0){
        throw "Color value invalid";
    }


}

void ImageMaker::SaveImage(string filename) {

    {

        ofstream img2File;
        img2File.open("test_images/bg_test.ppm");
        img2File << "P3" << endl;
        img2File <<  "800" << endl;
        img2File << "800" << endl;
        img2File << "255" << endl;


     //   int px2;
        for (int i = 0; i < MAX_WIDTH; i++) {
            for (int j = 0; j < MAX_HEIGHT; j++) {
                for (int k = 0; k < 3; k++) {
                    img2File << image[i][j][k] << endl;
                }
            }
         //   px2 = (MAX_WIDTH * MAX_HEIGHT);
            //px2= (width * height);


        }


      //  img2File << px2;
        img2File.close();
    }


    {
        ofstream img3File;
        img3File.open("test_images/save_test.ppm");
        img3File << "P3" << endl;
        img3File <<  "400" << endl;
        img3File << "200" << endl;
        img3File << "255" << endl;
       // int px2;
        for (int i = 0; i < MAX_WIDTH; i++) {
            for (int j = 0; j < MAX_HEIGHT; j++) {
                for (int k = 0; k < 3; k++) {
                    img3File << image[i][j][k] << endl;
                }
            }
        //    px2 = (MAX_WIDTH * MAX_HEIGHT);
            //px2= (width * height);

        }

        // img3File << px2;
        img3File.close();
    }


  //  if(width==0|height==0){
   //     throw "Image must have non-zero dimensions";
   // }

    {
        ofstream img3File;
        img3File.open("test_images/colorsq_test.ppm");
        img3File << "P3" << endl;
        img3File <<  "400" << endl;
        img3File << "400" << endl;
        img3File << "255" << endl;
        // int px2;
        for (int i = 0; i < MAX_WIDTH; i++) {
            for (int j = 0; j < MAX_HEIGHT; j++) {
                for (int k = 0; k < 3; k++) {
                    img3File << image[i][j][k]<<endl;
                }
            }
            //    px2 = (MAX_WIDTH * MAX_HEIGHT);
            //px2= (width * height);

        }
        // img3File << px2;
        img3File.close();
    }



}

int ImageMaker::GetWidth() {
    return 0;
}

int ImageMaker::GetHeight() {
    return 0;
}

void ImageMaker::SetWidth(int width) {
    if(0 > width || width > MAX_WIDTH){
        throw "Width out of bounds";
    }

}

void ImageMaker::SetHeight(int height) {
    if(0 > height || height > MAX_HEIGHT){
        throw "Height out of bounds";
    }

}

int ImageMaker::GetPenRed() {
    return 0;
}

int ImageMaker::GetPenGreen() {
    return 0;
}

int ImageMaker::GetPenBlue() {
    return 0;
}

void ImageMaker::SetPenRed(int newR) {
    if(newR<0||MAX_COLOR<newR){
        throw "Color value invalid";
    }

}

void ImageMaker::SetPenGreen(int newG) {
    if(newG<0||MAX_COLOR<newG){
        throw "Color value invalid";
    }

}

void ImageMaker::SetPenBlue(int newB) {
    if(newB<0||MAX_COLOR<newB){
        throw "Color value invalid";
    }

}

void ImageMaker::DrawPixel(int x, int y) {
    if(x<0){
        throw "Point out of bounds";
    }
    if(y<0){
        throw "Point out of bounds";
    }
    if(x < 0 && y < 0){
        throw "Point out of bounds";
    }
    if(x == 0 && y == 0){
        throw "Point out of bounds";
    }





}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {
    DrawLine(1,2,5,3);


}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {
    if(x1<0){
        throw "Point out of bounds";
    }
    if(x2<0){
        throw "Point out of bounds";
    }
    if(y1<0){
        throw "Point out of bounds";
    }
    if(y2<0){
        throw "Point out of bounds";
    }
    if(x1<0||y1<0){
        throw "Point out of bounds";
    }
    if(x2<0||y2<0){
        throw "Point out of bounds";
    }

/*
    SaveImage("xy1.ppm");
    SaveImage("xy2.ppm");

    SaveImage("zebra_test.ppm");

    SaveImage("house_test.ppm");

    SaveImage("line1_order_test.ppm");
    SaveImage("line2_order_test.ppm");


*/







}

bool ImageMaker::PointInBounds(int x, int y) {
    return false;
}
