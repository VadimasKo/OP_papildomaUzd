#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

const string endSymbols = ".,!?:;#$%(){}/<>'"; // does not contain ""
const string numbers = "0123456789";
const string separationSymbols = "/+-–"; // does not contain .


struct wordInfo{
    int count = 1;
    vector<int> posIndicators;  // indicates where word was found
};

void removeFrontSymbols(string &word){
    for(auto symbol : endSymbols){
        if(word.front() == symbol){
            word = word.substr(1,word.size());
            break; 
        }
        if(word.back() == '"') word = word.substr(1,word.size() );
    }
}


void removeEndSymbols(string &word){    //Removes symbols found at the end
    if(word.size() > 3 && word.substr( word.size()-2,word.size() )== "..") word.resize(word.size()-2); //check for ...

    for(auto symbol : endSymbols){
        if(word.back() == symbol){
            word.pop_back();
            break; 
        }
        if(word.back() == '"') word.pop_back();
    }
}

bool isNumber(const string &word){
    for(auto number : numbers){
        if(word.find(number) != string::npos) return true;
    }
    return false;
}

vector<string> separateWords(string connectedWords){
    vector<string> words;
    for(auto separator : separationSymbols){
        auto pos = connectedWords.find(separator);
        if( pos != string::npos){
            words.push_back(connectedWords.substr(0,pos));
            words.push_back(connectedWords.substr(pos+1,connectedWords.size())); //causing error ? 
            break;
        }
    }
    return words;
}

bool containsDot(const string &word){ //all words containing dot are considered links, flaw -> t.t and other abreviations
    for(auto letter : word){
        if(letter == '.') return true;
    }
    return false;
}

bool containsSeparator(const string &word){
    for(auto separator : separationSymbols){
        if(word.find(separator) != string::npos) return true;
    }
    return false;
}

bool isLink(const string &word){
    if(containsDot(word)) return true;
    else if( word.size() > 4 && word.substr(0,4) == "www.") return true;
    else if( word.size() > 8 && word.substr(0,8) == "https://") return true;
    else return false;
}

// void break




int main(){
    string filename = "input.txt";
    int lineIndicator = 1;
    map<string, wordInfo> words;
    vector<string> links;
    

    //geting data from file
    fstream file;
    file.open(filename);
    
    stringstream fileStream;
    fileStream << file.rdbuf();
    
    file.close();
    //geting words from data

    while(!fileStream.eof()){
        string buffer; //temporary string storage
        getline(fileStream, buffer);
        stringstream lineStream(buffer);
        while(!lineStream.eof()){
            lineStream>>buffer;
            removeEndSymbols(buffer);
            removeFrontSymbols(buffer);
            auto it = words.find(buffer);
            if(isLink(buffer)) links.push_back(buffer);
            else if(isNumber(buffer));
            else if(containsSeparator(buffer)){
                vector<string> separatedWords = separateWords(buffer);
                for(auto word : separatedWords ){
                    lineStream<<word;
                }
            }
            else if(it==words.end() || words.size()==0){ //add word
                wordInfo newInfo;
                newInfo.posIndicators.push_back(lineIndicator);
                words.insert(make_pair(buffer,newInfo));
            }
            else{ //update word info
                it->second.count++;
                it->second.posIndicators.push_back(lineIndicator);
            } 

            // else ()
        }
        lineIndicator++;
    }

    for(auto word : words){
        if(word.second.count <1 ) continue;
        
        cout<<setw(15)<<word.first<<" || count="<<setw(4)<<word.second.count<<" || locations: ";
        for(auto location : word.second.posIndicators){
            cout<<location<<" ";
        }
        cout<<endl;
    }
    
    cout<<"==========Links==========\n";
    for(auto link : links){
        cout<<link<<endl;
    }
}