#include <iostream>
#include <string>
using namespace std;

// Question 1
void numericCheck(){
    cout << "Enter an input to check if it is numeric: ";
    string s;
    cin >> ws;
    getline(cin, s);

    bool flag = true;
    int dotCount = 0;
    int digitCount = 0;

    for (int i=0; i<s.length(); i++){
        if ((int)s[i] == 46){
            dotCount++;
            if (dotCount > 1){
                flag = false;
                break;
            }
        }
        else if ((int)s[i] >= 48 && (int)s[i] <= 57){
            digitCount++;
        }
        else{
            flag = false;
            break;
        }
    }
    if (flag && digitCount > 0){
        cout << "Numeric constant." << endl;
    }
    else{
        cout << "Not numeric" << endl;
    }
}

// Question 2
string getOperatorName(char ch) {
    switch (ch) {
        case '+': return "Addition";
        case '-': return "Subtraction";
        case '*': return "Multiplication";
        case '/': return "Division";
        case '%': return "Modulus";
        case '=': return "Assignment";
        default:  return "Unknown Operator";
    }
}
void operatorCheck(){
    cout << "Enter a mathematical expression to find the operators and their names: ";
    string s, p;
    cin >> ws;
    getline(cin, s);
    string op = "+-*/%=";
    for (int i=0; i<s.length(); i++){
        for (int j=0; j<op.length(); j++){
            if (s[i] == op[j]){
                p += s[i];
                break;
            }
        }
    }
    if (p.empty()){
        cout << "No operators found." << endl;
        return;
    }
    for (int i=0; i<p.length(); i++){
        cout << "Operator " << (i+1) << ": " << p[i] << " (" << getOperatorName(p[i]) << ")" << endl;
    }
}

//Question 3
void commentCheck(){
    cout << "Enter code or comment: ";
    string inputLine, totalInput;
    cin >> ws;
    while (getline(cin, inputLine) && !inputLine.empty()) {
        totalInput += inputLine + "\n";
    }
    bool foundComment = false;
    for (int i=0; i<totalInput.length(); i++){
        if (totalInput[i] == '/'){
            if (i + 1 < totalInput.length() && totalInput[i+1] == '/'){
                cout << "Single line comment." << endl;
                foundComment = true;
                while (i < totalInput.length() && totalInput[i] != '\n'){
                    i++;
                }
            }
            else if (i + 1 < totalInput.length() && totalInput[i+1] == '*'){
                bool closed = false;
                for (int j=i+2; j<totalInput.length(); j++){
                    if (j + 1 < totalInput.length() && totalInput[j] == '*' && totalInput[j+1] == '/'){
                        cout << "Multiple Line Comment." << endl;
                        foundComment = true;
                        closed = true;
                        i = j + 1;
                        break;
                    }
                }
                if (!closed){
                    cout << "Unterminated multiple line comment." << endl;
                    foundComment = true;
                    break;
                }
            }
        }
    }
    if (!foundComment){
        cout << "No comment found." << endl;
    }
}

// Question 4
void identifierCheck(){
    cout << "Give an input to check if it is an identifier: ";
    string s;
    cin >> ws;
    getline(cin, s);
    if (s.empty()) {
        cout << "The given input is not a valid identifier." << endl;
        return;
    }
    bool flag = false;
    if (((int)s[0] >= 65 && (int)s[0] <= 90) || ((int)s[0] >= 97 && (int)s[0] <= 122) || (int)s[0] == 95) {
        flag = true;
        for (int i=1; i<s.length(); i++){
            if (((int)s[i] >= 65 && (int)s[i] <= 90) || ((int)s[i] >= 97 && (int)s[i] <= 122) || (int)s[i] == 95 || ((int)s[i] >= 48 && (int)s[i] <= 57)) {
                flag = true;
            }
            else {
                flag = false;
                break;
            }
        }
    }
    else {
        flag = false;
    }
    if (flag) {
        cout << "The given input is a valid identifier." << endl;
    }
    else {
        cout << "The given input is not a valid identifier." << endl;
    }
}

//Question 5
void averageCalculation(){
    cout << "Enter array size: ";
    int n;
    float total = 0;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return;
    }
    cout << "Enter elements of an array: " << endl;
    float arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    cout << "The average of the elements of the array = " << total/n << endl;
}

// Question 6
void min_max() {
    cout << "Enter array size: ";
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return;
    }
    cout << "Enter elements of an array: " << endl;
    float arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    float minimum=arr[0], maximum=arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i]<minimum) {
            minimum = arr[i];
        }
        if (arr[i]>maximum) {
            maximum = arr[i];
        }
    }
    cout << "The maximum number of the array: " << maximum << endl;
    cout << "The minimum number of the array: " << minimum << endl;
}

// Question 7
void fullNamePrint(){
    string firstName, lastName, fullName;
    cout << "Enter your first name: ";
    cin >> ws;
    getline(cin, firstName);
    cout << "Enter your last name: ";
    getline(cin, lastName);
    fullName = firstName + " " + lastName;
    cout << "Your full name is: " << fullName << endl;
}
int main()
{
    numericCheck();
    operatorCheck();
    commentCheck();
    identifierCheck();
    averageCalculation();
    min_max();
    fullNamePrint();
    return 0;
}
