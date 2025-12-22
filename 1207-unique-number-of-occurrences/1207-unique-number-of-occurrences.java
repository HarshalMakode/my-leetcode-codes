class Solution {
    public boolean uniqueOccurrences(int[] arr) {
    Map<Integer,Integer> ap=new HashMap<>();
    for(int i=0;i<arr.length;i++){
        if(ap.containsKey(arr[i])){

        }
        ap.put(arr[i],ap.getOrDefault(arr[i],0)+1);
    }
    HashSet<Integer> sp=new HashSet();
    boolean result=true;
    for(Map.Entry<Integer,Integer> x:ap.entrySet()){
        if(sp.contains(x.getValue())){
        result =false;
        break;
        }
      sp.add(x.getValue());
    }
  return result;
    }
}