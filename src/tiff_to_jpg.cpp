#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_directory> <output_directory>" << std::endl;
        return 1;
    }

    std::string inputDirectory = argv[1];
    std::string outputDirectory = argv[2];

    // Check if the input directory exists
    if (!fs::exists(inputDirectory) || !fs::is_directory(inputDirectory))
    {
        std::cerr << "Error: Input directory does not exist or is not a directory." << std::endl;
        return 1;
    }

    // Check if the output directory exists, if not create it
    if (!fs::exists(outputDirectory))
    {
        if (!fs::create_directory(outputDirectory))
        {
            std::cerr << "Error: Could not create output directory." << std::endl;
            return 1;
        }
    }

    // Iterate through all files in the input directory
    for (const auto &entry : fs::directory_iterator(inputDirectory))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".tiff")
        {
            std::string inputFilePath = entry.path().string();
            std::string outputFilePath = outputDirectory + "/" + entry.path().stem().string() + ".jpg";

            // Read the input image
            cv::Mat inputImage = cv::imread(inputFilePath, cv::IMREAD_UNCHANGED);
            if (inputImage.empty())
            {
                std::cerr << "Error: Could not open or find the image: " << inputFilePath << std::endl;
                continue;
            }

            // Save the image as JPG
            if (!cv::imwrite(outputFilePath, inputImage))
            {
                std::cerr << "Error: Could not save the image: " << outputFilePath << std::endl;
                continue;
            }

            std::cout << "Converted: " << inputFilePath << " to " << outputFilePath << std::endl;
        }
    }

    std::cout << "Conversion completed." << std::endl;
    return 0;
}
