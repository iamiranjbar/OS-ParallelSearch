#include "loadBalancer.hpp"

void loadBalancer::getInput(){
    getline(std::cin, commandLine);
}

bool loadBalancer::parseInput(){
    if (commandLine == "quit")
        return 0;
    const char chars[]= { '-' , '=' };
    commandParts = Tools::split(commandLine, chars);
    this->setFields();
    return 1;
}

void loadBalancer::setFields(){
    int lastElement = commandParts.size() - 1;
    for (int i = 0; i < lastElement-3; i = i+2){
        if (commandParts[i+1] == ASCEND || commandParts[i+1] == DECSEND){
            // sorting[commandParts[i]] = commandParts[i+1];
            sortingString += commandParts[i];
            sortingString += " ";
            sortingString += commandParts[i+1];
            sortingString += " ";
        }
        else{
            // filters[commandParts[i]] = commandParts[i+1];
            filterString += commandParts[i];
            filterString += " ";
            filterString += commandParts[i+1];
            filterString += " ";
        }
    }
    prcCnt = stoi(commandParts[lastElement-2]);
    dirPath = "./" + commandParts[lastElement];
}

void loadBalancer::getFiles(){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (dirPath.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (strcmp(ent->d_name,".") && strcmp(ent->d_name,"..")){
                dirFiles.push_back(ent->d_name);
            }
        }
        closedir (dir);
    } else { /* could not open directory */
        perror ("open directory failed!");
        exit(1);
    }
}

void loadBalancer::devideFilesAndCreateWorkers(){
    const int workerNum = this -> prcCnt;
    int fileCount = dirFiles.size();
    int eachWorkerFiles = fileCount / workerNum;
    int remain = fileCount - (eachWorkerFiles*workerNum);
    for (int i = 0; i < this->prcCnt; i++)
        this-> workerNumFiles.push_back(eachWorkerFiles);
    for (int i = 0; i < remain; i++)
        this-> workerNumFiles[i]++;
    int p[workerNum][2];
    int k = 0;
    for (int i = 0; i < workerNum; i++){
        if (pipe(p[i])== -1){
            perror("pipe() failed!");
            exit(1);
        }
        int pid = fork();
        if (pid == 0){
            close(p[i][1]);
            char msg[1000]; 
            read(p[i][0], msg, 1000); 
            close(p[i][0]);
            char* argv[3] = {WORKER,msg,NULL};
            std::cout << execv("/Users/amir/Desktop/OS-ParallelSearch/worker", argv) << std::endl;
            exit(0);
        }
        else if(pid > 0){
            close(p[i][0]);
            std::string data;
            data = filterString + " @ ";
            for (int j = 0; j < workerNumFiles[i]; j++){
                data = data + dirFiles[k];
                data = data + " ";
                k++;
            }
            write(p[i][1], data.c_str() , (data.length())+1);
            close(p[i][1]);
        }
    }
}

void loadBalancer::clear(){
    this-> commandLine = nullptr;
    this-> commandParts.clear();
    this-> filters.clear();
    this-> sorting.clear();
    this-> prcCnt = 0;
    this-> dirPath = nullptr;
    this-> dirFiles.clear();
    this->workerNumFiles.clear();
}