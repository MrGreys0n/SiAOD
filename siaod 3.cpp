#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


/* ������ �������� 25.
���� �����������, ����� � ������� ��������� ������ ����������� ������� ����������. 
������������ ������ �� ����, � ������� �������� ��������� ����������� � ������ �������.  */

// 1. ������� �� C-string
// 2. ������� �� std::string

// ��������� ������� � ������ ����, ��� �� ���� �� �������� ������ � �������� ������ ������� (��� ������� � �������), ��������� � ������ �������
vector<string> find_same(const char* sentence, const char* to_find)
{
    vector<string> words_wsb;
    const size_t len = strlen(sentence);
    const int len_of_to_find = strlen(to_find);
    bool f = true, word_is_ok = false; // word_is_ok ��������� �� ���������� ���� ���������, ����� ������ ���������� ���������� �������; f ��������� �� ����� �����
    int num_of_pos = 0;
    string this_word = "";
    for (unsigned long i = 0; i < len; i++)
    {
        if (isalpha(sentence[i]) && f)
        {
            if (not word_is_ok)
            {
                if (tolower(sentence[i]) == to_find[num_of_pos])
                {
                    num_of_pos++;
                    this_word += sentence[i];
                    if (num_of_pos == len_of_to_find)
                        word_is_ok = true;
                }
                else
                    f = false;
            }
            else
                this_word += sentence[i];
        }
        else if (not isalpha(sentence[i]))
        {   
            if (word_is_ok)
                words_wsb.push_back(this_word);
            word_is_ok = false;
            f = true;
            num_of_pos = 0;
            this_word = "";
        }

        if (i == len - 1 && word_is_ok)
            words_wsb.push_back(this_word);
    }

    return words_wsb;
}

int main()
{
    /* 1. */

    const char* sentence1 = "My name is Boris, I am a great football player! Team: Boston Boilers";
    const char* to_find = "bo";
    const vector<string> words_wsb = find_same(sentence1, to_find);
    for (unsigned long i = 0; i < words_wsb.size(); i++)
    {
        cout << words_wsb[i];
        if (i != words_wsb.size() - 1)
            cout << ", ";
    }
}