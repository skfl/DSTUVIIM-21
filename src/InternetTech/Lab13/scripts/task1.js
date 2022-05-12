let form = document.forms.form;
let select = document.getElementById("select");
let radio = form.elements.radio.value;
let img = document.getElementById("img");
let img2 = document.getElementById("img2");
let img3 = document.getElementById("img3");
let clicks = 0;

let timer = setInterval(function(){
    radio = form.elements.radio.value;
    if(radio == "1"){
        img.style.filter = "none";
        img.style.transform = "rotate(10deg)";
        img.style.width = "604px";
        img.style.height = "517px";
    }
    if(radio == "2"){
        img.style.filter = "none";
        img.style.transform = "rotate(0deg)";
        img.style.transform = "scale(-1, 1)";
        img.style.width = "604px";
        img.style.height = "517px";
    }
    if(radio == "3"){
        img.style.filter = "none";
        img.style.transform = "rotate(0deg)";
        img.style.filter = "opacity(30%)";
        img.style.width = "604px";
        img.style.height = "517px";
    }
    if(radio == "4"){
        img.style.transform = "rotate(0deg)";
        img.style.filter = "none";
        img.style.width = "700px";
        img.style.height = "700px";
    }
    
    if(select.value=="1"){
        
        img2.style.width = "604px";
        img2.style.height = "517px";
    }

    if(select.value=="2"){
        img2.style.width = "700px";
        img2.style.height = "700px";
    }

    if(select.value=="3"){
        
        img2.style.width = "640px";
        img2.style.height = "480px";
    }

    if(select.value =="4"){
        img2.style.width = "10px";
        img2.style.height = "15px";
    }

    if(clicks%2!=0){
        img3.src = "../Data/Naruto.png";
        img3.style.filter = "progid:DXImageTransform.Microsoft.Slide(slideStyle='SWAP', bands=0)";
    }else{
        img3.src = "../Data/itachi.jpg";
        img3.style.filter = "none";
    }

},1);

function regClick(){
    clicks+=1;
}