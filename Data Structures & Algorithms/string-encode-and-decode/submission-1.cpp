class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string str:strs)
        {
            encoded+=to_string(str.length());
            encoded+='#';
            encoded+=str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.length())
        {
            int j=i;
            while(s[j]!='#')
            {
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            j++;
            string word=s.substr(j,length);
            ans.push_back(word);
            i=j+length;
        }
        return ans;
    }
};
