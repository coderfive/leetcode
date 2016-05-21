class Solution {
public:
    string reverseVowels(string s) {
        int vowel[128] {};
        vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = 1;
        vowel['A'] = vowel['E'] = vowel['I'] = vowel['O'] = vowel['U'] = 1;
        int first = 0, last = s.size()-1;
        while (first < last) {
            while (first < last && !vowel[s[first]]) first++;
            while (first < last && !vowel[s[last]]) last--;
            if (first < last)
                std::swap(s[first++], s[last--]);
        }
        return s;
    }
};
