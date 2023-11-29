#include "FileReader.hpp"

vector<string> FileReader::readFile(string path){
    ifstream input(path);
    vector<string> contents;
    
    if(!input){
        cout << "No file found" << endl;
        return contents;
    }

    string line;
    while(getline(input, line)){
        line = trim(line);
        
        if(!(line.length() > 1)){
            continue;
        }
        contents.push_back(line);
    }

    return contents;
}

string FileReader::trim(string str){
    const int strStart = str.find_first_of('<');
        if(strStart == string::npos){
            return "";
        }

        const int strEnd = str.find_last_of(">");
        const int strRange = strEnd - strStart + 1;

        return str.substr(strStart, strRange);
}