document.write("<table border=\"1\">")
for(i = 1;i<=10;i++){
    document.write("<tr>")
    for(j = 1;j<=10;j++){
        if((i == 5) &&(j == 4)){
            document.write("<td colspan=\"2\" align =\"center\">"+ j+"*"+i+" = "+i*j+"</td>"); 
            continue;   
        }
        if((i == 5) &&(j == 5)){
            continue;    
        }
        if((i == 4)&&(j == 8)){
            document.write("<td rowspan=\"2\" align =\"center\">"+ j+"*"+i+" = "+i*j+"</td>");
            continue;
        }

        if((i == 5)&&(j == 8)){
            continue;
        }
        document.write("<td>"+ j+"*"+i+" = "+i*j+"</td>");

    }
    document.write("</tr>")
}
document.write("\n</table>")
document.write("<br>")
document.write("<br>")
