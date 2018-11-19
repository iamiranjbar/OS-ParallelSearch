#include "worker.hpp"

void worker::setFields(std::string data){
    int index = Tools::findCharIndex(data, '@');
    std::string filters = data.substr(0, index);
    std::string files = data.substr(index+2);
    fillMap(filters);
    setFiles(files);
}

void worker::fillMap(std::string filterString){
    std::vector<std::string> filter;
    filter = Tools::splitBySpace(filterString);
    for (int i = 0; i < filter.size(); i = i+2)
        filters[filter[i]] = filter[i+1];
}

void worker::setFiles(std::string fileString){
    files = Tools::splitBySpace(fileString);
}

void worker::processFiles(){
    std::ifstream fs;
    std::string line;
    for (int i = 0; i < files.size(); i++){
        fs.open(files[i],std::fstream::in);
        if (!fs) {
            std::cerr << "Unable to open file!";
            exit(1);  
        }
        getline(fs, line);
        if (searchTable.size()==0){
            std::vector<std::string> header = Tools::splitBySpace(line);
            searchTable.push_back(header);
        }
        while(getline(fs,line)){
            std::vector<std::string> l = Tools::splitBySpace(line);
            searchTable.push_back(l);
        }
        fs.close();
    }
}

void worker::search(){
    int header;
    for(std::map <std::string,std::string> ::iterator it = filters.begin(); it != filters.end(); ++it) {
        for (int i =0; i < searchTable[0].size(); i++){
            if (searchTable[0][i] == it -> first){
                header = i;
                break;
            }
        }
        for(int i =searchTable.size()-1; i > 0; i--){
            if(searchTable[i][header] != it -> second)
                searchTable.erase(searchTable.begin()+i);
        }
    }
}

void worker::makeDataReady(){
    for (int i =0; i< searchTable.size(); i++){
        for (int j =0; j < searchTable[i].size(); j++){
            dataForPresenter += searchTable[i][j] += " ";
        }
        dataForPresenter += " @";
    }
    dataForPresenter += "\n";
}

void worker::sendDataToPresenter(){
    int fd = open(WORKERSNAMEDPIPE, O_WRONLY);
    write(fd,dataForPresenter.c_str(),(dataForPresenter.length())+1);
    close(fd);
}