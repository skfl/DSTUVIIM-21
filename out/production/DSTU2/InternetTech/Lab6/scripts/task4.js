document.write("<table border=\"1\">")
for(i = 1;i<=10;i++){
    document.write("<tr>")
    for(j = 1;j<=10;j++){
        document.write("<td>"+ j+"*"+i+" = "+i*j+"</td>");
    }
    document.write("</tr>")
}
document.write("\n</table>")
document.write("<br>")
document.write("<br>")
