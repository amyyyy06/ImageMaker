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
    SaveImage("test_images/bg_test.ppm");


}

ImageMaker::ImageMaker(string filename) {


  //  LoadImage("images/cake.ppm");

    image[0][0][RED] = 0;
    image[0][0][GREEN] = 0;
    image[0][0][BLUE] = 0;

   // SaveImage("test_images/cake_copy.ppm");

  //  LoadImage("images/blocks.ppm");
  //  SaveImage("test_images/blocks_copy.ppm");

  //  LoadImage("cake.ppm");

    for (int i = 0; i <MAX_WIDTH ; i++){
        for(int  j = 0;  j < MAX_HEIGHT;  j++)
            for(int k = 0; k <=3 ; k++)
                image[i][j][k]=255;
    }
 //  SaveImage("test_images/cake_bg_test.ppm");


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

    ImageMaker imgTest;
    imgTest.LoadImage("images/cake.ppm");

    imgTest.SaveImage("test_images/cake_copy.ppm");
    imgTest.SaveImage("test_images/cake_bg_test.ppm");

    ImageMaker imgCake;

    imgCake.SaveImage("test_images/cake_copy.ppm");

    ImageMaker imgBlock;
    imgBlock.LoadImage("images/blocks.ppm");

    imgBlock.SaveImage("test_images/blocks_copy.ppm");


    ifstream File;
    File.open(filename);
    if(File.fail()){
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
/*
     ofstream img1File;
        img1File.open("test_images/save_test.ppm");
        img1File<< "P3"<<endl;
        img1File<<"400"<<endl;
        img1File<<"200"<<endl;
        img1File<<"255"<<endl;
        img1File.close();

*/

   // if(width==0){
   //     throw "Image must have non-zero dimensions";
   // }
 //   ImageMaker img;
 //   img.SetWidth(10);
 //   img.SetHeight(450);
 //   img.SaveImage("test_images/bg_test.ppm");





    ofstream img2File;
    img2File.open("test_images/bg_test.ppm");
    img2File<< "P3"<<endl;
    img2File<<"800"<<endl;
    img2File<<"800"<<endl;
    img2File<<"255"<<endl;
   // image[800][800][RED];
   // image[800][800][GREEN];
   // image[800][800][BLUE];
    //image[MAX_WIDTH][MAX_HEIGHT][3];
    int px2;
    for (int i = 0; i <MAX_WIDTH ; i++){
        for(int  j = 0;  j < MAX_HEIGHT;  j++)
            for(int k = 0; k < 3 ; k++)
                //image[i][j][k]={255};
                image[i][j][k] = {255};

     //   px2= height*width;


      //  img2File >> px2;

    }
    px2=width*height;
    img2File << px2;
    img2File.close();



  //  magic = "P3";
   // width = MAX_WIDTH;
   // height = MAX_HEIGHT;




    //img2File >> magic2 >> width2 >> height2 >>;

    //img2File.close();
    //file<<"P3"<<endl;








   // ofstream file;
   // file.open(filename);

   // string magic = "P3";



   // file.open("save_test.ppm");


    //file.close();

   // if(width<=0){
   //     throw "Image must have non-zero dimensions";
   // }







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
