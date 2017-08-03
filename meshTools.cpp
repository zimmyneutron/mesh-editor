
#include "meshTools.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

PointCloud::PointCloud(){
    points = new std::vector<Vertex>;
};

PointCloud::PointCloud(std::string filename){
    loadFromFile(new FileReader(filename));

}

PointCloud::PointCloud(FileReader& file){
    loadFromFile(file);
}

PointCloud::loadFromFile(FileReader& file){
    std::cout<<file->readLine();
}

PointCloud::~PointCloud(){
    delete points;
}

void PointCloud::AddPoint(Vertex newPoint){
    points->push_back(newPoint);
}

Vertex PointCloud::GetPoint(int pointNumber){
    return points->at(pointNumber);
}



FileReader::FileReader(std::string & filepath){
    this->fileName=filepath;
    try{
        this->infile = new std::ifstream (filepath.c_str(), std::ifstream::in);
        if(!infile->is_open()){
            throw std::exception();
        }
        std::cout << "file opened" << std::endl;
    }
    catch(std::exception){
        std::cout << "Could not read file: \"" << fileName << "\"" << std::endl;
    }
}

FileReader::~FileReader(){

}

std::string FileReader::readLine(){
    std::string foo;
    getline(*infile,foo);
    return foo;
}

std::vector<std::string> FileReader::splitSpaces(std::string line){
    std::vector<std::string> stringList; //a list of all the words separated by spaces within a line

    int start = 0;
    for(unsigned int i =0; i<line.length(); i++){
        if (line[i]==' '){  //if a space is encountered
            stringList.push_back(line.substr(start,i-start));
            start=++i;
        }
    }
    stringList.push_back(line.substr(start));
    return stringList;
}

std::vector<std::string> FileReader::parseLine(){
    return this->splitSpaces(this->readLine());

}
