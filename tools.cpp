#include "tools.hpp"

using namespace std;

vector<string> Tools::split(string statement , const char* delimeters){
    vector<string> result;
    string token;
    for(int i=0; i<statement.length(); i++){
        for (int j = 0; j < sizeof(delimeters); j++){
            if(statement[i] != ' ' && statement[i] != delimeters[j]){
                if (j == sizeof(delimeters)-1){
                    token += statement[i];
                }
            }
            else{
                if(token.length()) {
                    result.push_back(token);
                    token = "";
                }
                break;
            }
        }
    }
    if (token != ""){
        result.push_back(token);
    }
    return result;
}