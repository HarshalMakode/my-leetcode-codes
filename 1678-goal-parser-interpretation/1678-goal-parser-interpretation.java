// class Solution {
//     public String interpret(String command) {
//         String str1 = "", s = "";

//         for(int i = 0; i < command.length(); i++) {
//             s = s + command.charAt(i);
//             if(s.equals("G")) {
//                 str1+='G';
//                 s = "";
//             } else if(s.equals("()")) {
//                 str1+='o';
//                 s = "";
//             } else if(s.equals("(al)")) {
//                 str1+="al";
//                 s = "";
//             }
//         }

//         return str1;
//     }
// }

class Solution {
    public String interpret(String command) {
        StringBuilder res = new StringBuilder();
        for(int i =0;i<command.length();i++){
            if(command.charAt(i)=='G'){
                res.append('G');
            }else if(command.charAt(i)=='(' && command.charAt(i+1)==')'){
                res.append('o');
                i++;
            }else if(command.charAt(i)=='(' && command.charAt(i+1)=='a'){
                res.append("al");
                i+=3;
            }
        }
        String r = res.toString();
        return r;
    }
}