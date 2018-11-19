#include "presenter.hpp"

void presenter::config(std::string configLine){
    int index = Tools::findCharIndex(configLine, '@');
    std::string sortingSring = configLine.substr(0, index);
    std::string prcCntSring = configLine.substr(index+1);
    fillMap(sortingSring);
    this -> prcCnt = stoi(prcCntSring);
}

void presenter::fillMap(std::string sortingString){
    std::vector<std::string> sort = Tools::splitBySpace(sortingString);
    for (int i =0; i < sort.size(); i += 2)
        sorting[sort[i]] = sort[i+1];
}

void presenter::getDataFromWorkers(){
    std::ifstream fd;
    fd.open(WORKERSNAMEDPIPE, std::fstream::in);
    std::string workerRes;
    for (int i = 0; i < prcCnt; i++){
        getline(fd,workerRes);
        std::vector<std::string> res = splitData(workerRes);
        std::vector<std::vector<std::string> > resTable;
        for (int i =0; i < res.size(); i++){
            std::vector<std::string> splitted = Tools::splitBySpace(res[i]);
            resTable.push_back(splitted);
        }
        std::map <std::string,std::string> ::iterator it = sorting.begin();
        sortResult(resTable,it->first,it->second);
    }
    fd.close();
}

std::vector<std::string> presenter::splitData(std::string data){
    std::vector<std::string> result;
    std::string token;
    for(int i=0; i<data.length(); i++){
        if(data[i] != '@')
            token += data[i];
        else{
            if(token.length()) {
                result.push_back(token);
                token = "";
            }
        }
    }
    return result;
}

void presenter::sortResult(std::vector<std::vector<std::string> > &res, std::string sortBy,
    std::string type){
    int header;
    for (int i =0; i < res[0].size(); i++){
        if (res[0][i] == sortBy){
            header = i;
            break;
        }
    }
    if (!Tools::isNumber(res[1][header])){
        for (int i = 1; i < res.size(); i++){
            for (int j = 1; j < res.size()-1; j++){
                if(((res[j][header] > res[j+1][header]) && type == ASCEND)||
                    ((res[j][header] < res[j+1][header]) && type == DECSEND)){
                    std::vector<std::string> temp = res[i];
                    res[i] = res[j];
                    res[j] = temp;
                }
            }
        }
    }
    else{
        for (int i = 1; i < res.size(); i++){
            for (int j = 1; j < res.size()-1; j++){
                if(((stoi(res[j][header]) > stoi(res[j+1][header])) && type == ASCEND)||
                    ((stoi(res[j][header]) < stoi(res[j+1][header])) && type == DECSEND)){
                    std::vector<std::string> temp = res[i];
                    res[i] = res[j];
                    res[j] = temp;
                }
            }
        }
    }
}