#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input.pgm> <output.jpg>" << std::endl;
        return 1;
    }

    // Read the input image
    cv::Mat inputImage = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (inputImage.empty())
    {
        std::cerr << "Error: Could not open or find the image." << std::endl;
        return 1;
    }

    // Save the image as JPG
    if (!cv::imwrite(argv[2], inputImage))
    {
        std::cerr << "Error: Could not save the image." << std::endl;
        return 1;
    }

    std::cout << "Image successfully converted to JPG and saved as " << argv[2] << std::endl;
    return 0;
}
