#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <vector>
#include <fstream>

const std::string DEFAULTPATH = "Resources/";


void outputPw(std::string, std::string);
std::string randomPw(bool, bool, bool, bool, int);

long randomNum(long, long);

void outputName(std::string, std::string);
std::string randomName(char, std::vector<std::string>, std::vector<std::string>, int, int);

void d2h(std::string);
void d2b(std::string);
void d2s(std::string);
void h2d(std::string);
void h2b(std::string);
void h2s(std::string);
void b2d(std::string);
void b2h(std::string);
void b2s(std::string);
void s2h(std::string);
void s2b(std::string);

std::string base64Enc(std::string);
std::string base64Dec(std::string);

long string2Num(std::string);
long system2Num(std::string, int);
void helpOutput();


int main (int argc, const char *argv[])
{
    
    if (argc == 1)
    {
        helpOutput();
        return EXIT_FAILURE;
    }
    else if (!strcmp(argv[1], "Pw") || !strcmp(argv[1], "pw") || !strcmp(argv[1], "p"))
    {
        srand((uintmax_t)std::hash<std::thread::id>()(std::this_thread::get_id()));
        if (argc > 3)
        {
            outputPw(argv[2], argv[3]);
        }
        else if (argc > 2)
        {
            outputPw(argv[2], "");
        }
        else
        {
            outputPw("", "20");
        }
    }
    else if (!strcmp(argv[1], "Num") || !strcmp(argv[1], "num"))
    {
        srand((uintmax_t)std::hash<std::thread::id>()(std::this_thread::get_id()));
        if (argc > 3) std::cout << randomNum(string2Num(argv[2]), string2Num(argv[3])) << "\n";
        else if (argc > 2) std::cout << randomNum(1, string2Num(argv[2])) << "\n";
        else std::cout << randomNum(1, 10) << "\n";
    }
    else if (!strcmp(argv[1], "Name") || !strcmp(argv[1], "name") || !strcmp(argv[1], "n"))
    {
        srand((uintmax_t)std::hash<std::thread::id>()(std::this_thread::get_id()));
        if (argc > 3)
        {
            outputName(argv[2], argv[3]);
        }
        else if (argc > 2)
        {
            outputName(argv[2], "");
        }
        else
        {
            outputName("", "");
        }
    }
    else if (!strcmp(argv[1], "d2h") || !strcmp(argv[1], "dh"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                d2h(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "d2b") || !strcmp(argv[1], "db"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                d2b(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "d2c") || !strcmp(argv[1], "d2s") || !strcmp(argv[1], "dc") || !strcmp(argv[1], "ds"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                d2s(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "h2d") || !strcmp(argv[1], "hd"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                h2d(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "h2b") || !strcmp(argv[1], "hb"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                h2b(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "h2c") || !strcmp(argv[1], "h2s") || !strcmp(argv[1], "hc") || !strcmp(argv[1], "hs"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                h2s(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "b2d") || !strcmp(argv[1], "bd"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                b2d(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "b2h") || !strcmp(argv[1], "bh"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                b2h(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "b2c") || !strcmp(argv[1], "b2s") || !strcmp(argv[1], "bc") || !strcmp(argv[1], "bs"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                b2s(argv[i]);
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "s2h") || !strcmp(argv[1], "sh"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                s2h(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "s2b") || !strcmp(argv[1], "sb"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                s2b(argv[i]);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "base64Enc") || !strcmp(argv[1], "base64enc") || !strcmp(argv[1], "b64e"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                std::cout << base64Enc(argv[i]) << " ";
            }
            std::cout << "\n";
        }
    }
    else if (!strcmp(argv[1], "base64Dec") || !strcmp(argv[1], "base64dec") || !strcmp(argv[1], "b64d"))
    {
        if (argc > 2) 
        {
            for (int i = 2; i < argc; i++)
            {
                std::cout << base64Dec(argv[i]) << " ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        helpOutput();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void outputPw(std::string options, std::string maxLengthInput)
{
    bool useLower = false, useUpper = false, useNum = false, useSpec = false;
    int repeatCounter = 1, maxLength = 20;

    if (isdigit(maxLengthInput[0])) maxLength = string2Num(maxLengthInput);
    else if (isdigit(options[0]))
    {
        maxLength = string2Num(options); 
        options = maxLengthInput;
    }
    
    for (int i = 0; i < options.length(); i++)
    {
        switch (options[i])
        {
            case 'l':
            case 'L':
                useLower = true;
                break;
            case 'u':
            case 'U':
                useUpper = true;
                break;
            case 'n':
            case 'N':
                useNum = true;
                break;
            case 's':
            case 'S':
                useSpec = true;
                break;
            case 'r':
            case 'R':
                repeatCounter = string2Num(options.substr(i));
                break;
        }
    }
    
    if (!useLower && !useUpper && !useNum && !useSpec) 
    {
        useLower = true;
        useUpper = true;
        useNum = true;
        useSpec = true;
    }

    for (int i = 0; i < repeatCounter; i++)
        std::cout << randomPw(useLower, useUpper, useNum, useSpec, maxLength) << "\n";
}
std::string randomPw(bool useLower, bool useUpper, bool useNum, bool useSpec, int maxLength)
{
    std::string output;
    std::string alphabet;
    if (useLower) alphabet += "abcdefghijklmnopqrstuvwxyz";
    if (useUpper) alphabet +="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (useNum) alphabet += "0123456789";
    if (useSpec) alphabet += "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    if (alphabet.length() < 1) return "";
    if (maxLength < 1) maxLength = 20;
    for (int i = 0; i < maxLength; i++)
    {
        output += alphabet[randomNum(0, alphabet.length() -1 )];
    }
    return output;
}

long randomNum(long min, long max)
{
    if (min>max) return 0;
    else if (min==max) return min;
    return (rand() % (max-min)) + min; 
}

std::vector<std::string> setupVector(std::string filePath)
{
    std::vector<std::string> finishedVector;
    std::fstream file;
    file.open(filePath, std::ios::in);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            finishedVector.push_back(line);
        }
        file.close();
    }
    return finishedVector;
}
void outputName(std::string options, std::string path)
{
    int repeatCounter = 1, minLength = 3, maxLength = 20;
    char option = 'n';

    std::fstream fileExists;
    fileExists.open(path + "firstList.txt", std::ios::in);
    if (!fileExists.is_open())
    {
        fileExists.close();
        fileExists.open(options + "firstList.txt", std::ios::in);
        if (fileExists.is_open())
        {
            std::string tmp = "";
            if (path != "") tmp = path;
            path = options;
            options = tmp;
        }
        else
            path = DEFAULTPATH;
    }
    fileExists.close();

    for (int i = 0; i < options.length(); i++)
    {
        switch (options[i])
        {
            case 'l':
            case 'L':
                option = 'l';
                break;
            case 'u':
            case 'U':
                option = 'u';
                break;
            case 'n':
            case 'N':
                option = 'n';
                break;
            case 'r':
            case 'R':
                repeatCounter = string2Num(options.substr(i));
                break;
            case 'm':
            case 'M':
                minLength = string2Num(options.substr(i));
                break;
            case 'x':
            case 'X':
                maxLength = string2Num(options.substr(i));
                break;
        }   
    }

    std::vector<std::string> firstList = setupVector(path + "firstList.txt");
    std::vector<std::string> secondList = setupVector(path + "secondList.txt");

    for (int i = 0; i < repeatCounter; i++)
        std::cout << randomName(option, firstList, secondList, minLength, maxLength) << "\n";
}
std::string randomName(char option, std::vector<std::string> firstWord, std::vector<std::string> secondWord, int minLength, int maxLength)
{
    std::string username = "", one = "", two = "";

    while (username.length() < minLength || username.length() > maxLength )
    {
        one = firstWord[randomNum(0, firstWord.size() - 1)];

        two = secondWord[randomNum(0, secondWord.size() - 1)];
    
        username = one + two;
    }

    switch (option)
    {
        case 'n': //first Letters to upper Chars
            one[0] = toupper(one[0]);
            two[0] = toupper(two[0]);
            break;
        case 'l': //lower
            one[0] = tolower(one[0]);
            two[0] = tolower(two[0]);
            break;
        case 'u': //complete upper Chars
            for (int i = 0; i < one.length(); i++)
                one[i] = toupper(one[i]);
            for (int i = 0; i < two.length(); i++)
                two[i] = toupper(two[i]);
            break;
    }

    return one + two;
}

void outputIntHex(int input)
{
    std::ios::fmtflags cFlags(std::cout.flags());
    std::cout << "0x"<< std::hex << input;
    std::cout.flags(cFlags);
}
void outputCharHex(char input)
{
    std::ios::fmtflags cFlags(std::cout.flags());
    int decInput = input;
    std::cout << std::hex << decInput;
    std::cout.flags(cFlags);
}
void outputIntBinary(long input)
{
    std::string out;
    while(input!=0) {out=(input%2==0 ?"0":"1")+out; input/=2;}
    std::cout << out;
}
void d2h(std::string decimal)
{
    outputIntHex(string2Num(decimal));
}
void d2b(std::string decimal)
{
    outputIntBinary(string2Num(decimal));
}
void d2s(std::string decimal)
{
    std::string out = "x";
    out[0] = string2Num(decimal);
    std::cout << out;
}
void h2d(std::string hex)
{
    std::cout << system2Num(hex, 16);
}
void h2b(std::string hex)
{
    if(hex.length() > 2 && hex[0] == '0' && hex[1] == 'x') hex = hex.substr(2);
    std::string out, tmp = "0x";
    for (int i = 0; i < hex.length(); i++)
    {
        if (i < hex.length() -1 )
        {
            tmp[0] = hex[i];
            tmp[1] = hex[++i];
        }
        else 
        {
            tmp[0] = hex[i];
        }
        outputIntBinary(system2Num(tmp, 16));
        std::cout << " ";
    }
    
}
void h2s(std::string hex)
{
    if(hex.length() > 2 && hex[0] == '0' && hex[1] == 'x') hex = hex.substr(2);
    std::string out, tmp = "0x";
    for (int i = 0; i < hex.length(); i++)
    {
        if (i < hex.length() -1 )
        {
            tmp[0] = hex[i];
            tmp[1] = hex[++i];
        }
        else 
        {
            tmp[0] = hex[i];
        }
        out += system2Num(tmp, 16);
    }
    std::cout << out;
}
void b2d(std::string bin)
{
    std::cout << system2Num(bin, 2);
}
void b2h(std::string bin)
{
    outputIntHex(system2Num(bin, 2));
}
void b2s(std::string bin)
{
    std::string out = "x";
    out[0] = system2Num(bin, 2);
    std::cout << out;
}
void s2h(std::string str)
{
    std::cout << "0x";
    for (int i = 0; i < str.length(); i++)
        outputCharHex(str[i]);
}
void s2b(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        outputIntBinary(str[i]);
        std::cout << " ";
    }
}

static const char* B64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const int B64index[256] =
{
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  62, 63, 62, 62, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0,  0,  0,  0,  0,  0,
    0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0,  0,  0,  0,  63,
    0,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
};
const std::string b64encode(const void* data, const size_t &len)
{//source: https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
    std::string result((len + 2) / 3 * 4, '=');
    unsigned char *p = (unsigned  char*) data;
    char *str = &result[0];
    size_t j = 0, pad = len % 3;
    const size_t last = len - pad;

    for (size_t i = 0; i < last; i += 3)
    {
        int n = int(p[i]) << 16 | int(p[i + 1]) << 8 | p[i + 2];
        str[j++] = B64chars[n >> 18];
        str[j++] = B64chars[n >> 12 & 0x3F];
        str[j++] = B64chars[n >> 6 & 0x3F];
        str[j++] = B64chars[n & 0x3F];
    }
    if (pad)  /// Set padding
    {
        int n = --pad ? int(p[last]) << 8 | p[last + 1] : p[last];
        str[j++] = B64chars[pad ? n >> 10 & 0x3F : n >> 2];
        str[j++] = B64chars[pad ? n >> 4 & 0x03F : n << 4 & 0x3F];
        str[j++] = pad ? B64chars[n << 2 & 0x3F] : '=';
    }
    return result;
}
const std::string b64decode(const void* data, const size_t &len)
{//source: https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
    if (len == 0) return "";

    unsigned char *p = (unsigned char*) data;
    size_t j = 0,
        pad1 = len % 4 || p[len - 1] == '=',
        pad2 = pad1 && (len % 4 > 2 || p[len - 2] != '=');
    const size_t last = (len - pad1) / 4 << 2;
    std::string result(last / 4 * 3 + pad1 + pad2, '\0');
    unsigned char *str = (unsigned char*) &result[0];

    for (size_t i = 0; i < last; i += 4)
    {
        int n = B64index[p[i]] << 18 | B64index[p[i + 1]] << 12 | B64index[p[i + 2]] << 6 | B64index[p[i + 3]];
        str[j++] = n >> 16;
        str[j++] = n >> 8 & 0xFF;
        str[j++] = n & 0xFF;
    }
    if (pad1)
    {
        int n = B64index[p[last]] << 18 | B64index[p[last + 1]] << 12;
        str[j++] = n >> 16;
        if (pad2)
        {
            n |= B64index[p[last + 2]] << 6;
            str[j++] = n >> 8 & 0xFF;
        }
    }
    return result;
}
std::string base64Enc(std::string str)
{
    return b64encode(str.c_str(), str.size());
}
std::string base64Dec(std::string str)
{
    return b64decode(str.c_str(), str.size());
}

long string2Num(std::string input)
{
    long ret = 0;
    long multi = 1;
    short isNeg = 0;
    if (input[0] == '-') isNeg = 1;
    int i = isNeg;
    while (!isdigit(input[i])) i++;
    while (isdigit(input[i])) i++;

    for (int j = i; j>=isNeg; j--)
    {
        try
        {
            if (isdigit(input[j]))
            {
                ret += (input[j] - '0')*multi;
                multi *= 10;
            }
            else
                if (ret > 0) break;
        }
        catch (std::exception) {}
    }
    if (isNeg) return (ret * -1);
    else return ret;
}
long system2Num(std::string hex, int system)
{//source: https://www.tutorialspoint.com/cplusplus-program-for-hexadecimal-to-decimal
    long out = 0;
    long multi = 1;
    if(system == 16 && hex.length() > 2 && hex[0] == '0' && hex[1] == 'x') hex = hex.substr(2);
    for (int i = hex.length() - 1; i >= 0; i--)
    {
        if (hex[i]>='0' && hex[i]<='9') 
        {
            out += (hex[i] - 48)*multi;
            multi = multi * system;
        }
        else if (hex[i]>='A' && hex[i]<='F') 
        {
            out += (hex[i] - 55)*multi;
            multi = multi*system;
        }
    }
    return out;
}
 
void helpOutput()
{
    std::cout << "Known options:\n";
    std::cout << "help\tShow this output\n";
    std::cout << "Pw\tShow a random password\n";
    std::cout << "Num\tShow a pseudorandom number\n";
    std::cout << "Name\tShow a random username\n";
    std::cout << "d2h\tConvert decimal to hex\n";
    std::cout << "d2b\tConvert decimal to binary\n";
    std::cout << "d2c\tConvert decimal to character\n";
    std::cout << "h2d\tConvert hex to decimal\n";
    std::cout << "h2b\tConvert hex to binary\n";
    std::cout << "h2s\tConvert hex to string\n";
    std::cout << "b2d\tConvert binary to decimal\n";
    std::cout << "b2h\tConvert binary to hex\n";
    std::cout << "b2c\tConvert binary to character\n";
    std::cout << "s2h\tConvert string to hex\n";
    std::cout << "s2b\tConvert string to binary\n";
    std::cout << "base64Enc\tEncode a base64 string\n";
    std::cout << "base64Dec\tDecode a base64 string\n";
}
