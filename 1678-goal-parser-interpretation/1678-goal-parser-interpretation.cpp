class Solution {
public:
    string interpret(string command) {
        string str = "";
        int i=0 , j;
        while(i<command.size()){
            if(command[i] == 'G'){
                str += command[i];
                i++;
            }
            if(command[i] == '('){
                string temp = "(";
                j = i+1;
                while(command[j] != ')')
                    temp += command[j++];
                temp += ')';
                if(temp == "()")
                    str += "o";
                if(temp == "(al)")
                    str += "al";
                
                i = j+1;
            }
        }
        return str;
    }
};