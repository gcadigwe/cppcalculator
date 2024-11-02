//
//  main.cpp
//  cppcalculator
//
//  Created by Godswill Adigwe on 01/11/2024.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <sstream>



int evaluate(int x, int y, char op){
    switch(op) {
        case '/':
            return x / y;
            break;
            
        case '*':
            return x * y;
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

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return ""; // no content

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}


int main(int argc, const char * argv[]) {
    
    while(true) {
        char operators[] = {'/','*'};
        char loweroperators[] = {'+', '-'};
        
        int operator_size = 2;
        int final_result = 0;

        std::string temp;

        std::cout << "Enter Expression: " << std::endl;

        std::getline(std::cin, temp);

        char* input = new char[temp.length() + 1];

        std::strcpy(input, temp.c_str());

        for(int i = 0; i < operator_size; i++ ){

            char current_operator = operators[i];

            int j = 0;

            //        for(int j = 0; j < std::strlen(input); j++){
            while(j < std::strlen(temp.c_str())){

                if(temp.c_str()[j] == operators[i]){
                    
//                    std::cout << "Operator Found " << operators[i] << std::endl;

                    // count the number of times this operator appears
                    auto count = std::count(temp.begin(), temp.end(), temp.c_str()[j]);

//                    std::cout << "Count " << count << std::endl;



//                    for(int c = 1; c < count; c++){
                        int before_operator = j;
                        std::string expfirstpart;
                        std::string expsecondpart;
                        int startindex = j;
                        int endindex = j;
                        int after_operator = j+1;

                        for(int k = before_operator - 1; k >= 0; k--){


                            if (temp.c_str()[k] == '/' || temp.c_str()[k] == '*' || temp.c_str()[k] == '+' || temp.c_str()[k] == '-'){

                                break;

                            }else{
                                expfirstpart.append(std::string(1, temp.c_str()[k]));
                                startindex--;
                            }


                        }


                        std::reverse(expfirstpart.begin(), expfirstpart.end());


                        for(int l = after_operator; l < std::strlen(temp.c_str()); l++){


                            if (temp.c_str()[l] == '/' || temp.c_str()[l] == '*' || temp.c_str()[l] == '+' || temp.c_str()[l] == '-'){

                                break;

                            }else{
                                expsecondpart.append(std::string(1, temp.c_str()[l]));
                                endindex++;
                            }


                        }


                        int result = evaluate(std::stoi(expfirstpart), std::stoi(expsecondpart), current_operator);

                        temp.replace(startindex, endindex-startindex+1, std::to_string(result));
                        j = 0;

//                        std::cout << "Input now " << temp << std::endl;
//                        std::cout << "Result " << result << std::endl;

                        final_result = result;
                    }

//                }

                j++;
            }

        }
        
        int i = 0;
        
        while(i < std::strlen(temp.c_str())) {
            
            if(std::find(std::begin(loweroperators), std::end(loweroperators), temp.c_str()[i]) != std::end(loweroperators)){
                
//                std::cout << "Operator Found " << temp.c_str()[i] << std::endl;
                
                // count the number of times this operator appears
                auto count = std::count(temp.begin(), temp.end(), temp.c_str()[i]);
                
//                std::cout << "Count " << count << std::endl;
                
                int before_operator = i;
                std::string expfirstpart;
                std::string expsecondpart;
                int startindex = i;
                int endindex = i;
                int after_operator = i+1;
                
                for(int k = before_operator - 1; k >= 0; k--){
                    
                    
                    if (temp.c_str()[k] == '/' || temp.c_str()[k] == '*' || temp.c_str()[k] == '+' || temp.c_str()[k] == '-'){
                        
                        break;
                        
                    }else{
                        expfirstpart.append(std::string(1, temp.c_str()[k]));
                        startindex--;
                    }
                    
                    
                }
                
                
                std::reverse(expfirstpart.begin(), expfirstpart.end());
                
                
                for(int l = after_operator; l < std::strlen(temp.c_str()); l++){
                    
                    
                    if (temp.c_str()[l] == '/' || temp.c_str()[l] == '*' || temp.c_str()[l] == '+' || temp.c_str()[l] == '-'){
                        
                        break;
                        
                    }else{
                        expsecondpart.append(std::string(1, temp.c_str()[l]));
                        endindex++;
                    }
                    
                    
                }
                
                
                int result = evaluate(std::stoi(expfirstpart), std::stoi(expsecondpart), temp.c_str()[i]);
                
                temp.replace(startindex, endindex-startindex+1, std::to_string(result));
                i = 0;
                
//                std::cout << "Input now " << temp << std::endl;
//                std::cout << "Result 2" << result << std::endl;
                
                final_result = result;
                
                
            }
            i++;
        }
        
        std::cout << "Result: " << final_result << std::endl;

        delete[] input;
    };

        return 0;
}
