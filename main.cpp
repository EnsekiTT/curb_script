#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <map>

#define True 1
#define False 0

using namespace std;

/*
 Todo:
    class::function()の形に直す
 */

class AST {
private:
    string script;
    vector<string> words;
    int exit_flag;
    
    static void hello(){
        cout << "暁の水平線に勝利を刻みなさい!" << endl;
    }
    
    static void if_function(){
        
    }
    
    static void elif_function(){
        
    }
    
    static void else_function(){
        
    }
    
    static void while_function(){
        
    }
    
    static void comment_function(){
        
    }
    
    static void wide_comment_function(){
        
    }
    
public:
    AST() {
        cout << "hello User" << endl;
        exitFlag(True);
    }
    
    int exitFlag(){
        return this->exit_flag;
    }
    
    void exitFlag(int flag){
        this->exit_flag = flag;
    }
    
    static void printWords(const string word){
        cout << word << endl;
    }
    
    void readLine(){
        printf("curb > ");
        getline(cin, script);
    }
    
    void separator(){
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
    
    
    void commandDetect(){
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
        
        /*
        typedef map<string, void(*)()> command_function_dictionary;
        command_function_dictionary cf_dict;
        
        cf_dict.insert(make_pair("exit", exit));
        cf_dict.insert(make_pair("hello", hello));
        cf_dict.insert(make_pair("if", if_function));
        cf_dict.insert(make_pair("else", else_function));
        cf_dict.insert(make_pair("while", while_function));
        cf_dict.insert(make_pair("#", comment_function));
        cf_dict.insert(make_pair("###", wide_comment_function));
        
        command_function_dictionary::iterator it = cf_dict.find(words[0]);
        
        if (it != cf_dict.end()) {
            it->second();
        }else{
            cout << "command not found" << endl;
        }
         */
    }
    
    void printScript(){
        for_each(words.begin(), words.end(), printWords);
    }
    
    void script_loop(){
        while (this->exitFlag()) {
            readLine();
            separator();
            commandDetect();
        }
    }
};

string script;
int main(){
    int i = 0;
    int exit = 1;
    AST ast;
    ast.script_loop();
	return 0;
}
