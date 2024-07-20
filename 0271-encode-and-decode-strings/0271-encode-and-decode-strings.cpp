class Codec {
public:
    /*
      The idea is to serialize the string with it's length and a delemiter('/')
      While decoding it we can get the length until the delim and take substring of the string from that index till the length.
    */
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (string str : strs) {
            int n = str.size();
            res += to_string(n) + '/' + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.size();
        string temp = "";
        vector<string> res;
        for (int i = 0; i < n;) {
            while (s[i] != '/') {
                temp += s[i];
                i++;
            }
            int len = stoi(temp);
            i++;
            string curr = s.substr(i, len);
            res.push_back(curr);
            i += len;
            temp = "";
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));