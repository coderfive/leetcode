class Solution {
public:
    string getHint(string secret, string guess) {
        int freqs[10] {};
        int freqg[10] {};
        int bulls = 0, cows = 0; 
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                freqs[secret[i]-'0']++;
                freqg[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cows += std::min (freqs[i], freqg[i]);
        }
        string res;
        stringstream ss;
        ss << bulls << 'A' << cows << 'B';
        ss >> res;


        return res;
    }
};
