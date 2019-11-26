#include <iostream>
#include <cmath>

int scorePattern(int **c, int width)
{
    int score = 0;
    // score method 1
    // 5 squares in a row of the same color gets 3 points, every color of that in a row gets 1
    // vertical and horizontal
    int counter = 0;
    int currentColor = 2;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (currentColor == c[i][j])
            {
                counter += 1;
            }
            else
            {
                if (counter >= 5)
                {
                    score += 3;
                    counter -= 5;
                    score += counter;
                }
                currentColor = c[i][j];
                counter = 1;
            }
            if (j == width - 1 && counter >= 5)
            {
                score += 3;
                counter -= 5;
                score += counter;
            }
        }
        currentColor = 2;
        counter = 0;
    }
    
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (currentColor == c[j][i])
            {
                counter += 1;
            }
            else
            {
                if (counter >= 5)
                {
                    score += 3;
                    counter -= 5;
                    score += counter;
                }
                currentColor = c[j][i];
                counter = 1;
            }
            if (j == width - 1 && counter >= 5)
            {
                score += 3;
                counter -= 5;
                score += counter;
            }
        }
        currentColor = 2;
        counter = 0;
    }
    
    // score method 2
    // 3 points for every 2x2 square of the same color
    for (int i = 0; i < width - 1; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            currentColor = c[i][j];
            if (currentColor == c[i + 1][j] && currentColor == c[i][j + 1] && currentColor == c[i + 1][j + 1])
            {
                score += 3;
            }
        }
    }
    
    
    
    // score method 3
    // look for either 10111010000 or 00001011101, if found add 40 to score
    int row1[11] = {1,0,1,1,1,0,1,0,0,0,0};
    int row2[11] = {0,0,0,0,1,0,1,1,1,0,1};
    for (int i = 0; i < width; i++)
    {
        bool hasRow1 = true;
        bool hasRow2 = true;
        for (int j = 0; j < width - 11; j++)
        {
            for (int k = 0; k < 11; k++)
            {
                if (c[i][j + k] != row1[k])
                {
                    hasRow1 = false;
                }
                if (c[i][j + k] != row2[k])
                {
                    hasRow2 = false;
                }
            }
            if (hasRow1)
                score += 40;
            if (hasRow2)
                score += 40;
            hasRow1 = true;
            hasRow2 = true;
        }
    }
    
    for (int i = 0; i < width - 11; i++)
    {
        bool hasRow1 = true;
        bool hasRow2 = true;
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 11; k++)
            {
                if (c[j][i + k] != row1[k])
                {
                    hasRow1 = false;
                }
                if (c[j][i + k] != row2[k])
                {
                    hasRow2 = false;
                }
            }
            if (hasRow1)
                score += 40;
            if (hasRow2)
                score += 40;
            hasRow1 = true;
            hasRow2 = true;
        }
    }
    
    // score method 4
    // get total number of cells, and total of dark cells
    // get percent dark
    // find closest multiples of five 
    // sub both from 50, take abs values, and divide them by 5
    // take the smaller number and multiply it by 10 and add to the score
    int totalCells = width * width;
    int totalDark = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (c[i][j] == 1)
            {
                totalDark += 1;
            }
        }
    }
    
    int percentDark = (double(totalDark) / double(totalCells)) * 100;
    
    int bottomFactor = percentDark / 5;
    int upperFactor = bottomFactor + 5;
    
    bottomFactor = std::abs(bottomFactor - 50) / 5;
    upperFactor = std::abs(upperFactor - 50) / 5;
    
    if (bottomFactor > upperFactor)
        score += upperFactor * 10;
    else
        score += bottomFactor * 10;
    
    std::cout << "Score: " << score << std::endl;
    return score;
}

void genMaskingPatterns(int **c, int version)
{
    int width;
    
    if (version == 1)
    {
        width = 21;
    }
    else if (version == 2)
    {
        width = 24;
    }
    
    bool flipBit = false;
    
    // pattern 1
    std::cout << "Mask 1: " << std::endl;
    int **pat1 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && (i + j) % 2 == 0)
            {
                if (pat1[i][j] == 0)
                    pat1[i][j] = 1;
                else
                    pat1[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat1, width);
    std::cout << "\n\n";
    
    // pattern 2
    std::cout << "Mask 2: " << std::endl;
    int **pat2 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && (j) % 2 == 0)
            {
                if (pat2[i][j] == 0)
                    pat2[i][j] = 1;
                else
                    pat2[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat2, width);
    std::cout << "\n\n";
    
    // pattern 3
    std::cout << "Mask 3: " << std::endl;
    int **pat3 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && (i) % 3 == 0)
            {
                if (pat3[i][j] == 0)
                    pat3[i][j] = 1;
                else
                    pat3[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat3[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat3, width);
    std::cout << "\n\n";
    
    // pattern 4
    std::cout << "Mask 4: " << std::endl;
    int **pat4 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && (i + j) % 3 == 0)
            {
                if (pat4[i][j] == 0)
                    pat4[i][j] = 1;
                else
                    pat4[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat4[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat4, width);
    std::cout << "\n\n";
    
    // pattern 5
    std::cout << "Mask 5: " << std::endl;
    int **pat5 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && int(j / 2) + int(i / 3) % 2 == 0)
            {
                if (pat5[i][j] == 0)
                    pat5[i][j] = 1;
                else
                    pat5[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat5[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat5, width);
    std::cout << "\n\n";
    
    // pattern 6
    std::cout << "Mask 6: " << std::endl;
    int **pat6 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && ((i * j) % 2) + ((i * j) % 3) == 0)
            {
                if (pat6[i][j] == 0)
                    pat6[i][j] = 1;
                else
                    pat6[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat6[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat6, width);
    std::cout << "\n\n";
    
    // pattern 7
    std::cout << "Mask 7: " << std::endl;
    int **pat7 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && ((i * j) % 2) + ((i * j) % 3) % 2 == 0)
            {
                if (pat7[i][j] == 0)
                    pat7[i][j] = 1;
                else
                    pat7[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat7[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat7, width);
    std::cout << "\n\n";
    
    // pattern 8
    std::cout << "Mask 8: " << std::endl;
    int **pat8 = c;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 7 || j > 7) && (i > 7 || j < width - 8) && (i < width - 8 || j > 7))
            {
                if (version == 2 && (i < 16 || i > 20 || j < 16 || j > 20))
                {
                    flipBit = true;
                }
                else if (version == 1)
                {
                    flipBit = true;
                }
            }
            if (flipBit && ((i + j) % 2) + ((i * j) % 3) % 2 == 0)
            {
                if (pat7[i][j] == 0)
                    pat7[i][j] = 1;
                else
                    pat7[i][j] = 0;
            }
            flipBit = false;
            std::cout << pat7[i][j] << " ";
        }
        std::cout << std::endl;
    }
    scorePattern(pat8, width);
    std::cout << "\n\n";
    
}

void maskingControl(int **c, int version)
{
    genMaskingPatterns(c, version);
}

int main()
{
    int QRcode[21][21] = {{1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,1,1,1,1},
                          {1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1},
                          {1,0,1,1,1,0,1,0,1,0,0,1,1,0,1,0,1,1,1,0,1},
                          {1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,1},
                          {1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1},
                          {1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
                          {1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1},
                          {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,1,1},
                          {0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,1},
                          {0,0,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,0,0,0},
                          {0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,1,0,1,1,1,0},
                          {1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1},
                          {0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,1},
                          {1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0},
                          {1,0,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,1,0,0,0},
                          {1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,1},
                          {1,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0},
                          {1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,1,0,1,0,0,1},
                          {1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,1,1},
                          {1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1}};
            
    int *QRrows[21];
    for (int i = 0; i < 21; i++)
        QRrows[i] = QRcode[i];
    
    int **code = QRrows;
    
    maskingControl(code, 1);
    
    return 0;
}


