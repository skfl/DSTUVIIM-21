let elem  = document.getElementById("img1");

let cnt = 1;
let imgArr  = document.getElementsByClassName("img");
let imgArrLen = imgArr.length;
let srcArr = [];
for(i = 0;i<imgArrLen;i++){
    srcArr.push(imgArr[i].src);
}



let timer = setInterval(function(){
    

    elem.src = srcArr[cnt];
    
    cnt +=1;
    
    if(cnt >= srcArr.length){
        cnt = 0;
    }


    

},1500);
