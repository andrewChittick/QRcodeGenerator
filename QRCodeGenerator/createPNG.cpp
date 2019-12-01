#include <vector>
#include <iostream>
#include "createPNG.h"

//createPNG.cpp
//Marcellus Hunt
//10/15/19

/*
LodePNG Examples
Copyright (c) 2005-2012 Lode Vandevenne
This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:
    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.
    3. This notice may not be removed or altered from any source
    distribution.
*/

//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

void makeImage(int level,int **input){
	//make a white
	
		//make a blue line(column)
		// v1: 29 x 29 x 4 = 3364 matrix
		//v2: 33 x 33 x 4 = 4356
		
		//0 white 1 Black; 255 white 0 black
		
		//for the 29 x 29 matrix
        int x = 0;
		//if version 1
        if (level ==1)
		{
			std::vector<unsigned char> newImage (3364, 255);
			

            for (int i =0; i < 29; i++)
			{
                for (int j = 0; j < 29; j++)
                {
                    // if the matrix[i] == 1
                    if (input[i][j] == 1)
                    {
                        //then set i*4 = 0, i*4+1 = 0;, i*4+2 = 0;
                        newImage[x*4] = 0;
                        newImage[x*4+1] = 0;
                        newImage[x*4+2] = 0;
                        x++;
                    }
                }
			
			}
		//make a PNG
        std::cout<<"hfsalkJDS";
        encodeOneStep("QR.png", newImage,29,29);
		}
				
				
		//if version 2
        x = 0;
		if (level == 2)
		{
        std::vector<unsigned char> newImage (4356, 255);
		//for the 33 x 33 matrix
            for (int i = 0; i < 1089; i++)
			{
                for (int j = 0; j < 33; j++)
                {
                    //if the matrix [i] ==1
                    if(input[i][j] == 1)
                    {
                        //then i*4 = 0, i*4+1 = 0; i*4+2 = 0;
                        newImage[x*4] = 0;
                        newImage[x*4 + 1] = 0;
                        newImage[x*4+2] = 0;
                        x++;
                    }
                }
			}
			
		//make a PNG
        encodeOneStep("QR.png", newImage,33,33);
		}
		
}



