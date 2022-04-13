let form = document.forms.form;
let eq = form.elements.eqNum; 
let res = form.elements.resultNum;
function append(value){
    let val = String(eq.value);
    value = String(value);
    val = val + value;
    eq.value = val;
}

function appendOp(value){
    if(value == 0 ){
        value = "+";
    }
    if(value == 1){
        value = "-";
    }
    if(value == 2){
        value = "*";
    }
    if(value == 3){
        value = "/";
    }
    if(value == 4){
        eq.value = "";
        res.value = "";
        value = "";
    }
    append(value);
}

function getResult(){
    res.value = "";
    let result = eval(eq.value);
    console.log(typeof result);
    res.value = result;
}

function getSqrt(){
    res.value = "";
    console.log(Math.sqrt(25));
    res.value = Math.sqrt(eq.value);
}

function getSin(){
    res.value = "";
    res.value = Math.sin(eq.value);
}

function getCos(){
    res.value = "";
    res.value = Math.cos(eq.value);
}
