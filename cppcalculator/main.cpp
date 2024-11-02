//
//  main.cpp
//  cppcalculator
//
//  Created by Godswill Adigwe on 01/11/2024.
//

#include <iostream>
#include <cstring>



int evaluate(int x, int y, char op){
    switch(op) {
        case '/':
            return x/y;
            break;
            
        case '*':
            return x*y;
            break;
            
        case '+':
            return x + y;
            break;
            
        case '-':
            return x - y;
            break;
            
        default:
            std::cout << "Unsupported operator" << std::endl;
            break;
            
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    
    char operators[] = {'/',};
//        '*','+','-'};
    int operator_size = 1;
    
    std::string temp;
    
    std::cout << "Enter Expression" << std::endl;
    
    std::getline(std::cin, temp);
    
    char* input = new char[temp.length() + 1];
    
    std::strcpy(input, temp.c_str());
    
    for(int i = 0; i < operator_size; i++ ){
        
        char current_operator = operators[i];
        
        for(int j = 0; j < std::strlen(input); j++){
            
            if(input[j] == operators[i]){
                
//                int exp_begin;
//                int exp_end;
                int before_operator = j;
                std::string expfirstpart;
                std::string expsecondpart;
                int startindex = j;
                int endindex = j;
//                std::cout << before_operator << std::endl;
                int after_operator = j+1;
//                int after_operator = std::strlen(input) - after;
                
                for(int k = before_operator - 1; k >= 0; k--){
                    
                    
                    if (input[k] == '/' || input[k] == '*' || input[k] == '+' || input[k] == '-'){
                        
                        std::cout << "end here" << std::endl;
                        break;
                        
                    }else{
                        expfirstpart.append(std::string(1, input[k]));
                        startindex--;
                    }
                    
                   
                }
                
                std::cout << expfirstpart << std::endl;
                
                std::reverse(expfirstpart.begin(), expfirstpart.end());
                
                std::cout << expfirstpart << std::endl;
                
                
                for(int l = after_operator; l < std::strlen(input); l++){
                    
                    
                    if (input[l] == '/' || input[l] == '*' || input[l] == '+' || input[l] == '-'){
                        
                        std::cout << "end here" << std::endl;
                        break;
                        
                    }else{
                        expsecondpart.append(std::string(1, input[l]));
                        endindex++;
                    }
                    
                   
                }
                
                std::cout << expsecondpart << std::endl;
                std::cout << startindex << std::endl;
                std::cout << endindex << std::endl;
                
               int result = evaluate(std::stoi(expfirstpart), std::stoi(expsecondpart), current_operator);
                
                std::cout << temp << std::endl;
                temp.replace(startindex, endindex-startindex+1, std::to_string(result));
                
                std::cout << result << std::endl;
                std::cout << temp << std::endl;
               
            }
            
            
        }
        
        std::cout << current_operator << std::endl;
        
    }
    
    delete[] input;
    
    
    return 0;
}
