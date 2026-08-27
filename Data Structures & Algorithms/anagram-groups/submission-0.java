class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> anagrams = new HashMap<>();
        for(String s: strs){
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sortedS = new String(chars);
            anagrams.putIfAbsent(sortedS,new ArrayList<>());
            anagrams.get(sortedS).add(s);
        }
        return new ArrayList<>(anagrams.values());
    }
}

