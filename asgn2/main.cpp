#include "stack_a.h"
#include "stack_b.h"
#include "stack_c.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool isEqual(string stack_f, List* arr1, int size) {
    ifstream stk_file (stack_f);
    string line;
    Node* head = arr1->get_head(); // sentinel head
    head = head->next;
    // Need to compare size first.
    if(stk_file.is_open()) {
        int idx = 0;
        while(getline(stk_file, line)) {
            idx++;
            int stk_elem = stoi(line);
            if(stk_elem != head->get_value()) {
                return false;
            }
            head = head->next;
        }
        if(idx != size) {
            return false;
        }
    }  
    else {
        cout << "Unable to open file\n";
        return false;
    }
    return true; 
}

bool isEqual(string stack_f, int* arr1, int size) {
    ifstream stk_file (stack_f);
    string line;
    // Need to compare size first.
    if(stk_file.is_open()) {
        int idx = 0;
        while(getline(stk_file, line)) {
            idx++;
            int stk_elem = stoi(line);
            if(stk_elem != *arr1++) {
                return false;
            }
        }
        if(idx != size) {
            return false;
        }
    }
    else {
        cout << "Unable to open file\n";
        return false;
    }
    return true; 
}

bool run_testcase(string inp_dir, string file_name, string part, Stack_A* &stk_A, Stack_B* &stk_B, Stack_C* &stk_C) {
    string line;
    string output;
    ifstream myfile (inp_dir + file_name);
    ifstream outfile (inp_dir + "out.txt");
    if(part == "A") {
        stk_A = new Stack_A();
    }
    else if (part == "B"){
        stk_B = new Stack_B();
    }
    else {
        stk_C = new Stack_C();
    }
    if (myfile.is_open() && outfile.is_open()) {
        getline(myfile, line);
        int N = stoi(line);
        for(int i = 0; i < N; i++) {
            getline(myfile, line);
            stringstream ss(line);
            string elem;
            getline(ss, elem, ' ');
            // cout << elem << " " << i+1 << endl;
            string inst = elem;
            try {
                if (elem == "push") {
                    int data;
                    getline(ss, elem, ' ');
                    data = stoi(elem);
                    if(part == "A") {
                        stk_A->push(data);
                    }
                    else if(part == "B") {
                        stk_B->push(data);
                    }
                    else {
                        stk_C->push(data);
                    }
                }
                else if (elem == "pop") {
                    int val;
                    if(part == "A") {
                        val = stk_A->pop();
                    }
                    else if(part == "B") {
                        val = stk_B->pop();
                    }
                    else {
                        val = stk_C->pop();
                    }
                    getline(outfile, output);
                    if(val != stoi(output)) {
                        cout << "Testcase failed pop instruction " << (i+1) << endl;
                        return 0;
                    }
                }
                else if (elem == "get_element_from_top") {
                    int idx;
                    getline(ss, elem, ' ');
                    idx = stoi(elem);
                    int val;
                    if(part == "A") {
                        val = stk_A->get_element_from_top(idx);
                    }
                    else if(part == "B") {
                        val = stk_B->get_element_from_top(idx);
                    }
                    else {
                        val = stk_C->get_element_from_top(idx);
                    }
                    getline(outfile, output);
                    if(val != stoi(output)) {
                        cout << "Testcase failed get_element_from_top instruction " << (i+1) << endl;
                        return 0;
                    }
                }
                else if (elem == "get_element_from_bottom") {
                    int idx;
                    getline(ss, elem, ' ');
                    idx = stoi(elem);
                    int val;
                    if(part == "A") {
                        val = stk_A->get_element_from_bottom(idx);
                    }
                    else if(part == "B") {
                        val = stk_B->get_element_from_bottom(idx);
                    }
                    else {
                        val = stk_C->get_element_from_bottom(idx);
                    }
                    getline(outfile, output);
                    if(val != stoi(output)) {
                        cout << "Testcase failed get_element_from_bottom instruction " << (i+1) << endl;
                        return 0;
                    }
                }
                else if (elem == "add") {
                    int val;
                    if(part == "A") {
                        val = stk_A->add();
                    }
                    else if(part == "B") {
                        val = stk_B->add();
                    }
                    else {
                        val = stk_C->add();
                    }
                    getline(outfile, output);
                    if(val != stoi(output)) {
                        cout << "Testcase failed addition instruction " << (i+1) << endl;
                        return 0;
                    }
                }
                else if (elem == "subtract") {
                    int val;
                    if(part == "A") {
                        val = stk_A->subtract();
                    }
                    else if(part == "B") {
                        val = stk_B->subtract();
                    }
                    else {
                        val = stk_C->subtract();
                    }
                    getline(outfile, output);
                    if(val != stoi(output)) {
                        cout << "Testcase failed subtraction instruction " << (i+1) << endl;
                        return 0;
                    }
                }
                else if (elem == "multiply") {
                    int val;
                    if(part == "A") {
                        val = stk_A->multiply();
                    }
                    else if(part == "B") {
                        val = stk_B->multiply();
                    }
                    else {
                        val = stk_C->multiply();
                    }
                    getline(outfile, output);
                    if(val != stoi(output)) {
                        cout << "Testcase failed multiplication instruction " << (i+1) << endl;
                        return 0;
                    }
                }
                else if (elem == "divide") {
                    int val;
                    if(part == "A") {
                        val = stk_A->divide();
                    }
                    else if(part == "B") {
                        val = stk_B->divide();
                    }
                    else {
                        val = stk_C->divide();
                    }
                    getline(outfile, output);
                    if(val != stoi(output)) {
                        cout << "Testcase failed division instruction " << (i+1) << endl;
                        return 0;
                    }
                }
                else if (elem == "get_stack") {
                    int* stk;
                    List* stk1;
                    if(part == "A") {
                        stk = stk_A->get_stack();
                    }
                    else if(part == "B") {
                        stk = stk_B->get_stack();
                    }
                    else {
                        stk1 = stk_C->get_stack();
                    }
                }
                else if (elem == "get_size") {
                    int size;
                    if(part == "A") {
                        size = stk_A->get_size();
                    }
                    else if(part == "B") {
                        size = stk_B->get_size();
                    }
                    else {
                        size = stk_C->get_size();
                    }
                }
                else {
                    cout << "Command not found " << (i+1) << endl;
                }
            }
            catch (std::runtime_error &e) {
                string msg = e.what();
                getline(outfile, output);
                if(msg != output) {
                    cout << "Testcase failed at raising error for " << inst << " instruction " << (i+1) << endl;
                    return 0;
                }
            }
        }
        int* stk;
        List* stk1;
        if(part == "A") {
            stk = stk_A->get_stack();
            if(!isEqual(inp_dir+"final_stack.txt", stk, stk_A->get_size())) {
                cout << "FINAL STACK NOT MATCHED" << endl;
                return 0;
            }
        }
        else if(part == "B") {
            stk = stk_B->get_stack();
            if(!isEqual(inp_dir+"final_stack.txt", stk, stk_B->get_size())) {
                cout << "FINAL STACK NOT MATCHED" << endl;
                return 0;
            }
        }
        else {
            stk1 = stk_C->get_stack();
            if(!isEqual(inp_dir+"final_stack.txt", stk1, stk_C->get_size())) {
                cout << "FINAL STACK NOT MATCHED" << endl;
                return 0;
            }
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file"; 
        return 0;
    }
    return 1;
}

int main() {
    string inp_dir = "debug_A_testcase_1/";
    string file_name = "test.txt";
    Stack_A* stk_A;
    Stack_B* stk_B;
    Stack_C* stk_C;
    // Part A
    if(run_testcase(inp_dir, file_name, "A", stk_A, stk_B, stk_C)) {
        cout << "Part A: Debug testcase 1 passed" << endl;
    } 
    else {
        cout << "Part A: Debug testcase 1 failed" << endl;
    }
    delete stk_A;

    inp_dir = "debug_A_testcase_2/";
    if(run_testcase(inp_dir, file_name, "A", stk_A, stk_B, stk_C)) {
        cout << "Part A: Debug testcase 2 passed" << endl;
    } 
    else {
        cout << "Part A: Debug testcase 2 failed" << endl;
    }
    delete stk_A;

    inp_dir = "debug_A_testcase_3/";
    if(run_testcase(inp_dir, file_name, "A", stk_A, stk_B, stk_C)) {
        cout << "Part A: Debug testcase 3 passed" << endl;
    } 
    else {
        cout << "Part A: Debug testcase 3 failed" << endl;
    }
    delete stk_A;

    // Part B
    inp_dir = "debug_A_testcase_1/";
    if(run_testcase(inp_dir, file_name, "B", stk_A, stk_B, stk_C)) {
        cout << "Part B: Debug testcase 1 passed" << endl;
    } 
    else {
        cout << "Part B: Debug testcase 1 failed" << endl;
    }
    delete stk_B;
    
    inp_dir = "debug_A_testcase_2/";
    if(run_testcase(inp_dir, file_name, "B", stk_A, stk_B, stk_C)) {
        cout << "Part B: Debug testcase 2 passed" << endl;
    } 
    else {
        cout << "Part B: Debug testcase 2 failed" << endl;
    }
    delete stk_B;

    inp_dir = "debug_A_testcase_3/";
    if(run_testcase(inp_dir, file_name, "B", stk_A, stk_B, stk_C)) {
        cout << "Part B: Debug testcase 3 passed" << endl;
    } 
    else {
        cout << "Part B: Debug testcase 3 failed" << endl;
    }
    delete stk_B;

    inp_dir = "debug_B_testcase_1/";
    if(run_testcase(inp_dir, file_name, "B", stk_A, stk_B, stk_C)) {
        cout << "Part B: Debug testcase 4 passed" << endl;
    } 
    else {
        cout << "Part B: Debug testcase 4 failed" << endl;
    }
    delete stk_B;

    // Part C
    inp_dir = "debug_A_testcase_1/";
    if(run_testcase(inp_dir, file_name, "C", stk_A, stk_B, stk_C)) {
        cout << "Part C: Debug testcase 1 passed" << endl;
    } 
    else {
        cout << "Part C: Debug testcase 1 failed" << endl;
    }
    delete stk_C;
    
    inp_dir = "debug_A_testcase_2/";
    if(run_testcase(inp_dir, file_name, "C", stk_A, stk_B, stk_C)) {
        cout << "Part C: Debug testcase 2 passed" << endl;
    } 
    else {
        cout << "Part C: Debug testcase 2 failed" << endl;
    }
    delete stk_C;

    inp_dir = "debug_A_testcase_3/";
    if(run_testcase(inp_dir, file_name, "C", stk_A, stk_B, stk_C)) {
        cout << "Part C: Debug testcase 3 passed" << endl;
    } 
    else {
        cout << "Part C: Debug testcase 3 failed" << endl;
    }
    delete stk_C;

    inp_dir = "debug_B_testcase_1/";
    if(run_testcase(inp_dir, file_name, "C", stk_A, stk_B, stk_C)) {
        cout << "Part C: Debug testcase 4 passed" << endl;
    } 
    else {
        cout << "Part B: Debug testcase 4 failed" << endl;
    }
    delete stk_C;

    inp_dir = "debug_C_testcase_1/";
    if(run_testcase(inp_dir, file_name, "C", stk_A, stk_B, stk_C)) {
        cout << "Part C: Debug testcase 5 passed" << endl;
    } 
    else {
        cout << "Part C: Debug testcase 5 failed" << endl;
    }
    delete stk_C;
    return 0;
}