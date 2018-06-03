/*
 * Using the alphabetic cypher developed by lewis carroll, this application will encrypt any message per the guidelines of the /r dailyprogrammer
 * challenge that it is based off.
 */
#include <iostream>
#include <string>

using namespace std;

//function initializations
int cypherIndex(char);
string encrypt(string, string);
//global variables
static char cypher[26]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; //array of alphabet characters

int main(int argc, const char * argv[]) {
    string message, keyword;
    cin >> message >> keyword;
    int iterationCount = 0;
    while(keyword.length() != message.length()) {
        keyword += keyword[iterationCount];
        iterationCount++;
    }
    cout << encrypt(message, keyword) << endl;
    return 0;
}

string encrypt(string message, string keyword) {
    int messageIndex, keywordIndex, sumIndex;
    string output;
    for(int i = 0; i < message.length(); i++) {
        messageIndex = cypherIndex(message[i]);
        keywordIndex = cypherIndex(keyword[i]);
        sumIndex = (messageIndex + keywordIndex) % 26;
        output += cypher[sumIndex];
    }
    return output;
}

int cypherIndex(char c) {
    for(int i = 0; i < 26; i++) {
        if(c == cypher[i])
            return i;
    }
    return -999;
}
