//ubuntu
//g++ -Wextra -o main.out main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>
//#include <cstring>
#include <bits/stdc++.h>

using namespace std;

//todo fix it

std::wstring stringToWstring(const std::string& narrowStr) {
    // Create a converter from UTF-8 encoded string (char) to wide characters (wchar_t)
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(narrowStr);  // Convert from UTF-8 to wide string
}

std::string wstringToString(const std::wstring& wideStr) {
    // Create a converter from wide characters (wchar_t) to UTF-8 encoded string (char)
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wideStr);  // Convert to UTF-8
}

std::string decodeUnicodeEscapeSequence_old(const std::string& input) {
    if (input.size() < 6 || input.substr(0, 2) != "\\u") {
        return input;  // Not a valid Unicode escape sequence.
    }

    std::string hex1 = input.substr(2, 4);  // Extract the hexadecimal part after "\u".
    unsigned int codePoint;
    std::stringstream(hex1) >> std::hex >> codePoint;  // Convert hex string to integer.

    // Return the corresponding character as a string
    std::string result(1, static_cast<char>(codePoint));
    cout << (int) result.at(0) << "THIS IS TEH RESULTSSSSSSSSSSSTOTOTOTOTOTOTOT" << endl;
    return result;
}

std::wstring decodeUnicodeEscapeSequence(const std::string& input) {
    // Ensure the string is in the format "\uXXXX" (where X is a hexadecimal digit)
    if (input.size() < 6 || input.substr(0, 2) != "\\u") {
        throw std::invalid_argument("Invalid Unicode escape sequence");
    }

    // Extract the hexadecimal part (after "\u")
    std::string hex = input.substr(2, 4);
    
    unsigned int codePoint;
    std::stringstream(hex) >> std::hex >> codePoint; // Convert the hex string to an integer

    cout << codePoint << "THIS IS TEH RESULTSSSSSSSSSSSTOTOTOTOTOTOTOT" << endl;

    // Convert the code point to a wide character and return it as a wstring (to handle larger characters)
    return std::wstring(1, static_cast<wchar_t>(codePoint));  // Convert to wchar_t to store larger code points
}

map<string,wstring> initDictFromFile(string fname)
{
    map<string,wstring> dict;
    fstream thing;
    thing.open(fname,ios::in);
    string key;
    string value;
    string isEscape_s;
    int isEscape;
    while (thing >> key >> value >> (isEscape_s))
    {
        cout << "isEscape is = " << isEscape_s << endl;
        isEscape = stoi(isEscape_s);
        cout << "loading " << key << "as key for value " << value << endl;
        wstring newVal;
        if (isEscape) 
        {
            newVal = decodeUnicodeEscapeSequence(value);
            //cout << "CONVERTED TO " << newVal << "         TEHOUNHOENTHUNTOEHUTNHOTEUHNTOHENTUHNOHETUOEU";
            dict[key] = newVal;
        }
        else
        {
            dict[key] = stringToWstring(value);
        }
    }

    return dict;

}

map<string,string> initDict()
{
    map<string,string> dict;
    dict["high"] =      "C";
    dict["low"] =       "A";
    dict["above"] =     "E";
    dict["below"] =     "F";
    dict["max"] =       "G";
    dict["min"] =       "H";
    dict["increase"] =  "I";
    dict["decrease"] =  "J";
    dict["very"] =      "K";
    dict["yes"] =       "L";
    dict["no"] =        "M";
    dict["good"] =      "N";
    dict["bad"] =       "O";
    dict["a"] =         "Q";
    dict["."] =         ".";
    dict["isa"] =       "T";
    dict["isan"] =      "T";
    dict["are"] =       "T";
    dict["si"] =        "R";
    dict["for"] =       "U";
    dict["this"] =      "V";
    dict["from"] =      "W";
    dict["postitionM"] ="X";
    dict["tempM"]  =    "Y";
    dict["speedM"] =    "Z";
    dict["timeM"] =     "[";
    dict["sizeM"] =     "\\";
    dict["distanceM"] = "`";
    dict["true"] =      "LN";
    dict["in"] =        "e";
    dict["out"] =       "f";
    dict["me"] =        "n";
    dict["I"] =         "n";
    dict["we"] =        "no";
    dict["do"] =        "j";
    dict["input"] =     "e_put_";
    dict["output"] =    "f_put_";
    dict["load"] =      "_load_";
    dict["source"] =    "_source_";
    dict["-"] =         "£";
    dict["right"] =     "";


    return dict;
}

int main(int nargs,char* args[]) {
    if (nargs == 0) {exit(1);}
    cout << "hi" << endl;
    cout << (string(args[1])) << endl;

    cout << "checkpoint -1" << endl;

    
    map<char,string> alphabet;
    //ik this sucks but idc
    alphabet['A'] =         "\u00C0";
    alphabet['B'] =         "\u00C1";
    alphabet['C'] =         "\u00C2";
    alphabet['D'] =         "\u00C3";
    alphabet['E'] =         "\u00C4";
    alphabet['F'] =         "\u00C5";
    alphabet['G'] =         "\u00C6";
    alphabet['H'] =         "\u00C7";
    alphabet['I'] =         "\u00C8";
    alphabet['J'] =         "\u00C9";
    alphabet['K'] =         "\u00CA";
    alphabet['L'] =         "\u00CB";
    alphabet['M'] =         "\u00CC";
    alphabet['N'] =         "\u00CD";
    alphabet['O'] =         "\u00CE";
    alphabet['P'] =         "\u00CF";
    alphabet['Q'] =         "\u00D0";
    alphabet['R'] =         "\u00D1";
    alphabet['S'] =         "\u00D2";
    alphabet['T'] =         "\u00D3";
    alphabet['U'] =         "\u00D4";
    alphabet['V'] =         "\u00D5";
    alphabet['W'] =         "\u00D6";
    alphabet['X'] =         "\u00D7";
    alphabet['Y'] =         "\u00D8";
    alphabet['Z'] =         "\u00D9";

    fstream file1;
    fstream prgmOut;

    cout << "checkpoint 0" << endl;

    string filename = string(args[1]);
    string outFilename;
    
    if (nargs >= 2)
        outFilename = string(args[2]);
    else
        outFilename = "hi.txt";

    cout << "checkpoint 0.5" << endl;

    file1.open(filename,ios::in);
    prgmOut.open(outFilename,ios::out);

    cout << "checkpoint 1" << endl;
    //get the file contents.

    vector<string> words;
    string word;
    while (file1 >> word)
    {
        words.push_back(word);
    }
    file1.close();

    cout << "checkpoint 2" << endl;

    vector<string> wordsFlipped;

    for (long unsigned int i = 0;i<words.size();i++)
    {
        cout << words[i] << ",";
        wordsFlipped.push_back(words[i]);
    }

    //converting file below

    map<string, wstring> scribblishDict;
    scribblishDict = initDictFromFile("scribblish_with_escape.language");
    //scribblishDict["true"] = "YES GOOD";
    cout << "TEST::::: " << wstringToString( scribblishDict["true"] ) << endl;
    vector<wstring> newWords;
    std::string temp;

    for (long unsigned int i = 0;i<words.size();i++)
    {
        
        temp = words[i];
        cout << "{" << temp << "}" << "\t << CURRENT WORD;\t";
        if (!scribblishDict[temp].empty())
            {
                newWords.push_back(scribblishDict[temp]);
                cout << "[" << wstringToString( scribblishDict[temp] ) << "] ";
                prgmOut << wstringToString( scribblishDict[temp]);// << "";
            }
        else
            {
                transform(temp.begin(), temp.end(), temp.begin(),::toupper);;
                for (long unsigned int i = 0;i<temp.length();i++)
                {
                    cout << "This letter is: " << alphabet[temp[i]] << endl;
                    prgmOut << alphabet[temp[i]];
                }

                
                /*unsigned char* newTemp = new unsigned char[temp.length()];
                int newNum;
                for (long unsigned int i = 0;i<temp.length();i++)
                {
                    //newTemp[i] = (char((int)((char)(temp[i]+127))));
                    cout << "\n\tconversion step: " << temp[i] << "=" << (int)((char)temp[i]) << "+ 117 = " << ((int)((char)temp[i]))+117 << ";;";
                    newNum = ((int)((unsigned char)temp[i]))+117;
                    cout << "the final number, " << newNum << " is " << (unsigned char)newNum;
                    //newTemp[i] = (unsigned char)newNum;
                    newTemp[i] = static_cast<char>(newNum);
                    cout << "--another number is: " << newTemp[i] << "--";
                }

                newWords.push_back(temp);
                for (int i = 0;i<temp.length();i++)
                {
                    cout << "[" << std::hex << newTemp[i] << "], ";
                    stringstream newStr;
                    newStr << "\\u00" << std::hex << newTemp[i];
                    string newnewStr = newStr.str();
                    cout << "[[" << newnewStr << "]], ";
                    cout << "[[" << newTemp[i] << "]]";
                    //prgmOut << "\\u00".append(newTemp[i]);
                }*/
            }
        //cout << scribblishDict[temp] << " ";
        //prgmOut << scribblishDict[temp] << " ";
        cout << endl;
    }

    cout << "eof" << endl;

}
