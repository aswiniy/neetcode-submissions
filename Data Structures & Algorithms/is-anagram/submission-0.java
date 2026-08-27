class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())
        {
            return false;
        }
        HashMap<Character,Integer> sMap = new HashMap<>();
        HashMap<Character,Integer> tMap = new HashMap<>();
        loadCharMap(sMap,s);
        loadCharMap(tMap,t);
        
        return sMap.equals(tMap);
    }
    private void loadCharMap(HashMap<Character,Integer> map, String str)
    {
        for(int i=0;i<str.length();i++)
        {
            Character key = str.charAt(i);
            Integer count = map.getOrDefault(key,0);
            map.put(key, count+1);
        }
    }
}
