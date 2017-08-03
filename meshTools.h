#include <fstream>
#include <vector>

struct Vertex{
    float x,y,z;
};

class FileReader;

class PointCloud{
private:
    std::vector<Vertex> * points;
    FileReader * inFile;
    void loadFromFile();
public:
    PointCloud();
    PointCloud(std::string); //filepath name
    PointCloud(FileReader &inFile); //initialize from opened file
    ~PointCloud();

    void AddPoint(Vertex);
    Vertex GetPoint(int);
};

class FileReader{
private:
    std::ifstream * infile;
    std::string fileName;

public:
    FileReader(std::string &);
    ~FileReader();
    std::string readLine();
    std::vector<std::string> splitSpaces(std::string);
    std::vector<std::string> parseLine(); //read the line then parse and return the string vector
};

