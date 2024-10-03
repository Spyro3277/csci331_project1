/**
 * @file Buffer.h
 * @brief Header file for the Buffer class.
 * @author Team 5
 * @date September 28, 2024
 * @version 1.0
 */

/**
 * @class Buffer
 * @brief A class for managing a text file buffer.
 * @details Buffer Class: A simple read-only buffer that
 * handles the opening and closing of the file that is passed in.
 * Features: Error checking on invalid file.
 * Assumptions: This class assumes that the first line in a
 * file will be a header specifying the fields for the following data.
 */

#ifndef ZIPCODE_BUFFER_H
#define ZIPCODE_BUFFER_H

#include <string>
#include <fstream>

class Buffer {
public:
    /**
    * @brief Default constructor.
    *
    * @param[in] file The file to open with inputStream.
    *
    * @pre file is a valid file.
    * @post file has been opened and the first line has been read from it.
    */
    Buffer(const std::string &file);

    /**
    * @brief Destructor.
    *
    * @pre inputStream is a initialized fstream.
    * @post File opened by inputStream is closed.
    */
    ~Buffer();

    /**
    * @brief Reads the next line from the input file.
    *
    * @param[out] line - The string to store the line retrieved from file.
    * @return true if successful, false if the end of file is reached or an error occurs.
    *
    * @pre None.
    * @post Returns the next line from the input file.
    */
    bool readLine(std::string &line);

private:
    std::ifstream inputStream;    /**< input stream for file we want to read from */

    /**
    * @brief Opens a file for reading.
    *
    * @param[in] file - The name of the file to open.
    * @return true if the file is opened successfully, false otherwise.
    *
    * @pre file is a valid file.
    * @post file has been opened with inputStream.
    */
    bool openFile(std::string file);


    /**
    * @brief Closes the currently open file.
    *
    * @return true if the file is closed successfully, false otherwise.
    *
    * @pre None.
    * @post Opened file has been closed.
    */
    bool closeFile();
};

#endif //ZIPCODE_BUFFER_H
