document.querySelector("#submit").onclick = function(){
    let form = document.forms.form;
    
    let name = form.elements.name;
    let mail = form.elements.mail;
    let textArea = form.elements.textarea;
    let radio = form.elements.radio;
    let gender = form.elements.select_gender;
    let check = form.elements.checkbox;

    if(check.checked){
     if(name.value && mail.value && textArea.value && radio.value && gender.value){
        alert("User name \n"+name.value+"\n E-mail addres \n"+mail.value+" \n Gender "+gender.value+"\n Info about "+textArea.value+"\n Favorite language "+radio.value);
     }else{
       alert("You must fill all required fields!");
     }
    }else{
      alert("You must accept rules!");
    }
  }