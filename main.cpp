#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <map>

#define True 1
#define False 0

using namespace std;

class CALC {
private:
    stack<double> double_stack;
    stack<int> int_stack;
    string num;
    int parent_num;
    void readParent(string equation);
public:
    void calc(string equation);
};

void CALC::readParent(string equation, int left_parent, int right_parent){
    int parent_num = 0;
    left_parent = equation.find_first_of('(');
    if (left_parent == string::npos) {
        calc_equation()
    }else{
        right_parent = left_parent;
        do{
            right_parent++;
            if(equation.at(right_parent) == '('){
                parent_num++;
            }else if(equation.at(right_parent) == ')'){
                parent_num--;
            }else{
            
            }
        }while();
    }
}

class AST {
private:
    string script;
    vector<string> words;
    stack<char> control_stack;
    int tab_count;
    int exit_flag;
    
    void hello();
    void if_function();
    void elif_function();
    void else_function();
    void while_function();
    void comment_function();
    void wide_comment_function();
    
public:
    AST() {
        cout << "hello User" << endl;
        tabCount(0);
        exitFlag(True);
    }
    void init();
    int exitFlag();
    void exitFlag(int flag);
    int tabCount();
    void tabCount(int count);
    int tabCheck(int current_count);
    static void printWords(const string word);
    void readLine();
    void separator();
    void commandDetect();
    void controler();
    void printScript();
    void script_loop();
};

void AST::hello(){
    cout << "暁の水平線に勝利を刻みなさい!" << endl;
}

void AST::if_function(){
    control_stack.push("if");
}

int AST::exitFlag(){
    return this->exit_flag;
}

void AST::exitFlag(int flag){
    this->exit_flag = flag;
}

int AST::tabCount(){
    return this->tab_count;
}

void AST::tabCount(int count){
    this->tab_count = count;
}

int AST::tabCheck(int current_count){
    if(current_count == tabCount()){
        /*
         同ブロック内
         */
        return 0;
    }else if(current_count == (tabCount()-1)){
        /*
         1つ浅いブロック
         */
        return 1;
    }else{
        /*
         タブおかしい(error)
         */
        return -1;
    }
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
    int tab = 0;
    int i = 0;
    words.clear();
    tabCount(0);
    /*
     tab detect
     */
    while (tab != string::npos) {
        tab = script.find_first_of('\t');
        tabCount(tabCount()++);
        script = script.substr(tab+1);
    }
    
    separator = script.find_first_of(' ');
    words.push_back("");
    words[0].append(script, 0, separator);
    script = script.substr(separator+1);
    words.push_back("");
    words[1].append(script);
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

void AST::if_function(){
    
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
