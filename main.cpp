#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <map>

#define True 1
#define False 0

using namespace std;

class AST {
private:
    string script;
    vector<string> words;
    int exit_flag;
    
    void hello();
    void if_function();
    void elif_function();
    void else_function();
    void while_function();
    void comment_function();
    void wide_comment_function();
	void coding_style();
	void status();
    
public:
    AST() {
        cout << "hello User" << endl;
        exitFlag(True);
    }
    void init();
    int exitFlag();
    void exitFlag(int flag);
    static void printWords(const string word);
    void readLine();
    void separator();
    void commandDetect();
    void printScript();
    void script_loop();
};

void AST::hello(){
    cout << "暁の水平線に勝利を刻みなさい!" << endl;
}

int AST::exitFlag(){
    return this->exit_flag;
}

void AST::exitFlag(int flag){
    this->exit_flag = flag;
}

static void AST::printWords(const string word){
    cout << word << endl;
}

void AST::readLine(){
    printf("curb > ");
    getline(cin, script);
}

void AST::separator(){
    int separator = 0;
    int i = 0;
    words.clear();
    while (separator != string::npos) {
        separator = script.find_first_of(' ');
        if (separator == string::npos) {
            break;
        }
        words.push_back("");
        words[i].append(script, 0, separator);
        script = script.substr(separator+1);
        i++;
    }
    words.push_back("");
    words[i].append(script);
}


void AST::commandDetect(){
    if (words[0] == "exit") {
        this->exitFlag(False);
    }else if(words[0] == "hello"){
        this->hello();
    }else if(words[0] == "if"){
        this->if_function();
    }else if(words[0] == "elif"){
        this->elif_function();
    }else if(words[0] == "else"){
        this->else_function();
    }else if(words[0] == "while"){
        this->while_function();
    }
}

void AST::printScript(){
    for_each(words.begin(), words.end(), printWords);
}

void AST::script_loop(){
    while (this->exitFlag()) {
        readLine();
        separator();
        commandDetect();
    }
}

int main(){
    AST ast;
    ast.script_loop();
    return 0;
}
