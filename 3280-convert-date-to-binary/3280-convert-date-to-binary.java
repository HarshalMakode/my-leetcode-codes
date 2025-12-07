class Solution {
    public String convertDateToBinary(String date) {
        String[] arr = date.split("-");
        
        int year = Integer.parseInt(arr[0]);
        int month = Integer.parseInt(arr[1]);
        int day = Integer.parseInt(arr[2]);

        arr[0] = Integer.toBinaryString(year);
        arr[1] = Integer.toBinaryString(month);
        arr[2] = Integer.toBinaryString(day);

        date = String.join("-", arr);
        return date;
    }
}