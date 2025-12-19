class Solution {
    public String interpret(String command) {
        String str1 = "", s = "";

        for(int i = 0; i < command.length(); i++) {
            s = s + command.charAt(i);
            if(s.equals("G")) {
                str1+='G';
                s = "";
            } else if(s.equals("()")) {
                str1+='o';
                s = "";
            } else if(s.equals("(al)")) {
                str1+="al";
                s = "";
            }
        }

        return str1;
    }
}