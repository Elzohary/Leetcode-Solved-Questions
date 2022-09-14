class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size())
		return false;

	vector<int> counter(26);

	for (int i = 0; i < s.size(); i++)
	{
		counter[s[i] - 'a']++;
	}

	for (int i = 0; i < t.size(); i++)
	{
		counter[t[i] - 'a']--;

		if (counter[t[i] - 'a']< 0)
			return false;
	}
	return true;
    }
};