let textArea = document.getElementById("textArea");
let stringArray = textArea.value.split("");
let firstLetter = stringArray[0];
let pos = 0;
let tmp = "";


let timer = setInterval(function(){
    if(pos+1<stringArray.length){ 
        tmp = stringArray[pos+1];
        stringArray[pos+1] = firstLetter;
        stringArray[pos] = tmp;
        textArea.value = stringArray.join('');
        pos++;
    }
    

},200);